#include <pugixml.hpp>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <thread>
#include <cstring>
#include <cstdlib>
#include <stack>

namespace fs = std::filesystem;

class PortInfo {
private:
    std::string port_id;
    std::string service_info;

public:
    std::string getPortId() const {
        return port_id;
    }

    void setPortId(const std::string& id) {
        port_id = id;
    }

    std::string getServiceInfo() const {
        return service_info;
    }

    void setServiceInfo(const std::string& info) {
        service_info = info;
    }
};

class XmlParser {
public:
    virtual void parse(const std::string& xmlfile) = 0;
    virtual ~XmlParser() {};
};

class FileService {
public:
    static void save_service_info_to_file(const fs::path& ip_directory, const PortInfo& port_info) {
        std::ofstream service_file(ip_directory / (port_info.getPortId() + ".txt"));
        if (service_file.is_open()) {
            service_file << port_info.getServiceInfo();
            service_file.close();
        } else {
            std::cerr << "Unable to open file for writing service info for port " << port_info.getPortId() << std::endl;
        }
    }
};

class NmapXmlParser : public XmlParser {
private:
    std::string output_directory;
    std::stack<PortInfo> port_info_stack; // Стек для хранения информации о портах

public:
    NmapXmlParser(const std::string& dir) : output_directory(dir) {}

    void parse(const std::string& xmlfile) override {
        pugi::xml_document doc;
        if (!doc.load_file(xmlfile.c_str())) {
            std::cerr << "Failed to open the file!" << std::endl;
            return;
        }

        if (!output_directory.empty() && !fs::exists(output_directory)) {
            fs::create_directories(output_directory);
        }

        pugi::xml_node root = doc.child("nmaprun");

        for (pugi::xml_node host : root.children("host")) {
            std::string ip = host.child("address").attribute("addr").as_string();

            fs::path ip_directory = fs::absolute(fs::path(output_directory) / ip);
            fs::create_directories(ip_directory);

            pugi::xml_node ports = host.child("ports");

            for (pugi::xml_node port : ports.children("port")) {
                PortInfo port_info;
                port_info.setPortId(port.attribute("portid").as_string());

                pugi::xml_node service = port.child("service");

                if (service) {
                    std::string service_info;
                    service_info += service.attribute("name").as_string();
                    service_info += !service.attribute("product").empty() ? " " + std::string(service.attribute("product").as_string()) : "";
                    service_info += !service.attribute("version").empty() ? " " + std::string(service.attribute("version").as_string()) : "";
                    service_info += !service.attribute("extrainfo").empty() ? " " + std::string(service.attribute("extrainfo").as_string()) : "";

                    port_info.setServiceInfo(service_info);
                }

                port_info_stack.push(port_info); // Добавляем информацию о порте в стек
            }

            while (!port_info_stack.empty()) {
                const PortInfo& top_port_info = port_info_stack.top();
                FileService::save_service_info_to_file(ip_directory, top_port_info);
                port_info_stack.pop(); // Убираем верхний элемент стека
            }
        }
    }
};

class CommandLineParser {
private:
    std::vector<std::string> xmlfiles;
    std::string output_directory;

public:
    CommandLineParser() = default;

    bool parse(int argc, char** argv) {
        int opt;
        int option_index = 0;
        static struct option long_options[] = {
            {"file", required_argument, 0, 'f'},
            {"files", required_argument, 0, 's'},
            {"directory", required_argument, 0, 'd'},
            {"help", no_argument, 0, 'h'},
            {0, 0, 0, 0}
        };

        while ((opt = getopt_long(argc, argv, "f:s:d:h", long_options, &option_index)) != -1) {
            switch (opt) {
                case 'f':
                    xmlfiles.push_back(optarg);
                    break;
                case 's': {
                    char* file = strtok(optarg, " ");
                    while (file != NULL) {
                        xmlfiles.push_back(file);
                        file = strtok(NULL, " ");
                    }
                    break;
                }
                case 'd':
                    output_directory = optarg;
                    break;
                case 'h':
                    print_help(argv[0]);
                    return false;
                default:
                    print_help(argv[0]);
                    return false;
            }
        }

        if (xmlfiles.empty() || output_directory.empty()) {
            print_help(argv[0]);
            return false;
        }
        return true;
    }

    const std::vector<std::string>& getXmlFiles() const { return xmlfiles; }
    const std::string& getOutputDirectory() const { return output_directory; }

    void print_help(const char* prog_name) {
        std::cout << "Usage: " << prog_name << " [OPTIONS]\n"
                  << "Options:\n"
                  << " -f, --file Set the path to a single XML file for processing.\n"
                  << " -s, --files Set the path to multiple XML files for processing separated by spaces.\n"
                  << " -d, --directory Set the path to the output directory where results will be stored.\n"
                  << " -h, --help Display this help message and exit.\n"
                  << std::endl;
    }
};

void parse_xml_files_in_parallel(const std::vector<std::string>& xmlfiles, const std::vector<XmlParser*>& parsers) {
    std::vector<std::thread> threads;

    for (const auto& file : xmlfiles) {
        threads.emplace_back([file, &parsers]() { parsers.back()->parse(file); });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

int main(int argc, char** argv) {
    CommandLineParser cmdParser;
    if (!cmdParser.parse(argc, argv)) {
        return 1;
    }

    std::vector<XmlParser*> parsers;
    for (const std::string& file : cmdParser.getXmlFiles()) {
        parsers.push_back(new NmapXmlParser(cmdParser.getOutputDirectory()));
    }

    parse_xml_files_in_parallel(cmdParser.getXmlFiles(), parsers);

    for (auto parser : parsers) {
        delete parser;
    }

    return 0;
}


#include <pugixml.hpp>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <thread>
#include <cstring>
#include <map>
#include <cstdlib>

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

// Прототип функции для её использования до её определения ниже.
void save_service_info_to_file(const fs::path& ip_directory, const PortInfo& port_info);

void parse_nmap_xml(const std::string& xmlfile, const std::string& output_directory) {
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
                save_service_info_to_file(ip_directory, port_info);
            }
        }
    }
}

void parse_xml_files_in_parallel(const std::vector<std::string>& xmlfiles, const std::string& output_directory) {
    std::vector<std::thread> threads;

    for (const std::string& file : xmlfiles) {
        threads.emplace_back(parse_nmap_xml, file, output_directory);
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void save_service_info_to_file(const fs::path& ip_directory, const PortInfo& port_info) {
    std::ofstream service_file(ip_directory / (port_info.getPortId() + ".txt"));
    if (service_file.is_open()) {
        service_file << port_info.getServiceInfo();
        service_file.close();
    } else {
        std::cerr << "Unable to open file for writing service info for port " << port_info.getPortId() << std::endl;
    }
}

// Функция для вывода всех опций
void print_help(const char* prog_name) {
    std::cout << "Usage: " << prog_name << " [OPTIONS]\n"
              << "Options:\n"
              << "  -f, --file       Set the path to a single XML file for processing.\n"
              << "  -s, --files      Set the path to multiple XML files for processing separated by spaces.\n"
              << "  -d, --directory  Set the path to the output directory where results will be stored.\n"
              << "  -h, --help       Display this help message and exit.\n"
              << std::endl;
}

int main(int argc, char** argv) {
    std::vector<std::string> xmlfiles;
    std::string output_directory;
    int opt;
    int option_index = 0;
    opterr = 0;

    static struct option long_options[] = {
        {"file", required_argument, 0, 'f'}, // Опция для указания файла
        {"files", required_argument, 0, 's'}, // Опция для указания файлов (через пробел)
        // TODO : протестить и улучшить опцию s
        // TODO : добавить опцию --help-all для вывода всех опций + команды запуска с каждым флагом
        // TODO : подумать и добавить полезных фишек и увеличить функционал + написать make файл
        {"directory", required_argument, 0, 'd'}, // Опция для указания директории в которую сохраняется файл
        {"help", no_argument, 0, 'h'}, // Опция help
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "f:s:d:h", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'f':
                xmlfiles.push_back(optarg);
                break;
            case 's':
                {
                    char* file = strtok(optarg, " ");
                    while (file != NULL) {
                        xmlfiles.push_back(file);
                        file = strtok(NULL, " ");
                    }
                }
                break;
            case 'd':
                output_directory = optarg;
                break;
            case 'h':
                print_help(argv[0]);
                return 0;
            default:
                std::cerr << "Usage: " << argv[0] << " -h or " << argv[0] << " --help" << std::endl;
                return 1;
        }
    }

    // Проверяем, были ли предоставлены пути к файлу и директории для вывода
    if (xmlfiles.empty() || output_directory.empty()) {
        std::cerr << "Usage: " << argv[0] << " -h or " << argv[0] << " --help" << std::endl;
        return 1;
    }

    // Запуск параллельного парсинга
    parse_xml_files_in_parallel(xmlfiles, output_directory);

    return 0;
}

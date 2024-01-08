#include <pugixml.hpp>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <thread>
#include <cstring>

namespace fs = std::filesystem;

struct PortInfo {
    std::string port_id;
    std::string service_info;
};

void parse_nmap_xml(const std::string& xmlfile, const std::string& output_directory) {
    pugi::xml_document doc;
    if (!doc.load_file(xmlfile.c_str())) {
        std::cerr << "Failed to open the file!" << std::endl;
        return;
    }

    // Создание директории, если она не существует
    if (!output_directory.empty() && !fs::exists(output_directory)) {
        fs::create_directories(output_directory);
    }

    pugi::xml_node root = doc.child("nmaprun");

    for (pugi::xml_node host : root.children("host")) {
        // Парсинг IP адрес
        std::string ip = host.child("address").attribute("addr").as_string();

        // Создание директории с названием = IP в указанной выходной директории
        fs::path ip_directory = fs::absolute(fs::path(output_directory) / ip);
        fs::create_directories(ip_directory);

        pugi::xml_node ports = host.child("ports");
        for (pugi::xml_node port : ports.children("port")) {
            // Парсинг ID порта
            std::string port_id = port.attribute("portid").as_string();

            pugi::xml_node service = port.child("service");
            std::string service_info;
            if (service) {
                std::string service_name = service.attribute("name").as_string();
                std::string product = service.attribute("product").as_string();
                std::string version = service.attribute("version").as_string();
                std::string extrainfo = service.attribute("extrainfo").as_string();
                service_info = service_name + " " + product + " " + version + " " + extrainfo;
            }

            // Сохранение информации о сервисе в файл с именем порта
            std::ofstream service_file(ip_directory / (port_id + ".txt"));
            if (service_file.is_open()) {
                service_file << service_info;
                service_file.close();
            } else {
                // В случае ошибки открытия файла вывод сообщения об ошибке
                std::cerr << "Unable to open file for writing service info for port " << port_id << std::endl;
            }
        }
    }
}

// Функция для параллельного запуска парсинга
void parse_xml_files_in_parallel(const std::vector<std::string>& xmlfiles, const std::string& output_directory) {
    std::vector<std::thread> threads;

    for (const std::string& file : xmlfiles) {
        threads.emplace_back(parse_nmap_xml, file, output_directory);
    }

    // Ожидание завершения всех потоков
    for (auto& thread : threads) {
        thread.join();
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

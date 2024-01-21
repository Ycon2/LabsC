#include "NmapXmlParser.h"
#include "FileService.h"
#include <pugixml.hpp>
#include <filesystem>
#include "pugixml.hpp"
#include <filesystem>
#include <iostream>
#include <ostream>
#include <fstream>
#include <stack>

namespace fs = std::filesystem;

NmapXmlParser::NmapXmlParser(const std::string& dir) : output_directory(dir) {}

void NmapXmlParser::parse(const std::string& xmlfile) {
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


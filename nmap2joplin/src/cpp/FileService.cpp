#include "FileService.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <ostream>

namespace fs = std::filesystem;

void FileService::save_service_info_to_file(const fs::path& ip_directory, const PortInfo& port_info) {
    std::ofstream service_file(ip_directory / (port_info.getPortId() + ".txt"));
    if (service_file.is_open()) {
        service_file << port_info.getServiceInfo();
        service_file.close();
    } else {
        std::cerr << "Unable to open file for writing service info for port " << port_info.getPortId() << std::endl;
    }
}

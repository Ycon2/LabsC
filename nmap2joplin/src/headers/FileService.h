#pragma once

#include <filesystem>
#include "PortInfo.h"

namespace fs = std::filesystem;

class FileService {
public:
    static void save_service_info_to_file(const fs::path& ip_directory, const PortInfo& port_info);
};

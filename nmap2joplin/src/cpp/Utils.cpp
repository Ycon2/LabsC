#include "Utils.h"
#include <thread>

void parse_xml_files_in_parallel(const std::vector<std::string>& xmlfiles, const std::vector<XmlParser*>& parsers) {
    std::vector<std::thread> threads;

    for (const auto& file : xmlfiles) {
        threads.emplace_back([file, &parsers]() { parsers.back()->parse(file); });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

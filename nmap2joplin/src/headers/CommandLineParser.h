#pragma once
#include <vector>
#include <string>

class CommandLineParser {
private:
    std::vector<std::string> xmlfiles;
    std::string output_directory;

public:
    CommandLineParser();

    bool parse(int argc, char** argv);

    const std::vector<std::string>& getXmlFiles() const;
    const std::string& getOutputDirectory() const;

    void print_help(const char* prog_name);
};

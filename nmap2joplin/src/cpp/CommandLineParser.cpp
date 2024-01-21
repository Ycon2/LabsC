#include "CommandLineParser.h"
#include <getopt.h>
#include <iostream>
#include <cstring>

CommandLineParser::CommandLineParser() = default;

bool CommandLineParser::parse(int argc, char** argv) {
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

const std::vector<std::string>& CommandLineParser::getXmlFiles() const {
    return xmlfiles;
}

const std::string& CommandLineParser::getOutputDirectory() const {
    return output_directory;
}

void CommandLineParser::print_help(const char* prog_name) {
    std::cout << "Usage: " << prog_name << " [OPTIONS]\n"
              << "Options:\n"
              << " -f, --file Set the path to a single XML file for processing.\n"
              << " -s, --files Set the path to multiple XML files for processing separated by spaces.\n"
              << " -d, --directory Set the path to the output directory where results will be stored.\n"
              << " -h, --help Display this help message and exit.\n"
              << std::endl;
}


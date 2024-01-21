#include "../headers/CommandLineParser.h"
#include "../headers/NmapXmlParser.h"
#include "../headers/Utils.h"

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

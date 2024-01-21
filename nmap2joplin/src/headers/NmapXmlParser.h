#pragma once

#include "XmlParser.h"
#include <stack>
#include "PortInfo.h"
#include "FileService.h"

class NmapXmlParser : public XmlParser {
private:
    std::string output_directory;
    std::stack<PortInfo> port_info_stack;

public:
    NmapXmlParser(const std::string& dir);

    void parse(const std::string& xmlfile) override;
};

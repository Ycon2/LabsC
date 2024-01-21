#pragma once

#include <string>

class XmlParser {
public:
    virtual void parse(const std::string& xmlfile) = 0;
    virtual ~XmlParser() {};
};

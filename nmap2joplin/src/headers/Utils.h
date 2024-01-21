#pragma once

#include <vector>
#include <string>
#include "XmlParser.h"

void parse_xml_files_in_parallel(const std::vector<std::string>& xmlfiles, const std::vector<XmlParser*>& parsers);

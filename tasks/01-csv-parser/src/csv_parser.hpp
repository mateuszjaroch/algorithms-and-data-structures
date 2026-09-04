#pragma once

#include<string>
#include<vector>

namespace csv {

std::vector<std::string> parse_line(const std::string& line, char delimiter = ',');

}
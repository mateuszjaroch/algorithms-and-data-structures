#pragma once

#include<string>
#include<vector>

namespace csv {

std::vector<std::string> parse_line(const std::string& line, char delimiter = ',');

struct ColumnStats{
    double sum = 0.0;
    double mean= 0.0;
    int count = 0;      
};

ColumnStats compute_stats(const std::vector<std::string>& values);

}
#include"csv_parser.hpp"

#include <charconv>
#include<sstream>

namespace csv {

std::vector<std::string> parse_line(const std::string& line, char delimiter) {
    std:: vector<std::string> fields;
    std:: string field;
    std::istringstream stream(line);

    while(std::getline(stream, field, delimiter)) {
        fields.push_back(field);
    }

    return fields;
}

ColumnStats compute_stats(const std::vector<std::string>& values) {
    ColumnStats stats;

    for(const auto& value : values){
        if (value.empty()){
            continue;
        }

        double parsed = 0.0;
        auto result = std::from_chars(value.data(), value.data() + value.size(), parsed);
        if(result.ec != std::errc()){
            continue;
        }

        stats.sum +=parsed;
        stats.count +=1;
    }

    if(stats.count >0){
        stats.mean = stats.sum / static_cast<double>(stats.count);
    }

    return stats;
}

}
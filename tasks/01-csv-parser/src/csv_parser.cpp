#include"csv_parser.hpp"

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

}
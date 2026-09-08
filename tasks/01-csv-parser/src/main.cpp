#include <fstream>
#include <iostream>
#include <vector>

#include "csv_parser.hpp"

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cerr << "Usage: csv_parser <file.csv>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if(!file) {
        std:: cerr << "Cannot open file: " << argv[1] << '\n';
    }

    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> columns;

    std::string line;
    bool first_line = true;

    while (std::getline(file,line)) {
        auto fields = csv::parse_line(line);

        if (first_line) {
            headers = fields;
            columns.resize(headers.size());
            first_line = false;
            continue;
        }
        
        for (size_t i = 0; i < fields.size() && i < columns.size(); ++i) {
            columns[i].push_back(fields[i]);
        }
    }

    for (size_t i = 0; i < headers.size(); ++i) {
        auto stats = csv::compute_stats(columns[i]);

        std::cout << headers[i] << ": ";
        if (stats.count > 0) {
            std::cout << "sum=" << stats.sum << ", mean=" << stats.mean 
                        <<",count=" << stats.count << '\n';
        } else {
            std::cout << "(brak wartości liczbowych)\n";
        }
    }
    
    return 0;
}
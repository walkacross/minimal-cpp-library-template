#include <vector>
#include "libminimal/intermediate/data_io/data_reader.h"

namespace libminimal { namespace intermediate { namespace data{

std::map<std::string, std::tuple<double, double, double, double, double, double>> read_trading_data(std::string file_path){

    std::map<std::string, std::tuple<double, double, double, double, double, double>> innerMap;

    std::string line, lineItem;

    std::ifstream filestream(file_path);
    if(!filestream.is_open()) {
        throw std::runtime_error("Could not open file: " + file_path);}
    else {
        std::getline(filestream, line);

        // read the raw data line by line
        while (std::getline(filestream, line)) {
            std::stringstream ss(line);
            std::vector<std::string> lineVector;

            while (std::getline(ss, lineItem, ',')) {
                lineVector.emplace_back(lineItem);
            }

            innerMap.insert({lineVector[0], std::make_tuple(std::stod(lineVector[1]), std::stod(lineVector[2]), std::stod(lineVector[3]), std::stod(lineVector[4]), std::stod(lineVector[5]), std::stod(lineVector[6])) });
        }
    }
    return innerMap;
}

} //namespace data
} //namespace intermedia
} //namespace libminimal

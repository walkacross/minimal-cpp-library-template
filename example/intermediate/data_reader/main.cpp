#include <iostream>
#include <tuple>
#include <string>
#include <map>
#include <libminimal/libminimal.h>

enum tuple_columns {
    OPEN,
    HIGH,
    LOW,
    CLOSE,
    ADJ_CLOSE,
    VOLUME
};


int main(){

        std::string file_path = "./data/AAPL.csv";

        std::map<std::string, std::tuple<double, double, double, double, double, double>> data_map;

        data_map = libminimal::intermediate::data::read_trading_data(file_path);

        for (auto i = data_map.begin(); i != data_map.end(); i++) {
            std::cout << i->first << '\n';
        }

        std::tuple<double, double, double, double, double, double> a_tuple;
        a_tuple = data_map.at("2020-06-04");

        double open_price = std::get<tuple_columns::OPEN>(a_tuple);
        std::cout << "the first open price is: " << open_price << std::endl;

        double volume = std::get<tuple_columns::VOLUME>(a_tuple);
        std::cout << "the first volume is: " << volume << std::endl;

        return 0;

}

#include <iostream>
#include <tuple>
#include <string>
#include <map>
#include <libminimal/libminimal.h>
#include <libminimal/domain_knowledge/finance/risk.h>

enum tuple_columns {
    OPEN,
    HIGH,
    LOW,
    CLOSE,
    ADJ_CLOSE,
    VOLUME
};

std::vector<double> price_to_returns(std::vector<double> v){
    std::vector<double> returns;
    int size = v.size();
    for(int i=1; i < size; i++)
    {
        returns.push_back(v.at(i)/v.at(i-1) - 1);
    }
    return returns;
}



int main(){

    std::string file_path = "./data/AAPL.csv";

    std::map<std::string, std::tuple<double, double, double, double, double, double>> data_map;

    data_map = libminimal::intermediate::data::read_trading_data(file_path);

    std::vector<double> close_price;
    for (auto i = data_map.begin(); i != data_map.end(); i++) {
        std::tuple<double, double, double, double, double, double> a_tuple;
        a_tuple = data_map.at(i->first);
        double price = std::get<tuple_columns::CLOSE>(a_tuple);
        close_price.push_back(price);
    }

    std::vector<double> returns = price_to_returns(close_price);
    std::vector<double> benchmark_returns(returns.size(), 0.);  // a vector with 0.0

    libminimal::finance::Risk risk(returns, benchmark_returns, 0., "daily");
    double return_rate = risk.return_rate();
    std::cout << "total returns: " << return_rate << std::endl;

    std::map<std::string, double> perforamce_map = risk.all_performance();
    for (auto i = perforamce_map.begin(); i != perforamce_map.end(); i++) {
        std::cout << i->first << ":" << i->second << std::endl;
    }

    return 0;

}

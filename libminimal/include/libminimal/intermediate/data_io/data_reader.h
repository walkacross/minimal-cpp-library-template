#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>
#include <map>


namespace libminimal { namespace intermediate { namespace data {

std::map<std::string, std::tuple<double, double, double, double, double, double>> read_trading_data(std::string file_path);

} // namespace data
} // namespace intermediate
} // namespace libminimal
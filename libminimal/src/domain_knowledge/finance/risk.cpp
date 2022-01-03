#include "libminimal/domain_knowledge/finance/risk.h"
#include <numeric> // std::accumulate
#include <cmath>  // std::pow operation
#include <algorithm> //std::transform
#include <functional> //std::minus


namespace libminimal { namespace finance {

    Risk::Risk(std::vector<double> returns, std::vector<double> benchmark_returns, double risk_free_rate, std::string frequency){
        _returns = returns;
        if (benchmark_returns.empty()){
            std::vector<double> a_zero_vector(returns.size(), 0.0);
            _benchmark_returns = a_zero_vector;
        }
        else{
            _benchmark_returns = benchmark_returns;
        }

        _period_count = returns.size();
        _risk_free_rate = risk_free_rate;
        _annual_factor = ANNUALIZATION_FACTORS[frequency];

        _total_return = std::accumulate(returns.begin(), returns.end(), 1., [](double net_value, double x){return net_value*(1.+x);}) - 1.;
        _benchmark_total_return = std::accumulate(benchmark_returns.begin(), benchmark_returns.end(), 1., [](double net_value, double x){return net_value*(1.+x);}) - 1.;

        // generate _excess_return vector
        std::vector<double> output(returns.size(), 0.0);
        std::transform(returns.begin(), returns.end(), _benchmark_returns.begin(), output.begin(), std::minus<double>());
        _excess_return = output;
        _excess_return_rate = std::accumulate(_excess_return.begin(), _excess_return.end(), 1., [](double net_value, double x){return net_value*(1.+x);}) - 1.;

        // win_rate
        int count = std::count_if(_excess_return.begin(), _excess_return.end(), [](double x){return x>=0;});
        _win_rate = static_cast<double>(count)/_period_count;
    }

    double Risk::return_rate() const {
        return _total_return;
    }

    double Risk::benchmark_return() const {
        return _benchmark_total_return;
    }

    double Risk::annual_return() const{
        double annual_return_value = std::pow(1 + _total_return, static_cast<double>(_annual_factor)/_period_count) - 1.;
        return annual_return_value;
    }

    double Risk::benchmark_annual_return() const{
            double benchmark_annual_return_value = std::pow(1 + _benchmark_total_return, static_cast<double>(_annual_factor)/_period_count) - 1.;
            return benchmark_annual_return_value;
    }


    double Risk::excess_return(){
        return  _excess_return_rate;
    }

    double Risk::excess_annual_return(){
        double excess_annual_return_value = std::pow(1 + _excess_return_rate, static_cast<double>(_annual_factor)/_period_count) - 1.;
        return excess_annual_return_value;
    }

    double Risk::volatility(){
        double variance = calculate_variance(_returns);
        _volatility = std::sqrt(variance);
        _annual_volatility = _volatility * std::sqrt(_annual_factor);
        return _volatility;
    }

    double Risk::benchmark_volatility(){
        double benchmark_variance = calculate_variance(_benchmark_returns);
        _benchmark_volatility = std::sqrt(benchmark_variance);
        _benchmark_annual_volatility = _benchmark_volatility * std::sqrt(_annual_factor);
        return _benchmark_volatility;
    }

    double Risk::excess_volatility(){
        double _excess_variance = calculate_variance(_excess_return);
        _excess_volatility = std::sqrt(_excess_variance);
        _excess_annual_volatility = _excess_volatility * std::sqrt(_annual_factor);
        return _excess_volatility;
    }

    double Risk::max_drawdown() {
        std::vector<double> price;
        price = returns_to_price(_returns);
        _maxdrawdown = calculate_max_drawdown(price);
        return _maxdrawdown;
    }

    double Risk::excess_max_drawdown(){
        std::vector<double> excess_price;
        excess_price = returns_to_price(_excess_return);
        _excess_max_drawdown = calculate_max_drawdown(excess_price);
        return _excess_max_drawdown;
    }


    double Risk::calculate_max_drawdown(std::vector<double> price) {
        const int size = price.size();

        if(size<=1)
            return 0;

        double maxdrawdown = 0.0, max_so_far = price[0];

        for(register int i = 1; i < size; ++i){
            if(price[i] > max_so_far){
                max_so_far = price[i];
            }
            else{
                if(max_so_far > 0){
                    const double dd = (price[i] - max_so_far) / max_so_far;
                    if(dd < maxdrawdown)
                        maxdrawdown =dd;
                }

            }
        }
        return maxdrawdown;
    }

    std::map<std::string, double> Risk::all_performance(){
        std::map<std::string, double> performance_map;

        performance_map["return_rate"] = return_rate();
        performance_map["benchmark_return_rate"] = benchmark_return();
        performance_map["annual_return"] = annual_return();
        performance_map["benchmark_annual_return"] = benchmark_annual_return();
        performance_map["volatility"] = volatility();
        performance_map["annual_volatility"] = _annual_volatility;
        performance_map["benchmark_volatility"] = benchmark_volatility();
        performance_map["benchmark_annual_volatility"] = _benchmark_annual_volatility;
        performance_map["max_drawdown"] = max_drawdown();

        performance_map["excess_return"] = excess_return();
        performance_map["excess_annual_return"] = excess_annual_return();
        double excess_volatility_value = excess_volatility();
        performance_map["excess_annual_volatility"] = _excess_annual_volatility;
        performance_map["excess_max_drawdown"] = excess_max_drawdown();
        performance_map["win_rate"] = _win_rate;


        return performance_map;
    }

    double Risk::calculate_mean(std::vector<double> v){
        if (v.empty()){
            return std::nan("1");
        }

        double mean = std::accumulate(v.begin(), v.end(), 0., [](double x , double y){return x+y;}) / v.size();
        return mean;
    }

    double Risk::calculate_variance(std::vector<double> v){
        if (v.empty()){
            return std::nan("1");
        }

        double mean = calculate_mean(v);

        auto add_square = [&mean](double sum, double i){
            auto d = i - mean;
            return sum + d*d;
        };
        double total_deviation = std::accumulate(v.begin(), v.end(), 0.0, add_square);
        double variance =  total_deviation / (v.size() - 1);
        return variance;
    }

    std::vector<double> Risk::returns_to_price(std::vector<double> v){
        std::vector<double> price;
        price.push_back(1.0);
        for(int i=1; i<=v.size(); i++){
            double current_price = price[i-1] * (1+v[i-1]);
            price.push_back(current_price);
        }
        return price;
    }

} //namespace finance

} //namespace libminimal


#pragma once

#include <string>
#include <vector>
#include <map>

namespace libminimal {
    namespace finance {

        class Risk {
        protected:
            int APPROX_BDAYS_PER_MONTH = 21;
            int APPROX_BDAYS_PER_YEAR = 252;

            int MONTHS_PER_YEAR = 12;
            int WEEKS_PER_YEAR = 52;

            std::string DAILY = "daily";
            std::string WEEKLY = "weekly";
            std::string MONTHLY = "monthly";
            std::string YEARLY = "yearly";

            std::map<std::string, int> ANNUALIZATION_FACTORS = {{DAILY,APPROX_BDAYS_PER_MONTH},
                                                                {WEEKLY,WEEKS_PER_YEAR},
                                                                {MONTHLY,MONTHS_PER_YEAR}};

            std::vector<double> _returns;
            std::vector<double> _benchmark_returns;
            int _period_count;
            double _risk_free_rate;
            int _annual_factor;
            double _daily_risk_free_rate;

            double _total_return;
            double _benchmark_total_return;
            double _volatility;
            double _annual_volatility;
            double _benchmark_volatility;
            double _benchmark_annual_volatility;
            double _maxdrawdown;

            std::vector<double> _excess_return;
            double _excess_return_rate;
            double _excess_annual_return;
            double _excess_volatility;
            double _excess_annual_volatility;
            double _excess_max_drawdown;
            double _win_rate;


        public:
            Risk(std::vector<double> returns, std::vector<double> benchmark_returns, double risk_free_rate = 0.0,
                 std::string frequency = "daily");

            double return_rate() const;
            double benchmark_return() const;
            double annual_return() const;
            double benchmark_annual_return() const;
            double volatility();
            double benchmark_volatility();
            double max_drawdown();

            std::map<std::string, double> all_performance();
            //double sharpe() const;

            double excess_return();
            double excess_annual_return();
            double excess_volatility();
            double excess_max_drawdown();
            //double win_rate() const;

            double calculate_mean(std::vector<double> v);
            double calculate_variance(std::vector<double> v);
            double calculate_max_drawdown(std::vector<double> price);
            std::vector<double> returns_to_price(std::vector<double> v);

        };

    } // namespace finance
} //namespace libminimal
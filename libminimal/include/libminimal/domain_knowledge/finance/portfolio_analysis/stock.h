#pragma once

#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>

class Stock{
private:
    std::vector<std::string> date;
    std::vector<std::string> open;
    std::vector<std::string> high;
    std::vector<std::string> low;
    std::vector<std::string> close;
    std::vector<std::string> volume;
    std::vector<std::string> symbol;
public:
    Stock(std::vector<std::string>,std::vector<std::string>,std::vector<std::string>,std::vector<std::string>,std::vector<std::string>,std::vector<std::string>,std::vector<std::string>);
    double getStockPrice();
    bool isValidDate(std::string);
    bool isValidSymbol(std::string);
    std::string getDate(int);
    double getOpen(int);
    double getHigh(int);
    double getLow(int);
    double getClose(int);
    double getVolume(int);
    void printStockInformation(int);
    double getPercentageChange(int, int);
    double getPercentageChange(int);
    std::string getSymbol();
    void readStock();
};
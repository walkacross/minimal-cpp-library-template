#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "libminimal/domain_knowledge/finance/portfolio_analysis/stock.h"
#include "libminimal/domain_knowledge/finance/portfolio_analysis/CheckSymbol.h"

class Portfolio{
private:
    std::vector <Stock*> vec;
    int counter = 0;
public:
//Portfolio();
//~Portfolio();
    bool isEmpty(){
        if(counter == 0){
            return true;
        }
        return false;
    }

    void AddStock(){
        std::string date, open, high, low, close, volume, symbol;
        std::vector<std::string> vdate;
        std::vector<std::string> vopen;
        std::vector<std::string> vhigh;
        std::vector<std::string> vlow;
        std::vector<std::string> vclose;
        std::vector<std::string> vvolume;
        std::vector<std::string> vsymbol;
        // string file = DO CHECKSYM FUNCTION +"_data.csv";
        CheckSymbol cs;
        std::string file = cs.CheckSym();
        std::ifstream stockData(file);
        if (stockData.is_open()){
            std::string line;
            getline(stockData,line);    //ignore the first line

            while (!stockData.eof()) {
                getline(stockData,date,',');
                vdate.push_back(date);
                getline(stockData,open, ',');
                vopen.push_back(open);
                getline(stockData,high,',');
                vhigh.push_back(high);
                getline(stockData, low, ',');
                vlow.push_back(low);
                getline(stockData,close,',');
                vclose.push_back(close);
                getline(stockData,volume, ',');
                vvolume.push_back(volume);
                getline(stockData,symbol,'\n');
                vsymbol.push_back(symbol);
            }
        }
        else{
            std::cout << "Unable to open file." << std::endl;

        }
        Stock* A = new Stock(vdate,vopen,vhigh,vlow,vclose,vvolume,vsymbol);
        vec.push_back(A);
        counter++;
    }

    Stock* getStock(int i){
        return vec.at(i);
    }

    void display(){
        for (unsigned i = 0; i < counter; ++i){
            std::cout << "=== STOCK #" << i+1 << " ===" << std::endl;
            vec.at(i)->printStockInformation(1259);
            std::cout << std::endl;
        }

    }
    void RemoveStock(){
        bool loop = true;
        int input;
        this->display();
        while (loop) {
            std::cout << std::endl << "Select stock to remove: ";
            std::cin >> input;
            input -= 1;
            if(input >= 0 && input <= counter) {
                vec.erase(vec.begin() +input);
                counter--;
                loop = false;
                this->display();
                std::cout << "stock removed!";
            }
            else
                std::cout << "Invalid input!" << std::endl;
            loop = false;
        }
    }

};
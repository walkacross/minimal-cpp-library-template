#include <iostream>
#include <string>
#include <vector>
#include "libminimal/domain_knowledge/finance/portfolio_analysis/CheckDate.h"
#include "libminimal/domain_knowledge/finance/portfolio_analysis/portfolio.h"
#include "libminimal/domain_knowledge/finance/portfolio_analysis/stock.h"
using namespace std;

void printMenu();

int main(){
    printMenu();
    return 0;
}


void printMenu(){
    char input = ' ';
    int select = 0;
    Stock* currentStock = nullptr;
    Portfolio portfolio;
    while (input != 'q'){
        if (currentStock == nullptr){
            cout << "===== NO STOCK SELECTED =====" << endl;
        }
        else{
            cout << "=== Current Stock: " << currentStock->getSymbol() << " ===" << endl;
        }
        cout << "--------- S&P 500 Stock Data ----------" << endl
             << "        02/07/2013 to 02/07/2018       " << endl
             << "Select an option from the menu:" << endl
             << "1. Select stock from portfolio" << endl
             << "2. Add stock to portfolio" << endl
             << "3. Remove stock from portfolio" << endl
             << "4. Show single day gain" << endl
             << "5. Show gains over a period" << endl
             << "6. Show volume sold in one day" << endl
             << "7. Show current stock data" << endl
             << "8. Show current portfolio" << endl
             << "Type 'q' to quit."  << endl << endl
             << "Enter a number: ";
        cin >> input;
        cout << endl << endl;
        if (input == '1'){
            if (portfolio.isEmpty() == true){
                cout << "Portfolio is empty!" << endl;
                input = ' ';
            }
            else{
                portfolio.display();
                cout << "Select Stock: ";
                cin >> select;
                currentStock = portfolio.getStock(select-1);
                input = ' ';
            }

        }
        else if (input == '2'){        //add stock
            portfolio.AddStock();
            input = ' ';

        }
        else if (input == '3'){
            portfolio.RemoveStock();
            cout << endl  << endl;
            input = ' ';
        }
        else if (input == '4'){            // single day gain
            // int day = CHECKDATE()
            CheckDate d1;
            int day = d1.index();
            cout << "Single day gain = ";
            double ans = 100 *  currentStock->getPercentageChange(day);
            cout << ans << " percent" <<endl;
            input = ' ';
        }
        else if (input == '5'){        //gains over a period
            //int day1 = CHECKDATE();  int day2 = CHECKDATE();
            CheckDate d1;
            int day1 = d1.index();
            int day2 = d1.index();
            cout << "Gains over period = ";
            double ans =100 * currentStock->getPercentageChange(day1,day2);
            cout << ans << " percent" << endl;
            input = ' ';
        }
        else if (input == '6'){    // volume
            // int day = CHECKDATE()
            CheckDate d1;
            int day  = d1.index();
            cout << "Single day volume: " << endl;
            currentStock->getDate(day);
            double ans = currentStock->getVolume(day);
            cout << ans << endl;
            input = ' ';
        }
        else if (input == '7'){
            // int day = CHECKDATE()
            CheckDate d1;
            int day = d1.index();
            cout << "Current Stock data" << endl << endl;
            currentStock->printStockInformation(day);
            input = ' ';
        }
        else if (input == '8'){
            cout << "show portfolio" << endl << endl;
            portfolio.display();
            input = ' ';
        }
        else if (input == 'q'){
            cout << "Bye!" << endl << endl;
            break;
        }
    }

}

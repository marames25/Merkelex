#pragma once;
#include <string>
#include <map>
#include "OrderBokkEntry.h"
using namespace std;
class Wallet{
public:
    Wallet();
    /** insert currency to the wallet */
    void insertCurrency(string type, double amount);

    /** remove currency from the wallet */
    bool removeCurrency(string type, double amount);

    /** check if the wallet contains currency */
    bool containsCurrency(string type, double amount);

    /** check if this wallet can cope with this ask or bid */
    bool canFulfillOrder(OrderBookEntry order);

    /** update the contents of the wallet
     * assumer the order was made by the owner of the wallet
     * */
    void processSale(OrderBookEntry& sale);

    /** generate a string representation of the wallet */
    string toString();
    friend std::ostream& operator<<(std::ostream& os, Wallet& wallet);

private:
    map<string,double> currencies;
    
};

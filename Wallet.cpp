#include "Wallet.h"
#include "CSVReader.h"
Wallet::Wallet() {

}
void Wallet:: insertCurrency(string type, double amount){
    double balance;
    if(amount<0){
        throw exception{};
    }
    if(currencies.count(type) == 0){ // not there yet
        balance = 0;
    } else{ // there is
        balance =  currencies[type];
    }
    balance+=amount;
    currencies[type] = balance;
}
bool Wallet::removeCurrency(string type, double amount){
    if(amount < 0){
        return false;
    }
    if(currencies.count(type) == 0){ // not there yet
        return false;
    } else{ // there is/ do we have enough
        if(containsCurrency(type,amount)){ // we have enough
            currencies[type] -= amount;
            return true;
        }
        else //not enough
            return false;
    }
}

bool Wallet::containsCurrency(string type, double amount){
    if(currencies.count(type) == 0) return false;// not there yet
    else return currencies[type] >=amount;
        return  false;
}

string Wallet::toString() {
    string s;
    for(pair<string,double>pair : currencies){
        string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + to_string(amount) + "\n";
    }
    return s;
}

bool Wallet::canFulfillOrder(OrderBookEntry order) {
    vector<string> currs = CSVReader :: tokenise(order.product, '/');
    //ask
    if(order.orderType == OrderBookType::ask){
        double amount = order.amount;
        string currency = currs[0];
        cout<<"Wallet::canFulfillOrder"<<currency<<" : "<<amount<<endl;
        return containsCurrency(currency, amount);
    }
    //bid
    if(order.orderType == OrderBookType::bid){
        double amount = order.amount * order.price;
        string currency = currs[1];
        cout<<"Wallet::canFulfillOrder"<<currency<<" : "<<amount<<endl;
        return containsCurrency(currency, amount);
    }

    return false;
}
void Wallet::processSale(OrderBookEntry& sale){
    vector<string> currs = CSVReader :: tokenise(sale.product, '/');
    //ask
    if(sale.orderType == OrderBookType::asksale){
        double outgoingAmount = sale.amount;
        string outgoingCurrency = currs[0];
        double incomingAmount = sale.amount * sale.price;
        string incomingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
    //bid
    if(sale.orderType == OrderBookType::bidsale){
        double incomingAmount = sale.amount;
        string incomingCurrency = currs[0];
        double outgoingAmount = sale.amount * sale.price;
        string outgoingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
}


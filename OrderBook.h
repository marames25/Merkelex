#pragma once
#include "OrderBokkEntry.h"
#include "CSVReader.h"
#include <vector>
#include <string>
using namespace std;
class OrderBook{
public:
    /** constructor, reading a CSV data file */
    OrderBook(string filename);
    /** return a vector of all known products in a data set*/
    vector<string>getKnownProducts();
    /** return a vector of orders according to the sent filters*/
    vector<OrderBookEntry>getOrders(OrderBookType type,
                                    string product,
                                    string timestamp);
    string getEarliestTime();
    /** return the next time after the sent time in the order book */
    string getNextTime(string timestamp);
    void insertOrder(OrderBookEntry& order);

    vector<OrderBookEntry> matchAsksToBids(string product, string timestamp);

    static double getHighPrice(vector<OrderBookEntry>&orders);
    static double getLowPrice(vector<OrderBookEntry>&orders);
private:
    vector<OrderBookEntry>orders;
};
#pragma once
#include "OrderBokkEntry.h"
#include <vector>
#include <string>
class CSVReader{
public:
    CSVReader();
    static vector<OrderBookEntry>readCSV(string csvFile);
    static vector<string> tokenise(string csvLine, char separator);

    static OrderBookEntry stringToOBE(string priceString,
                                      string amountString,
                                      string timestamp,
                                      string product,
                                      OrderBookType OrderType);


private:
    static OrderBookEntry stringToOBE(vector<string>strings);


};
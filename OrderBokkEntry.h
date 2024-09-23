#pragma once
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

enum class OrderBookType{bid,ask,unknown,asksale,bidsale};



class OrderBookEntry
        {
public:
    OrderBookEntry(double _price,
                    double _amount,
                    string _timestamps,
                    string _product,
                    OrderBookType _orderType,
                    string username = "dataset");
    static OrderBookType stringToOrderBookType(string s);

    static bool  compareByTimestamp(OrderBookEntry& e1,OrderBookEntry& e2)
    {
        return e1.timestamps < e2.timestamps;
    }
    static bool  compareByPriceAsc(OrderBookEntry& e1,OrderBookEntry& e2)
    {
        return e1.price < e2.price;
    }
    static bool  compareByPriceDesc(OrderBookEntry& e1,OrderBookEntry& e2)
    {
        return e1.price > e2.price;
    }
    double price;
    double amount;
    string timestamps;
    string product;
    OrderBookType orderType;
    string username;

};
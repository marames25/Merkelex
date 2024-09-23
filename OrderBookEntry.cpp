#include "OrderBokkEntry.h"

OrderBookEntry::OrderBookEntry(double _price,
               double _amount,
               string _timestamps,
               string _product,
               OrderBookType _orderType, string _username)
: price(_price),
  amount(_amount),
  timestamps(_timestamps),
  product(_product),
  orderType(_orderType),
  username (_username){
}
OrderBookType OrderBookEntry:: stringToOrderBookType(string s){
    if(s == "ask") return OrderBookType::ask;
    if(s == "bid") return OrderBookType::bid;
    return OrderBookType::unknown;
}


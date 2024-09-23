#include "OrderBook.h"
#include "CSVReader.h"
#include <string>
#include <map>
#include <algorithm>
/** constructor, reading a CSV data file */
OrderBook::OrderBook(string filename){
    orders = CSVReader::readCSV(filename);
}
/** return a vector of all known products in a data set*/
vector<string> OrderBook::getKnownProducts(){
    vector<string> products;
    map<string,bool>prodMap;
    for(OrderBookEntry&e : orders){
        prodMap[e.product] = true;
    }

    for(auto const& e : prodMap){
        products.push_back(e.first);
    }
    return products;
}
/** return a vector of orders according to the sent filters*/
vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                            string product,
                                            string timestamp){
    vector<OrderBookEntry> orders_sub;
    for(OrderBookEntry&e : orders){
        if(e.orderType == type &&
            e.product == product &&
            e.timestamps == timestamp){
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}
double OrderBook:: getHighPrice(vector<OrderBookEntry>&orders){
    double max = orders[0].price;
    for(OrderBookEntry& e:orders){
        if(e.price>max) max= e.price;
    }
     return max;
}
double OrderBook:: getLowPrice(vector<OrderBookEntry>&orders){
    double min = orders[0].price;
    for(OrderBookEntry& e:orders){
        if(e.price<min) min= e.price;
    }
    return min;
}
string OrderBook::getEarliestTime() {
    return orders[0].timestamps;
}
string OrderBook::getNextTime(string timestamp){
    string next_timestamp = "";
    for(OrderBookEntry&e:orders){
        if(e.timestamps>timestamp){
            next_timestamp = e.timestamps;
            break;
        }
    }
    if(next_timestamp ==""){
        next_timestamp = orders[0].timestamps;
    }
    return next_timestamp;
}
void OrderBook:: insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    sort(orders.begin(),orders.end(),OrderBookEntry::compareByTimestamp);
}
vector<OrderBookEntry> OrderBook::matchAsksToBids(string product, string timestamp){
    vector<OrderBookEntry> asks = getOrders(OrderBookType::ask,
            product,
            timestamp);
    vector<OrderBookEntry> bids = getOrders(OrderBookType::bid,
                                            product,
                                            timestamp);
    vector<OrderBookEntry> sales;
    sort(asks.begin(),asks.end(), OrderBookEntry::compareByPriceAsc);
    sort(bids.begin(),bids.end(), OrderBookEntry::compareByPriceDesc);

    for(OrderBookEntry&ask:asks){
        for(OrderBookEntry&bid : bids){
            if(bid.price>= ask.price){
                OrderBookEntry sale {ask.price,0 , timestamp,product,OrderBookType::asksale};
                OrderBookType type = OrderBookType::asksale;

                if(bid.username == "simuser"){
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::bidsale;
                }
                if(ask.username == "simuser"){
                    sale.username = "simuser";
                    sale.orderType =  OrderBookType::asksale;
                }


                if(bid.amount == ask.amount){
                    sale.amount= ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;
                }
                if(bid.amount > ask.amount){
                    sale.amount= ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount-ask.amount;
                    break;
                }
                if(bid.amount < ask.amount && bid.amount >0){
                    sale.amount= bid.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount-bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }
        }
    }
    return sales;
}




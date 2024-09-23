#include "MerkelMain.h"
#include <iostream>
#include <limits>
#include <vector>
#include "OrderBokkEntry.h"
#include "CSVReader.h"
#include "OrderBook.h"
#include "Wallet.h"
using namespace std;

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    wallet.insertCurrency("BTC", 10);
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain:: printMenu()
{
    cout << "\n**********";
    cout << "\n1: print help \n";
    cout << "2: print exchange stats \n";
    cout << "3: make an offer \n";
    cout << "4: make a bid \n";
    cout << "5: print wallet \n";
    cout << "6: continue \n";
    cout << "**********\n" << "Select a number from 1-6:\n ";
    cout<<"Current time is: "<<currentTime<<endl;
}

void MerkelMain::printHelp()
{
    cout << "Help - choose options from the menu" << endl;
}

void MerkelMain::printMarketStats()
{
    for(string const p  : orderBook.getKnownProducts()){
        cout<<"Product: "<<p<<endl;
        vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                             p,currentTime);
        cout<<"Asks seen: "<<entries.size()<<endl;
        cout<<"Max ask : "<<OrderBook::getHighPrice(entries)<<endl;
        cout<<"min ask : "<<OrderBook::getLowPrice(entries)<<endl;


    }
//    cout << "OrderBOok contains : " << orders.size()<< "  entries" << endl;
//    unsigned int bids = 0;
//    unsigned int asks = 0;
//    for(OrderBookEntry& e : orders){
//        if(e.orderType == OrderBookType::ask) asks ++;
//        if(e.orderType == OrderBookType::bid) bids ++;
//    }
//    cout << "OrderBook asks : " << asks<< " ,bids: " <<bids<< endl;

}

void MerkelMain::enterAsk()
{
    cout << "make an ask-enter amount: product,price,amount,eg-ETH/BTC,200,0.5" << endl;
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    vector<string> tokens = CSVReader:: tokenise(input, ',');
    if(tokens.size() != 3){
        cout<<"MerkelMain::enterAsk Bad input! \n"<<input<<endl;
    }
    else{
        try {
            OrderBookEntry obe = CSVReader::stringToOBE(tokens[1],
                                                        tokens[2],
                                                        currentTime,
                                                        tokens[0],
                                                        OrderBookType::ask);
            obe.username = "simuser";
            if(wallet.canFulfillOrder(obe)){
                cout<<"Wallet looks good "<<endl;
                orderBook.insertOrder(obe);
            }else{
                cout<<"Wallet has insufficient funds "<<endl;
            }
            orderBook.insertOrder(obe);
        } catch (const exception&e)
        {
            cout<<"MerkelMain::enterAsk bad input!"<<endl;
        }
    }
        cout<<"you typed: "<<input<<endl;
}

void MerkelMain::enterBid()
{
    cout << "make a bid-enter  amount: product,price,amount,eg-ETH/BTC,200,0.5" << endl;
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    vector<string> tokens = CSVReader:: tokenise(input, ',');
    if(tokens.size() != 3){
        cout<<"MerkelMain::enterBid Bad input! \n"<<input<<endl;
    }
    else{
        try {
            OrderBookEntry obe = CSVReader::stringToOBE(tokens[1],
                                                        tokens[2],
                                                        currentTime,
                                                        tokens[0],
                                                        OrderBookType::bid);
            obe.username = "simuser";
            if(wallet.canFulfillOrder(obe)){
                cout<<"Wallet looks good "<<endl;
                orderBook.insertOrder(obe);
            }else{
                cout<<"Wallet has insufficient funds "<<endl;
            }
            orderBook.insertOrder(obe);
            orderBook.insertOrder(obe);
        } catch (const exception&e)
        {
            cout<<"MerkelMain::enterBid  bad input!"<<endl;
        }
    }
    cout<<"you typed: "<<input<<endl;
}

void MerkelMain::printWallet()
{
    cout<<wallet.toString()<<endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    cout<<"Going to next time frame"<<endl;
    vector <OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC",currentTime);
    cout<<"Sales: "<<sales.size()<<endl;
    for(OrderBookEntry&sale : sales){
        cout<<"Sale price: "<<sale.price<<" Amount "<<sale.amount<<endl;
        if(sale.username == "simuser"){
            //update the wallet
            wallet.processSale(sale);
        }
    }
    currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int userOption;
    cin >> userOption;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nINVALID INPUT. Please enter a number from 1 to 6.\n" << endl;
        return -1;
    }
    cout << "You chose: " << userOption << endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    switch(userOption)
    {
        case 1:
            printHelp();
            break;
        case 2:
            printMarketStats();
            break;
        case 3:
            enterAsk();
            break;
        case 4:
            enterBid();
            break;
        case 5:
            printWallet();
            break;
        case 6:
            gotoNextTimeFrame();
            break;
        default:
            cout << "\nINVALID INPUT, please choose a number from 1-6.\n " << endl;
            break;
    }
}

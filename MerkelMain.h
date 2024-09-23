#pragma once
#include <vector>
#include "OrderBokkEntry.h"
#include "OrderBook.h"
#include "Wallet.h"
class MerkelMain
{
    public:
        MerkelMain();
        /** call this to start the sim */
        void init();
    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int  getUserOption();
        void processUserOption(int userOption);
        string currentTime;
        OrderBook orderBook{"20200317 (3).csv"};
        Wallet wallet;



};
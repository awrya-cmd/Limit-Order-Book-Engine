#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "Order.h"
using namespace std;


struct BuyCompare
{

    bool operator()(const Order& a, const Order& b)
    {

        if (a.price == b.price)
            return a.timestamp > b.timestamp;

        return a.price < b.price;
    }
};

struct SellCompare
{

    bool operator()(const Order& a, const Order& b)
    {

        if (a.price == b.price)
            return a.timestamp > b.timestamp;

        return a.price > b.price;
    }
};

struct Trade
{

    int quantity;
    double price;
};

class MatchingEngine
{

    private:

         priority_queue<Order,  vector<Order>, BuyCompare> buyOrders;
         priority_queue<Order,  vector<Order>, SellCompare> sellOrders;

         vector<Trade> tradeHistory;

        int nextOrderId = 1;

    public:

        void placeBuyOrder()
        {

            double price;
            int quantity;

             cout << "Enter BUY price: ";
             cin >> price;

             cout << "Enter quantity: ";
             cin >> quantity;

            Order order(nextOrderId++, "BUY", price, quantity);

            buyOrders.push(order);

            matchOrders();
        }

        void placeSellOrder()
        {

            double price;
            int quantity;

             cout << "Enter SELL price: ";
             cin >> price;

             cout << "Enter quantity: ";
             cin >> quantity;

            Order order(nextOrderId++, "SELL", price, quantity);

            sellOrders.push(order);

            matchOrders();
        }

        void matchOrders()
        {

            while (!buyOrders.empty() && !sellOrders.empty())
            {

                Order buy = buyOrders.top();
                Order sell = sellOrders.top();

                if (buy.price >= sell.price)
                {

                    int tradedQty =  min(buy.quantity, sell.quantity);

                     cout << "\nTrade executed: "
                            << tradedQty
                            << " shares @ "
                            << sell.price
                            << "\n";

                    tradeHistory.push_back({tradedQty, sell.price});

                    buyOrders.pop();
                    sellOrders.pop();

                    buy.quantity -= tradedQty;
                    sell.quantity -= tradedQty;

                    if (buy.quantity > 0)
                        buyOrders.push(buy);

                    if (sell.quantity > 0)
                        sellOrders.push(sell);
                }

                else
                    break;
            }
        }

        void showOrderBook()
        {

             cout << "\n===== ORDER BOOK =====\n";

             cout << "\nBuy Orders:\n";

            auto buyCopy = buyOrders;

            while (!buyCopy.empty())
            {

                Order o = buyCopy.top();
                buyCopy.pop();

                 cout << "BUY "
                        << o.quantity
                        << " @ "
                        << o.price
                        << "\n";
            }

             cout << "\nSell Orders:\n";

            auto sellCopy = sellOrders;

            while (!sellCopy.empty())
            {

                Order o = sellCopy.top();
                sellCopy.pop();

                 cout << "SELL "
                        << o.quantity
                        << " @ "
                        << o.price
                        << "\n";
            }
        }

        void showTrades()
        {

             cout << "\n===== TRADE HISTORY =====\n";

            if (tradeHistory.empty())
            {

                 cout << "No trades executed\n";
                return;
            }

            for (auto &t : tradeHistory)
            {

                 cout << t.quantity
                        << " shares @ "
                        << t.price
                        << "\n";
            }
        }

        void showMarketStats()
        {

             cout << "\n===== MARKET STATS =====\n";

            if (tradeHistory.empty())
            {

                 cout << "No trades yet\n";
                return;
            }

            int totalVolume = 0;
            double totalValue = 0;
            double maxPrice = 0;

            for (auto &t : tradeHistory)
            {

                totalVolume += t.quantity;
                totalValue += t.quantity * t.price;

                if (t.price > maxPrice)
                    maxPrice = t.price;
            }

            double avgPrice = totalValue / totalVolume;

             cout << "Total Trades: "
                    << tradeHistory.size()
                    << "\n";

             cout << "Total Volume: "
                    << totalVolume
                    << "\n";

             cout << "Average Trade Price: "
                    << avgPrice
                    << "\n";

             cout << "Highest Trade Price: "
                    << maxPrice
                    << "\n";
        }
};

#endif
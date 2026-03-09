#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <chrono>
using namespace std;

class Order
{

public:
    int orderId;
    string side;
    double price;
    int quantity;
    long long timestamp;

    Order(int id, string s, double p, int q)
        : orderId(id), side(s), price(p), quantity(q)
    {

        timestamp = chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    }
};

#endif
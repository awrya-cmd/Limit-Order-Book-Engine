#include <iostream>
#include "MatchingEngine.h"
using namespace std;

int main()
{

    MatchingEngine engine;
    int choice;

    while (true)
    {

        cout << "\n===== LIMIT ORDER BOOK ENGINE =====\n";

        cout << "1 Place Buy Order\n";
        cout << "2 Place Sell Order\n";
        cout << "3 Show Order Book\n";
        cout << "4 Show Trade History\n";
        cout << "5 Market Statistics\n";
        cout << "6 Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                engine.placeBuyOrder();
                break;

            case 2:
                engine.placeSellOrder();
                break;

            case 3:
                engine.showOrderBook();
                break;

            case 4:
                engine.showTrades();
                break;

            case 5:
                engine.showMarketStats();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
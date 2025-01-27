#ifndef POCKETMONEY_H
#define POCKETMONEY_H

#include <string>
using namespace std;

class PocketMoney {
private:
    string source;
    double amountReceived;
    static double totalAmount;  // Static variable to track total money

public:
    PocketMoney(const string& src, double amount);
    void display() const;
    static double getTotalAmount();  // Static function to access totalAmount
};

#endif // POCKETMONEY_H
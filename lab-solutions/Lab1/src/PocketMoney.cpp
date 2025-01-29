#include "../headers/PocketMoney.h"
#include <iostream>
using namespace std;

double PocketMoney::totalAmount = 0.0;

PocketMoney::PocketMoney(const string& src, double amount)
    : source(src), amountReceived(amount) {
    totalAmount += amount;
}

void PocketMoney::display() const {
    cout << "Received $" << amountReceived << " from " << source << endl;
    cout << "Total amount in wallet: $" << totalAmount << endl;
}

// Static function to get the total amount
double PocketMoney::getTotalAmount() {
    return totalAmount;
}
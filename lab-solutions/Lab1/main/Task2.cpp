#include "../headers/PocketMoney.h"
#include <iostream>

int main() {
    PocketMoney money1("Parents", 50.0);
    money1.display();

    PocketMoney money2("Grandparents", 30.0);
    money2.display();

    PocketMoney money3("Part-time Job", 100.0);
    money3.display();

    std::cout << "Final total amount in wallet: $" << PocketMoney::getTotalAmount() << std::endl;

    return 0;
}
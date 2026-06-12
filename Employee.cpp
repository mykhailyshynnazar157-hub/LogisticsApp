#include "Employee.h"
#include <iostream>
#include <vector> 
using namespace std;

Employee::Employee(string n) : name(n) {}

void Employee::printInfo() {
    cout << "Worker name: " << name << endl;
}

Driver::Driver(string status, string n) : Employee(n), status(status), myTruck(nullptr) {}

void Driver::deliverOrder() {
    cout << "Finished" << endl;
}

Logist::Logist(string n) : Employee(n) {}

void Logist::assignOrder() {
    cout << "Logist " << name << " assigned the order." << endl;
}


double Logist::findBestOrder(std::vector<Order*>& bank, Driver* driver) {
    Transport* truck = driver->getTruck();


    if (truck == nullptr) {
        cout << "Driver has no a truck" << endl;
        return 0.0;
    }

    Order* bestChoice = nullptr;
    double maxProfit = -1.0;

    cout << "Logist " << name << "Searching for the best delivering " << endl;

    // Перебираємо всі замовлення компанії
    for (int i = 0; i < bank.size(); i++) {
        Order* currentOrder = bank[i];
        // Умова 2: Шукаємо найдорожче замовлення
        if (currentOrder->status == "Expected" && currentOrder->shipping_cost > maxProfit) {
            maxProfit = currentOrder->shipping_cost;
            bestChoice = currentOrder;
        }
    }

    // Якщо ми знайшли хороше замовлення
    if (bestChoice != nullptr) {
        cout << "Delivering is fond #" << bestChoice->orderID
            << " in price " << bestChoice->shipping_cost << "$" << endl;

        bestChoice->status = "Delivered";
        driver->deliverOrder();

        return bestChoice->shipping_cost;

    }
    else {
        cout << "There is no any orders" << endl;
        return 0.0;
    }
}
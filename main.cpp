#include <iostream>
#include <vector>
#include <fstream> 
#include "LogisticsCompany.h"
#include "Order.h"
#include "Transport.h"
#include "Employee.h"

using namespace std;

int main() {

    LogisticsCompany myCompany("Nazar Logistics");

    Transport* truck1 = new Transport("BC 1456 AA");
    Transport* truck2 = new Transport("BC 2987 CX");
    Transport* truck3 = new Transport("BC 7729 BO");
    Transport* truck4 = new Transport("BC 4182 DI");

    myCompany.addTruck(truck1);
    myCompany.addTruck(truck2);
    myCompany.addTruck(truck3);
    myCompany.addTruck(truck4);

    Driver* driver1 = new Driver("Active", "Ivan");
    driver1->assignTruck(truck1);

    Driver* driver2 = new Driver("Active", "Petro");
    driver2->assignTruck(truck2);

    Driver* driver3 = new Driver("Active", "Dima");
    driver3->assignTruck(truck3);

    Driver* driver4 = new Driver("Active", "Oleg");
    driver4->assignTruck(truck4);

    myCompany.hireEmployee(driver1);
    myCompany.hireEmployee(driver2);
    myCompany.hireEmployee(driver3);
    myCompany.hireEmployee(driver4);

    Logist* chiefLogist = new Logist("Oleksiy");
    myCompany.hireEmployee(chiefLogist);

    ifstream inFile("orders.txt");
    
    if (inFile.is_open()) {
        int id;
        string dest;
        double cost;
        string trailer;

        while (inFile >> id >> dest >> cost >> trailer) {
            myCompany.addOrder(new Order(id, dest, cost, trailer));
        }
        inFile.close();
        cout << "[System] Database successfully loaded from orders.txt!\n\n";
    }
    

    int choice = -1;

    while (choice != 0) {
        cout << "   Nazar Logistics\"\n";
        cout << "1. Show all orders\n";
        cout << "2. Show company staff\n";
        cout << "3. Run Logist shift (distribute orders)\n";
        cout << "4. Show financial statistics\n";
        cout << "0. Save report and exit\n";
        cout << "Choose an action (enter a number): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nOrder data\n";

            for (int i = 0; i < myCompany.getOrders().size(); i++) {
                myCompany.getOrders()[i]->Order_info();
                cout << "----------------------\n";
            }
            break;

        case 2:
            cout << "\nCOMPANY STAFF\n";

            for (int i = 0; i < myCompany.getStaff().size(); i++) {
                myCompany.getStaff()[i]->printInfo();
            }
            break;

        case 3:
            cout << "\nLOGIST WORKING SHIFT\n";

            myCompany.addProfit(chiefLogist->findBestOrder(myCompany.getOrders(), driver1));
            myCompany.addProfit(chiefLogist->findBestOrder(myCompany.getOrders(), driver2));
            myCompany.addProfit(chiefLogist->findBestOrder(myCompany.getOrders(), driver3));
            myCompany.addProfit(chiefLogist->findBestOrder(myCompany.getOrders(), driver4));
            cout << "Order distribution completed!\n";
            break;

        case 4:

            myCompany.showCompanyStats();
            break;

        case 0: {
            myCompany.exportReport();
            break;
        }
        }
    }
    return 0;
}
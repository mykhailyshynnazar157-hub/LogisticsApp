#include "LogisticsCompany.h"
#include <iostream>
#include <fstream> 

LogisticsCompany::LogisticsCompany(std::string name)
    : companyName(name), totalProfit(0.0), completedShipments(0) {
}

void LogisticsCompany::addTruck(Transport* t) { fleet.push_back(t); }
void LogisticsCompany::addOrder(Order* o) { orderBank.push_back(o); }
void LogisticsCompany::hireEmployee(Employee* e) { staff.push_back(e); }

void LogisticsCompany::addProfit(double amount) {
    if (amount > 0) {
        totalProfit += amount;
        completedShipments++;
    }
}

void LogisticsCompany::showCompanyStats() {
    std::cout << companyName << std::endl;
    std::cout << "Trucks in fleet: " << fleet.size() << std::endl;
    std::cout << "Total Employees: " << staff.size() << std::endl;
    std::cout << "Completed Shipments: " << completedShipments << std::endl;
    std::cout << "Total Profit: $" << totalProfit << std::endl;
    
}

LogisticsCompany::~LogisticsCompany() {
    for (auto o : orderBank) delete o;
    for (auto t : fleet) delete t;
    for (auto s : staff) delete s;
}

void LogisticsCompany::exportReport() {
    std::ofstream outFile("report.txt"); // Створюємо файл

    if (outFile.is_open()) {
        outFile << "Final report\n";
        outFile << "Company Name: " << companyName << "\n";
        outFile << "Total Staff: " << staff.size() << " employees\n";
        outFile << "Fleet Size: " << fleet.size() << " trucks\n";
        outFile << "Successful Shipments: " << completedShipments << "\n";
        outFile << "Total Net Profit: $" << totalProfit << "\n";
      

        outFile.close();
        std::cout << "Report successfully exported with real data to report.txt!\n";
    }
    else {
        std::cout << "Error: Could not create the file.\n";
    }
}
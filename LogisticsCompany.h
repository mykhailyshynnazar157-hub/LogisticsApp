#pragma once
#pragma once
#include <vector>
#include <string>
#include "Order.h"
#include "Transport.h"
#include "Employee.h"

class LogisticsCompany {
private:
    std::string companyName;
    double totalProfit;          
    int completedShipments;     

    std::vector<Transport*> fleet;
    std::vector<Order*> orderBank;
    std::vector<Employee*> staff;

public:
    LogisticsCompany(std::string name);
    ~LogisticsCompany();

    void addTruck(Transport* t);
    void addOrder(Order* o);
    void hireEmployee(Employee* e);

    void showCompanyStats();

    std::vector<Order*>& getOrders() { return orderBank; }
    std::vector<Employee*>& getStaff() { return staff; }

    void addProfit(double amount);

    void exportReport();
};
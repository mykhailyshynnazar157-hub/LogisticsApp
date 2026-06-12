#pragma once
#include <string>
#include <iostream>
#include "Transport.h"
#include "Order.h"
#include <vector>

class Employee {
protected:
	std::string name;

public:
	Employee(std::string n);
	virtual ~Employee() {}
	virtual void printInfo();

	std::string getName() { return name; }
};

class Driver: public Employee {
private:
	Transport* myTruck;
	std::string status;
public:

	Driver(std::string status, std::string n);
	void assignTruck(Transport* t) {
		myTruck = t;
	}
	Transport* getTruck() {
		return myTruck;
	}

	void deliverOrder();
};

class Logist: public Employee {
public:
	Logist(std::string n);

	double findBestOrder(std::vector<Order*>& bank, Driver* driver);
	void assignOrder();
};
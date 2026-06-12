#pragma once
#include <string>

class Order {
public:
	int orderID;
	std::string destination;
	double shipping_cost;
	std::string trailer;
	std::string status;

	Order(int id, std::string dest, double cost, std::string t);
	void Order_info();
};
#include "Order.h"
#include <iostream>
using namespace std;

Order::Order(int id, string dest, double cost, string t) : orderID(id), destination(dest), shipping_cost(cost), trailer(t), status("Expected")
{
}

void Order::Order_info() {
	cout << "Order #" << orderID << endl;
	cout << "Destination: " << destination << endl;
	cout << "Trailer type: " << trailer << endl;
	cout << "Shipping cost: "<< shipping_cost << "$" << endl;
	cout << "Status: " << status << endl;

}
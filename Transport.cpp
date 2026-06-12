#include "Transport.h"
#include <iostream>
using namespace std;

Transport::Transport(string plate) : Truck_plate(plate), status("Available") {
}
void Transport::SetStatus(std::string newStatus) {
    status = newStatus;
}
string Transport::GetTruck_plate() {
	return Truck_plate;
}

string Transport::GetStatus() {
	return status;
}
bool Transport::isAvailable() {
	return status == "Available";
}

void Transport::TruckInfo() {
	cout << "Truck plate: " << Truck_plate << endl;
	cout << "Status: " << status << endl;

}
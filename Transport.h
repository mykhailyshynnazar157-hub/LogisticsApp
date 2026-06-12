#pragma once
#include <string>


class Transport {
private:
	std::string Truck_plate;
	std::string status;

public:
	Transport(std::string plate);

	std::string GetTruck_plate();
	std::string GetStatus();

	void SetStatus(std::string NewStatus);

	bool isAvailable();

	void TruckInfo();

};
#pragma once
#include <string>
#include <windows.h>
#include "Room.h"

class Person
{
private:
	int id;
	std::string person_name;
	Room* room;
	int preffered_temperature;
	int preffered_lightstrength;

public:
	Person(std::string name, int i, int temp, int light, Room* room_);
	Room* get_room() { return room; };
	void print();
	std::string getPersonName() { return person_name; };
	void Move(Room* r);
	int getPrefferedTemperature() { return preffered_temperature; };
	int getPrefferedLightStrength() { return preffered_lightstrength; };
	~Person() {};
};


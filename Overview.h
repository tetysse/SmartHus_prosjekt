#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <fstream>
#include <direct.h>
#include<limits.h>

#include "House.h"
#include "Room.h"
#include "Person.h"


class Overview
{
protected:
	std::string o_name;
	std::vector<House*> houseList;
	int time;
public:
	Overview(std::string name) { o_name = name; };
	void print_houses();
	void add_house();
	void remove_house();
	void change_address();
	void configure_house();
	void read_config_file();
	void add_instruments(std::string line, Room* room);
	std::vector<std::string> split(const std::string& str, const std::string& delim);
	std::string getTypeAndValues(Instrument* instrument);
	void save_to_file();
	std::vector<Coffee_Machine*> getAllCoffeMachines();
	void set_time(int* time_);
	void move_person();
	void Move(int i, int j, int k);
	void add_person();
	void add_person(House* house);
	~Overview() {}
};


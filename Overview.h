#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "House.h"

class Overview
{
protected:
	std::string o_name;
	std::vector<House*> houseList;
public:
	Overview(std::string name) { o_name = name; };
	void print_houses();
	void add_house();
	void remove_house();
	void change_address();
	void configure_house();
	~Overview() {};
};


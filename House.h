#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Room.h"

class House
{
protected:
	std::string h_name;
	int h_id;
public:
	House(std::string name, int id) {h_name = name, h_id = id};
	void h_set_name(std::string name) { h_name = name; };
	void h_set_id(int id) { h_id = id; };
	std::string h_get_name() { return h_name; };
	int h_get_id() { return h_id; };
	void print_out();
	~House();
};


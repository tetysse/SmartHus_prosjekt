#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Instrument.h"

// Coffee: 
//Name, id, cups of coffee
//Machine status, Time of daily coffee, daily coffee activated
//


class Coffee_Machine : public Instrument
{
protected:
	int c_val;
	int c_time;
	bool c_daily;
public:
	Coffee_Machine(std::string name, int id, int status, Position pos, int time, bool daily) : Instrument(name, id, pos)
	{	c_val = status, c_time = time, c_daily = daily;	};
	std::string print_out();
	int c_get_status() { return c_val; };
	int c_get_time() { return c_time; };
	bool c_get_daily() { return c_daily; }
	void set_coffe_time(int time) { c_time = time; }; // To be added
};


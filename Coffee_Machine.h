#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Instrument.h"

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
	void c_set_val(int val) { c_val = val; };
	void c_set_time(int time) { c_time = time; };
	void c_set_daily(bool daily) { c_daily = daily; };
	int c_get_status() { return c_val; };
	int c_get_time() { return c_time; };
	bool c_get_daily() { return c_daily; }
	void set_coffe_time(int time) { c_time = time; };
	~Coffee_Machine() {};
};


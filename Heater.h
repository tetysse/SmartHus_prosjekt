#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Instrument.h"

class Heater : public Instrument
{
protected:
	int h_val;
public:
	Heater(std::string name, int id, int status, Position pos) : Instrument(name, id, pos)
	{
		h_val = status;
	};
	int get_temperature() { return h_val; };
	std::string print_out();
};
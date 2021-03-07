#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Instrument.h"

class Door : public Instrument
{
protected:
public:
	Door(std::string name, int id, Position pos) : Instrument(name, id, pos) {};
	std::string print_out();
};
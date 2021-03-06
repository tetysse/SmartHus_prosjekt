#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Instrument.h"

class Light : public Instrument
{
protected:
	int l_val;
	bool l_dig;
public:
	Light(std::string name, int id, int status, Position pos, bool dig) : Instrument(name, id, pos)
	{	l_val = status, l_dig = dig; };
	std::string print_out();
	void l_set_dig(bool dig) { l_dig = dig; };
	void l_set_val(int val) { l_val = val; };
	int l_get_status() { return l_val; };
	bool l_get_dig() { return l_dig; };
	~Light() {};
};

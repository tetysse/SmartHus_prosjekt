#pragma once

#include <iostream>
#include <string>

enum class Position : bool { On, Off };

class Instrument
{
protected:
	std::string i_name;
	Position i_pos;
	int i_id;
public:
	Instrument(std::string name, int id, Position pos) : i_name{ name }, i_id{ id }, i_pos{ pos }{};
	virtual std::string print_out() = 0;
	std::string get_name() { return i_name; };
	void set_name(std::string name) { i_name = name; };
	void set_pos(Position pos) { i_pos = pos; };
	bool get_pos() {
		if (i_pos == Position::On) { return true; }
		else { return false; }
	}
	int get_id() { return i_id; }
	virtual ~Instrument() { }; 
};
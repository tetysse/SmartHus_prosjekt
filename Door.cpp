#include "Door.h"

std::string Door::print_out() {
	std::cout << "Door name: " << i_name;
	std::string temp;
	if (i_pos == Position::On)
	{
		temp = "Open";
	}
	else { temp = "Closed"; }
	std::cout << "\tDoor status: " << temp << std::endl;
	return "Door";
}

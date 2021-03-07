#include "Heater.h"

std::string Heater::print_out() {
	std::string temp;
	std::cout << "Heater name: " << i_name;
	if (i_pos == Position::On)
	{
		temp = "On";
	}
	else { temp = "Off"; }
	std::cout << "\tCurrently: " << temp;
	std::cout << "\tDegree: " << (temp == "On" ? h_val : 0) << "\*C\n";
	return "Heater";
}
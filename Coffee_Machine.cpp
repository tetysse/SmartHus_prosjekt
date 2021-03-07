#include "Coffee_Machine.h"

std::string Coffee_Machine::print_out() {
	std::string temp;
	std::cout << "Coffee Machine: " << i_name;
	std::cout << "\tCurrently: ";
	if (i_pos == Position::On)
	{	temp = "On"; }
	else 
	{	temp = "Off"; }
	std::cout << temp;
	std::cout << "\tDegree: " << (temp == "On" ? c_val : 0) << " \370C\n";
	if (c_daily == true) 
	{	std::cout << "Daily coffee: On ";	}
	else
	{	std::cout << "Daily coffee: Off";	}
	std::cout << "\tTime: ";
	if (c_time < 10) { std::cout << "0"; }
	std::cout << c_time << "\:00\n";
	return "Coffe Machine";
}
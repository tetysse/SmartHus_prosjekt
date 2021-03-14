#include "Light.h"

std::string Light::print_out() {
	std::string temp;
	std::cout << "Light name: " << i_name;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "\tCurrently: ";
	if (i_pos == Position::On)
	{
		SetConsoleTextAttribute(hConsole, 2); //Green
		std::cout << "On";
		SetConsoleTextAttribute(hConsole, 7); // white
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 4); // Red
		std::cout << "Off";
		SetConsoleTextAttribute(hConsole, 7); //white
	}
	if (l_dig == false) {
		std::cout << "\tLight: \%: " << (temp == "On" ? l_val : 0) << std::endl;
	}
	else {
		std::cout << "Light is not dimmable\n";
	}
	return "Light";
}
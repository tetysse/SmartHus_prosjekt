#include "Light.h"

std::string Light::print_out() {
	std::string temp;
	std::cout << "Light name: " << i_name;
	if (i_pos == Position::On)
	{
		temp = "On";
	}
	else { temp = "Off"; }
	std::cout << "\tCurrently: " << temp;
	if (l_dig == false) {
		std::cout << "\tLight: \%: " << (temp == "On" ? l_val : 0) << std::endl;
	}
	else {
		std::cout << "Light is not dimmable\n";
	}
	return "Light";
}
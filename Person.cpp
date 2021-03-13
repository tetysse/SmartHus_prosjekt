#include "Person.h"

Person::Person(std::string name, int i, int temp, int light, Room* room_)
{
	id = i;
	person_name = name;
	preffered_temperature = temp;
	preffered_lightstrength = light;
	room = room_;
	//room_->set_all_lights(light);
}

void Person::print()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 11); // cyan?
	std::cout << person_name << " Temp: " << preffered_temperature << " Lightstrength: " << preffered_lightstrength << std::endl;
	SetConsoleTextAttribute(hConsole, 7); //white

}

void Person::Move(Room* r)
{
	room = r;
	//r->set_all_lights(preffered_lightstrength);
}
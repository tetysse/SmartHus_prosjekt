#include "House.h"

void House::add_room() {
	Room* temp;
	char c;
	std::string n_temp;
	int i_temp = h_id + 200 * roomList.size();
	int size;
	bool active = true;
	while (active) {
		std::cout << "----------------------------------------------------------------\n";
		std::cout << "adding a room to " << h_name << std::endl;
		for (int i = 0; i < roomList.size(); i++) {
			std::cout << "Room " << i + 1 << ": " << roomList[i]->r_get_name() << std::endl;
		}
		std::cout << "----------------------------------------------------------------\n";
		std::cout << "Add a name to the room: ";
		std::cin >> n_temp;
		temp = new Room(n_temp, i_temp);
		roomList.push_back(temp);
		size = roomList.size();
		std::cout << "Want to add quick instruments to the room? (heaters, doors, lights and coffe machine) (Y/N) ";
		std::cin >> c;
		if (c == 'y' || c == 'Y') {
			roomList[size - 1]->quick_start(i_temp, size);
		}
		std::cout << "Do you wish to add another room? (Y/N) ";
		std::cin >> c;
		if (c != 'y' && c != 'Y') {
			active = false;
		}
	}
}

void print_inst_type(int c, std::string &temp) {
	if (c == 1) {
		temp = "door";
	}
	else if (c == 2) {
		temp = "light";
	}
	else if (c == 3) {
		temp = "heater";
	}
	else if (c == 4) {
		temp = "coffe machine";
	}
	else if (c == 5) {
		temp = "instrument";
	}
	else { 
		temp = "Not available";
	}
}

void House::configure_room() {
	int c;
	int c2;
	char c3;
	int max_instrument = 0;
	std::string type_t;
	bool active = true;
	while (active)
	{
		std::cout << "----------------------------------------------------------------\n";
		std::cout << "Configuring an instrument in the room...\n";
		std::cout << "Select in which room to add/remove or configure an instrument (1 - " << roomList.size() << "):\n";
		for (int i = 0; i < roomList.size(); i++) {
			std::cout << "Room " << i + 1 << " - " << roomList[i]->r_get_name() << std::endl;
		}
		std::cout << "Press '0' to return to main menu\n";
		std::cin >> c;
		if (c != 0)
		{
			std::cout << "----------------------------------------------------------------\n";
			std::cout << "                   Room: " << roomList[c - 1]->r_get_name();
			std::cout << "----------------------------------------------------------------\n";
			std::cout << "Do you wish to:\n";
			std::cout << "1:  Add a door\n";
			std::cout << "2:  Remove a door\n";
			std::cout << "3:  Configure a door\n";
			std::cout << "4:  Open/close all doors\n";
			std::cout << "11: Add a light\n";
			std::cout << "12: Remove a light\n";
			std::cout << "13: Configure a light\n";
			std::cout << "14: Turn on/off all lights";
			std::cout << "21: Add a heater\n";
			std::cout << "22: Remove a heater\n";
			std::cout << "23: Configure a heater\n";
			std::cout << "24: Turn on/off all heaters\n";
			std::cout << "31: Add a coffee machine\n";
			std::cout << "32: Remove a coffee machine\n";
			std::cout << "33: Configure a coffee machine\n";
			std::cout << "34: Turn on/off all coffee machines\n";
			std::cout << "9:  Print room\n";
			std::cout << "0:  Return to main menu\n";
			std::cout << "----------------------------------------------------------------\n";
			std::cin >> c2;
			if (c2 > 0 && c2 < 35) {
				print_inst_type((c % 10), type_t);
				if (c2 % 10 == 1) {
					max_instrument = roomList[c - 1]->instrument_count(5);
					roomList[c - 1]->add_instrument(max_instrument + 1, ((c2-1)/10)+1);
				}
				else if (c2 % 10 == 2) {
					roomList[c - 1]->delete_instrument(((c2 - 1) / 10) + 1);
				}
				else if (c2 % 10 == 3) {
					roomList[c - 1]->configure_instrument(((c2 - 1) / 10) + 1);
				}
				else if (c2 % 10 == 4) {
					std::cout << "Do you want to turn all the " << type_t << " On or Off ('Y' = On, 'N' = Off): ";
					std::cin >> c3;
					if (c3 == 'y' || c3 == 'Y') {
						roomList[c - 1]->turn_instruments((((c2 - 1) / 10) + 1), Position::On);
					}
					else if (c3 == 'n' || c3 == 'N') {
						roomList[c - 1]->turn_instruments((((c2 - 1) / 10) + 1), Position::Off);
					}
					else { std::cout << "Invalid input...\n"; }
				}
				else if (c2 == 9) {
					roomList[c - 1]->print_room(1);
				}
				else { 
					std::cout << "Invalid input, returning to main menu...\n"; 
					active = false;
				}
			}
			else if (c2 == 0) {
				active = false;
			}
		}
		else { active = false; }
	}
}

void House::remove_room(int house_rem) {
	int count;
	std::string name;
	int length;
	int c;
	if (house_rem != 1)
	{
		std::cout << "----------------------------------------------------------------\n";
		std::cout << "Select a room to remove:\n";
		for (int i = 0; i < roomList.size(); i++) {
			name = roomList[i]->r_get_name();
			length = static_cast<int>(name.length());
			count = roomList[i]->instrument_count(5);
			std::cout << i + 1 << ": " << name << " ";
			for (int j = 0; j < (12 - length); j++) {
				std::cout << " ";
			}
			std::cout << "Instruments: " << count << std::endl;
		}
		std::cin >> c;
		std::cout << "Removing a room and all instruments...\n";
		//roomList[c - 1]->delete_all_instruments();
		roomList[c - 1]->~Room();
		roomList.erase(roomList.begin() + c - 1);
		std::cout << "----------------------------------------------------------------\n";
	}
	else if (house_rem == 1){
		for (int j = 0; j < roomList.size(); j++) {
			//roomList[j]->delete_all_instruments();
			roomList[j]->~Room();
		}
		roomList.clear();
	}
}

void House::print_out(int c) {
	if (c != 1) {
		std::cout << "----------------------------------------------------------------\n";
		std::cout << "\t\tPrinting " << h_name << std::endl;
		std::cout << "----------------------------------------------------------------\n";
	}
	for (int i = 0; i < roomList.size(); i++) {
		std::cout << "                   Room: " << roomList[i]->r_get_name() << std::endl;
		std::cout << "----------------------------------------------------------------\n";
		for (Person* pers : person_list)
		{
			if (pers->get_room() == roomList[i])
			{
				std::cout << "  ";
				pers->print();
			}
		}
		roomList[i]->print_door(0);
		roomList[i]->print_light(0);
		roomList[i]->print_heater(0);
		roomList[i]->print_coffee(0);
		std::cout << "----------------------------------------------------------------\n";
	}

}

Room* House::get_room(int a)
{
	return roomList[a];
}

void House::all_instruments(int house_c){
	char c;
	int choice = 0;
	std::string type;
	Position p = Position::Off;
	if (house_c != 1) {
		std::cout << "----------------------------------------------------------------\n";
		std::cout << "Press '1' to OPEN/CLOSE all doors\n";
		std::cout << "Press '2' to turn all lights ON/OFF\n";
		std::cout << "Press '3' to turn all heater ON/OFF\n";
		std::cout << "Press '4' to turn all coffee machines ON/OFF\n";
		std::cout << "Press '5' to turn all instruments ON/OFF\n";
		std::cout << "----------------------------------------------------------------\n";
		std::cin >> choice;
		print_inst_type(choice, type);
	}
	else if (house_c == 1) {
		type = "instrument";
		choice = 5;
	}
	std::cout << "----------------------------------------------------------------\n";
	std::cout << "Do you want to turn all " << type << "s ON or OFF(Y = On, N = Off)\n";
	std::cout << "----------------------------------------------------------------\n";
	std::cin >> c;
	if (c == 'y' || c == 'Y') {
		p = Position::On;
	}
	else if (c == 'n' || c == 'N') {
		p = Position::Off;
	}
	else { std::cout << "Invalid input...\n"; }
	if (choice > 0 && choice < 6){
		for (int i = 0; i < roomList.size(); i++) {
			roomList[i]->turn_instruments(choice, p);
		}
	}
	else { std::cout << "Invalid input...\n"; }
}
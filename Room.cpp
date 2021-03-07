#include "Room.h"

void space_management(int size) {
    for (int i = 0; i < 20 - size; i++)
    {
        std::cout << " ";
    }
}

void Room::print_room() {
    Door* d_temp = nullptr;
    Light* l_temp = nullptr;
    Heater* h_temp = nullptr;
    Coffee_Machine* c_temp = nullptr;
    bool digital_pos;
    int analog_pos;
    std::string temp_n = "NA";
    std::cout << "---------------------------------------------\n";
    std::cout << "                  Doors\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < doorList.size(); i++) {
        digital_pos = doorList[i]->get_pos();
        temp_n = doorList[i]->get_name();
        std::cout << "Name: " << temp_n;
        space_management(temp_n.size());
        std::cout << "Position: " << (digital_pos == true ? "Open" : "Closed") << "\n";
    }
    std::cout << "---------------------------------------------\n";
    std::cout << "                  Lights\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < lightList.size(); i++) {
        analog_pos = lightList[i]->l_get_status();
        digital_pos = lightList[i]->get_pos();
        temp_n = lightList[i]->get_name();
        std::cout << "Name: " << temp_n;
        space_management(temp_n.size());
        std::cout << "Currently: " << (digital_pos == true ? "On" : "Off");
        std::cout << ", " << analog_pos << " \%\n";
    }
    std::cout << "---------------------------------------------\n";
    std::cout << "               Coffee Machine\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < coffeeList.size(); i++) {
        analog_pos = coffeeList[i]->c_get_status();
        digital_pos = coffeeList[i]->get_pos();
        temp_n = coffeeList[i]->get_name();
        std::cout << "Name: " << temp_n;
        space_management(temp_n.size());
        std::cout << "Currently: " << (digital_pos == true ? "On" : "Off");
        std::cout << ", " << coffeeList[i]->c_get_status() << " \%\n";
    }
}

void Room::add_instrument(int id, int i_val) {
    if (i_val == 1)
    {
        add_door(id);
    }
    else if (i_val == 2)
    {
        add_light(id);
    }
    else if (i_val == 3)
    {
        add_heater(id);
    }
    else if (i_val == 4)
    {
        add_coffee(id);
    }
}

void Room::add_door(int id) {
    std::string name;
    char door;
    Position d_st;
    std::cout << "Adding a door...\n";
    std::cout << "Add a name: ";
    std::cin >> name;
    std::cout << "Is the door open? (Y/N) ";
    std::cin >> door;
    if (door == 'Y' || door == 'y')
    {
        d_st = Position::On;
    }
    else
    {
        d_st = Position::Off;
    }
    Door* new_d = new Door(name, id, d_st);
    doorList.push_back(new_d);
    new_d->print_out();
}

void Room::add_light(int id) {
    std::string name;
    int val = 0;
    char c2;
    bool digital;
    std::cout << "Adding a light...\n";
    std::cout << "Add a name: ";
    std::cin >> name;
    std::cout << "Is the light dimmable? (Y/N) ";
    std::cin >> c2;
    if (c2 == 'Y' || c2 == 'y') {
        digital = false;
        std::cout << "At what \% is the light currently? ";
        std::cin >> c2;
        val = (int)c2;
    }
    else if (c2 == 'N' || c2 == 'n') {
        digital = true;
        std::cout << "Is the light on or off (Y = on, N = off) ";
        std::cin >> c2;
        if (c2 == 'Y' || c2 == 'y')
        {
            val = 100;
        }
        else
        {
            val = 0;
        }
    }
    Light* new_l = new Light(name, id, val, ((c2 == 'Y' || c2 == 'y') ? Position::On : Position::Off), digital);
    lightList.push_back(new_l);
    new_l->print_out();
}

void Room::add_coffee(int id) {
    std::string name;
    Position onOff;
    bool daily;
    int val = 0;
    int time = 0;
    char c;
    std::cout << "Adding a Coffee machine...\n";
    std::cout << "Add a name: ";
    std::cin >> name;
    std::cout << "Set a daily coffeetime: (0 - 24) ";
    std::cin >> c;
    time = (int)c;
    std::cout << "How many cups of coffe do you wish to make? (1 - 10) ";
    std::cin >> c;
    val = (int)c;
    std::cout << "Do you wish to turn on daily coffeetime? (Y/N) ";
    std::cin >> c;
    if (c == 'Y' || c == 'y')
    {
        daily = true;
    }
    else if (c == 'N' || c == 'n')
    {
        daily = false;
    }
    std::cout << "Is the machine currently on? (Y/N) ";
    std::cin >> c;
    if (c == 'Y' || c == 'y')
    {
        onOff = Position::On;
    }
    else if (c == 'N' || c == 'n')
    {
        onOff = Position::Off;
    }
    Coffee_Machine* new_c = new Coffee_Machine(name, id, val, onOff, time, daily);
    coffeeList.push_back(new_c);
    new_c->print_out();
}

void Room::add_heater(int id) {
    std::string name;
    int val;
    Position onOff;
    char c;
    std::cout << "Adding a heater...\n";
    std::cout << "Add a name: ";
    std::cin >> name;
    std::cout << "Set temperature: ";
    std::cin >> val;
    std::cout << "Set heater on or off: (Y/N) ";
    std::cin >> c;
    if (c == 'Y' || c == 'y')
    {
        onOff = Position::On;
    }
    else if (c == 'N' || c == 'n')
    {
        onOff = Position::Off;
    }
    Heater* new_l = new Heater(name, id, val, onOff);
    heaterList.push_back(new_l);
}

void Room::quick_door(std::string name, int id, Position openClosed) {
    Door* new_d = new Door(name, id, openClosed);
    doorList.push_back(new_d);
}
void Room::quick_light(std::string name, int id, int val, Position onOff, bool dig) {
    Light* new_l = new Light(name, id, val, onOff, dig);
    lightList.push_back(new_l);
}

void Room::quick_coffee(std::string name, int id, int val, Position onOff, int time, bool daily) {
    Coffee_Machine* new_c = new Coffee_Machine(name, id, val, onOff, time, daily);
    coffeeList.push_back(new_c);
}

void Room::quick_heater(std::string name, int id, int val, Position onOff) {
    Heater* new_l = new Heater(name, id, val, onOff);
    heaterList.push_back(new_l);
}

void Room::quick_start() {
    std::cout << "Adding 4 doors, 4 lights, coffe machine and 2 heaters...\n";
    quick_door("Hoved", 1, Position::On);
    quick_door("Side", 2, Position::Off);
    quick_door("Bak", 3, Position::Off);
    quick_door("Skap", 4, Position::On);
    quick_light("Tak", 5, 13, Position::On, true);
    quick_light("Vegg", 6, 17, Position::Off, false);
    quick_light("Bord", 7, 25, Position::Off, true);
    quick_light("Gulv", 8, 90, Position::On, false);
    quick_coffee("Mocca", 9, 4, Position::On, 8, true);
    quick_heater("Radiator", 10, 25, Position::On);
    quick_heater("Varmekabler", 11, 32, Position::Off);
}
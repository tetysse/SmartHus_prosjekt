#include "Room.h"

void n_space_management(int size) {
    for (int i = 0; i < 12 - size; i++)
    {   std::cout << " ";  }
}

void Room::print_door(int header) {
    bool digital_pos;
    std::string temp_n = "NA";
    if (header == 1) {
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                          Doors\n";
        std::cout << "----------------------------------------------------------------\n";
    }
    else { std::cout << "DOORS:\n"; }
    for (int i = 0; i < doorList.size(); i++) {
        digital_pos = doorList[i]->get_pos();
        temp_n = doorList[i]->get_name();
        std::cout << i+1 << ": Name: " << temp_n;
        n_space_management(temp_n.size());
        std::cout << "Position: " << (digital_pos == true ? "Open" : "Closed") << "\n";
    }
    if (doorList.size() == 0) {
        std::cout << "There are no doors configured in this room!\n";
    }
}

void Room::print_light(int header) {
    bool digital_pos = false;
    int analog_pos = 0;
    std::string temp_n = "NA";
    if (header == 1) {
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                          Lights\n";
        std::cout << "----------------------------------------------------------------\n";
    }
    else { std::cout << "LIGHTS:\n"; }
    for (int i = 0; i < lightList.size(); i++) {
        if (lightList[i] != NULL)
        analog_pos = lightList[i]->l_get_status();
        digital_pos = lightList[i]->get_pos();
        temp_n = lightList[i]->get_name();
        std::cout << i+1 << ": Name: " << temp_n;
        n_space_management(temp_n.size());
        std::cout << "Status: " << (digital_pos == true ? "On" : "Off");
        if (digital_pos == true) { std::cout << ",  "; }
        else { std::cout << ", "; }
        std::cout << "Set point: " << analog_pos << " \%\n";
    }
    if (lightList.size() == 0) {
        std::cout << "There are no lights configured in this room!\n";
    }
}

void Room::print_heater(int header) {
    bool digital_pos;
    int analog_pos;
    std::string temp_n = "NA";
    if (header == 1) {
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                          Heaters\n";
        std::cout << "----------------------------------------------------------------\n";
    }
    else
    {   std::cout << "HEATERS:\n";   }
    for (int i = 0; i < heaterList.size(); i++) {
        analog_pos = heaterList[i]->get_temperature();
        digital_pos = heaterList[i]->get_pos();
        temp_n = heaterList[i]->get_name();
        std::cout << i+1 << ": Name: " << temp_n;
        n_space_management(temp_n.size());
        std::cout << "Currently: " << (digital_pos == true ? "On" : "Off");
        if (digital_pos == true) { std::cout << ",  "; }
        else { std::cout << ", "; }
        std::cout << " Set point: " << analog_pos << " \370C\n";
    }
    if (heaterList.size() == 0) {
        std::cout << "There are no heaters configured in this room!\n";
    }
}

void Room::print_coffee(int header) {
    bool digital_pos;
    int analog_pos;
    std::string temp_n = "NA";
    if (header == 1) {
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                          Coffee Machine\n";
        std::cout << "----------------------------------------------------------------\n";
    }
    else { std::cout << "COFFEE MACHINE:\n"; }
    for (int i = 0; i < coffeeList.size(); i++) {
        analog_pos = coffeeList[i]->c_get_status();
        digital_pos = coffeeList[i]->get_pos();
        temp_n = coffeeList[i]->get_name();
        std::cout << i+1 << ": Name: " << temp_n;
        n_space_management(temp_n.size());
        std::cout << "Currently: " << (digital_pos == true ? "On" : "Off");
        if (digital_pos == true) { std::cout << ",  "; }
        else { std::cout << ", "; }
        digital_pos = coffeeList[i]->c_get_daily();
        std::cout << " Cups: " << analog_pos << ", ";
        if (analog_pos > 9) { std::cout << " "; }
        analog_pos = coffeeList[i]->c_get_time();
        if (digital_pos == true)
        {
            std::cout << "Coffeetime: ";
            if (analog_pos < 10) { std::cout << "0"; }
            std::cout << analog_pos << ":00" << std::endl;
        }
        else { std::cout << "Coffeetime not active\n"; }
    }
    if (coffeeList.size() == 0) {
        std::cout << "There are no coffee machines configured in this room!\n";
    }
}

void Room::print_room(int header) {
    if (header == 1) {
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                   Room: " << r_name << "\n";
        std::cout << "----------------------------------------------------------------\n";
    }
    else { std::cout << "Room: " << r_name << std::endl; }
    print_door(header);
    print_light(header);
    print_heater(header);
    print_coffee(header);
}

void Room::add_instrument(int id, int i_val) {
    if (i_val == 1)
    {   add_door(id);    }
    else if (i_val == 2)
    {   add_light(id);   }
    else if (i_val == 3)
    {   add_heater(id);  }
    else if (i_val == 4)
    {   add_coffee(id);  }
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
    {   d_st = Position::On;  }
    else
    {   d_st = Position::Off; }
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
        {   val = 100;   }
        else
        {   val = 0;     }
    }
    Light* new_l = new Light(name, id, val, ((c2 == 'Y' || c2 == 'y') ? Position::On : Position::Off), digital);
    lightList.push_back(new_l);
    new_l->print_out();
}

void Room::add_coffee(int id) {
    std::string name;
    Position onOff = Position::Off;
    bool daily = false;
    int val = 0;
    int time = 0;
    char c;
    std::cout << "Adding a Coffee machine...\n";
    std::cout << "Add a name: ";
    std::cin >> name;
    std::cout << "Set a daily coffeetime: (0 - 24) ";
    std::cin >> time;
    if (time > 24 || time < 0) { time = 8; }
    std::cout << "How many cups of coffe do you wish to make? (1 - 10) ";
    std::cin >> val;
    if (val > 10) { val = 10; }
    else if (val < 0) { val = 0; }
    std::cout << "Do you wish to turn on daily coffeetime? (Y/N) ";
    std::cin >> c;
    if (c == 'Y' || c == 'y')
    {    daily = true;    }
    else if (c == 'N' || c == 'n')
    {    daily = false;   }
    std::cout << "Is the machine currently on? (Y/N) ";
    std::cin >> c;
    if (c == 'Y' || c == 'y')
    {    onOff = Position::On;  }
    else if (c == 'N' || c == 'n')
    {    onOff = Position::Off; }
    Coffee_Machine* new_c = new Coffee_Machine(name, id, val, onOff, time, daily);
    coffeeList.push_back(new_c);
    new_c->print_out();
}

void Room::add_heater(int id) {
    std::string name;
    int val;
    Position onOff = Position::Off;
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

void Room::delete_door() {
    int c;
    int size = doorList.size();
    print_door(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to remove a door\n";
        std::cout << "Press \'" << size + 1 << "\' to remove all\n";
        std::cout << "Press \'0\' to go back to the menu\n";
        std::cin >> c;
        if (c != size + 1) {
            for (int i = 0; i < size; i++) {
                if (c == i + 1) {
                    doorList[i]->~Door();
                    doorList.erase(doorList.begin() + i);
                }
            }
        }
        else if (c == size + 1) {
            for (int i = 0; i < doorList.size(); i++)
            {
                doorList[i]->~Door();
            }
            doorList.clear();
        }
    }
}


void Room::delete_light() {
    int c;
    int size = lightList.size();
    print_light(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to remove a light\n";
        std::cout << "Press \'" << size + 1 << "\' to remove all\n";
        std::cout << "Press \'0\' to go back to the menu\n";
        std::cin >> c;
        if (c != size + 1) {
            for (int i = 0; i < size; i++) {
                if (c == i + 1) {
                    lightList[i]->~Light();
                    lightList.erase(lightList.begin() + i);
                }
            }
        }
        else if (c == size + 1) {
            for (int i = 0; i < lightList.size(); i++) 
            {   lightList[i]->~Light(); }
            lightList.clear();
        }
    }
}

void Room::delete_heater() {
    int c;
    int size = heaterList.size();
    print_heater(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to remove a heater\n";
        std::cout << "Press \'" << size + 1 << "\' to remove all\n";
        std::cout << "Press \'0\' to go back to the menu\n";
        std::cin >> c;
        if (c != size + 1) {
            for (int i = 0; i < size; i++) {
                if (c == i + 1) {
                    heaterList[i]->~Heater();
                    heaterList.erase(heaterList.begin() + i);
                }
            }
        }
        else if (c == size + 1) {
            for (int i = 0; i < heaterList.size(); i++)
            {
                heaterList[i]->~Heater();
            }
            heaterList.clear();
        }
    }
}

void Room::delete_coffee() {
    int c;
    int size = coffeeList.size();
    print_coffee(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to remove a coffee machine\n";
        std::cout << "Press \'" << size + 1 << "\' to remove all\n";
        std::cout << "Press \'0\' to go back to the menu\n";
        std::cin >> c;
        if (c != size + 1) {
            for (int i = 0; i < size; i++) {
                if (c == i + 1) {
                    coffeeList[i]->~Coffee_Machine();
                    coffeeList.erase(coffeeList.begin() + i);
                }
            }
        }
        else if (c == size + 1) {
            for (int i = 0; i < coffeeList.size(); i++)
            {
                coffeeList[i]->~Coffee_Machine();
            }
            coffeeList.clear();
        }
    }
}

void Room::configure_door() {
    int c;
    char  c2;
    int size = doorList.size();
    std::cout << "configure door...\n";
    print_door(1);
    std::cout << "Press 1 - " << size << " to configure a door\n";
    std::cout << "Press '0' to go back to the menu\n";
    std::cin >> c;
    std::cout << "Do you wish to change doorname? (Y/N) ";
    std::cin >> c2;
    if (c2 == 'y' || c2 == 'Y') {
        std::cout << "Set new name: ";

    }
    doorList[c]->set_pos();

}

void Room::configure_light() {
    std::cout << "configure light\n";
}

void Room::configure_heater() {
    std::cout << "configure heater\n";
}

void Room::configure_coffee() {
    std::cout << "configure coffee\n";
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
    quick_door("Hoved", 1,      Position::On );
    quick_door("Side",  2,      Position::Off);
    quick_door("Bak",   3,      Position::Off);
    quick_door("Skap",  4,      Position::On );
    quick_light("Tak",  5, 13,  Position::On,  true  );
    quick_light("Vegg", 6, 17,  Position::Off, false );
    quick_light("Bord", 7, 25,  Position::Off, true  );
    quick_light("Gulv", 8, 90,  Position::On,  false );
    quick_coffee("Mocca", 9, 4, Position::On, 8, true);
    quick_heater("Radiator", 10, 25, Position::On    );
    quick_heater("Varmekabler", 11, 32, Position::Off);
}
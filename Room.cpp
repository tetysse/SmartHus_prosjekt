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
        if (lightList[i]->l_get_dig() == true) {
            std::cout << "Light is not dimmable\n";
        }
        else {
            std::cout << "Set point: " << analog_pos << " \%\n";
        }
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

void Room::delete_door(int choice) {
    int c;
    int size = doorList.size();
    print_door(1);
    if (size > 0) {
        if (choice != 1) {
            std::cout << "Press 1 - " << size << " to remove a door\n";
            std::cout << "Press '0' to go back to the menu\n";
            std::cin >> c;
            if (c != size + 1) {
                for (int i = 0; i < size; i++) {
                    if (c == i + 1) {
                        doorList[i]->~Door();
                        doorList.erase(doorList.begin() + i);
                    }
                }
            }
        }
        if (choice == 1 || c == size + 1) {
            for (int i = 0; i < doorList.size(); i++)
            {
                doorList[i]->~Door();
            }
            doorList.clear();
            std::cout << "Removing all the doors...\n";
        }
    }
}


void Room::delete_light(int choice) {
    int c;
    int size = lightList.size();
    print_light(1);
    if (size > 0) {
        if (choice != 1) {
            std::cout << "Press 1 - " << size << " to remove a light\n";
            std::cout << "Press '0' to go back to the menu\n";
            std::cin >> c;
            if (c != size + 1 && choice != 1) {
                for (int i = 0; i < size; i++) {
                    if (c == i + 1) {
                        lightList[i]->~Light();
                        lightList.erase(lightList.begin() + i);
                    }
                }
            }
        }
        if (choice == 1 || c == size + 1) {
            for (int i = 0; i < lightList.size(); i++) 
            {   lightList[i]->~Light(); }
            lightList.clear();
            std::cout << "Removing all the lights...\n";
        }
    }
}

void Room::delete_heater(int choice) {
    int c;
    int size = heaterList.size();
    print_heater(1);
    if (size > 0) {
        if (choice != 1) {
            std::cout << "Press 1 - " << size << " to remove a heater\n";
            std::cout << "Press '0' to go back to the menu\n";
            std::cin >> c;
            if (c != size + 1) {
                for (int i = 0; i < size; i++) {
                    if (c == i + 1) {
                        heaterList[i]->~Heater();
                        heaterList.erase(heaterList.begin() + i);
                    }
                }
            }
        }
        else if (choice == 1 || c == size + 1) {
            for (int i = 0; i < heaterList.size(); i++)
            {
                heaterList[i]->~Heater();
            }
            heaterList.clear();
            std::cout << "Removing all the heaters...\n";
        }
    }
}

void Room::delete_coffee(int choice) {
    int c;
    int size = coffeeList.size();
    print_coffee(1);
    if (size > 0) {
        if (choice != 1) {
            std::cout << "Press 1 - " << size << " to remove a coffee machine\n";
            std::cout << "Press '0' to go back to the menu\n";
            std::cin >> c;
            if (c != size + 1) {
                for (int i = 0; i < size; i++) {
                    if (c == i + 1) {
                        coffeeList[i]->~Coffee_Machine();
                        coffeeList.erase(coffeeList.begin() + i);
                    }
                }
            }
        }
        else if (choice == 1) {
            for (int i = 0; i < coffeeList.size(); i++)
            {
                coffeeList[i]->~Coffee_Machine();
            }
            coffeeList.clear();
            std::cout << "Removing all the coffee machines...\n";
        }
    }
}

void Room::configure_door(int choice) {
    int c;
    int c2;
    char c3;
    std::string n_name;
    int size = doorList.size();
    std::cout << "configure door...\n";
    print_door(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to configure a door\n";
        std::cout << "Press '0' to go back to the menu\n";
        std::cin >> c;
        if (c != 0) {
            std::cout << "Press '1' for name change on " << doorList[c - 1]->get_name() << std::endl;
            std::cout << "Press '2' to change door position, Currently: " << (doorList[c - 1]->get_pos() == true ? "Open" : "Closed") << std::endl;
            std::cout << "Press '3' for both options\n";
            std::cout << "Press '0' to return to main menu\n";
            std::cin >> c2;
            if (c2 == 1 || c2 == 3) {
                std::cout << "Set new name: ";
                std::cin >> n_name;
                doorList[c - 1]->set_name(n_name);
            }
            if (c2 == 2 || c2 == 3) {
                std::cout << "Set Position ('Y' = Open \/ 'N' = Closed): ";
                std::cin >> c3;
                if (c3 == 'Y' || c3 == 'y') {
                    doorList[c - 1]->set_pos(Position::On);
                }
                else if (c3 == 'N' || c3 == 'n') {
                    doorList[c - 1]->set_pos(Position::Off);
                }
                else
                {
                    std::cout << "Invalid input, no change in position\n";
                }
                doorList[c - 1]->print_out();
            }
        }
    }
}

void Room::configure_light(int choice) {
    std::cout << "configure light...\n";
    int c;
    int c2;
    char c3;
    int c4;
    std::string n_name;
    int size = lightList.size();
    print_light(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to configure a light\n";
        std::cout << "Press '0' to go back to main menu\n";
        std::cin >> c;
        if (c != 0) {
            std::cout << "Press '1' for name change on " << lightList[c - 1]->get_name() << std::endl;
            std::cout << "Press '2' to change light status, Currently: " << (lightList[c - 1]->get_pos() == true ? "On" : "Off") << std::endl;
            std::cout << "Press '3' to change dimming percentage\n";
            if (lightList[c - 1]->l_get_dig() == true) {
                std::cout << "--- This light is not dimmable ---\n";
            }
            std::cout << "Press '4' for all options\n";
            std::cout << "Press '0' to return to main menu\n";
            std::cin >> c2;
            if (c2 == 1 || c2 == 4) {
                std::cout << "Set new name: ";
                std::cin >> n_name;
                lightList[c - 1]->set_name(n_name);
            }
            if (c2 == 2 || c2 == 4) {
                std::cout << "Set position ('Y' = On \/ 'N' = Off): ";
                std::cin >> c3;
                if (c3 == 'Y' || c3 == 'y') {
                    lightList[c - 1]->set_pos(Position::On);
                }
                else if (c3 == 'N' || c3 == 'n') {
                    lightList[c - 1]->set_pos(Position::Off);
                }
                else
                {
                    std::cout << "Invalid input, no change in status\n";
                }
            }
            if ((c2 == 3 || c2 == 4) && !lightList[c - 1]->l_get_dig()) {
                std::cout << "Set new dimming percentage: ";
                std::cin >> c4;
                lightList[c - 1]->l_set_val(c4);
            }
            lightList[c - 1]->print_out();
        }
    }
}

void Room::configure_heater(int choice) {
    std::cout << "configure heater...\n";
    int c;
    int c2;
    char c3;
    int c4;
    std::string n_name;
    int size = heaterList.size();
    print_heater(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to configure a heater\n";
        std::cout << "Press '0' to go back to main menu\n";
        std::cin >> c;
        if (c != 0) {
            std::cout << "Press '1' for name change on " << heaterList[c - 1]->get_name() << std::endl;
            std::cout << "Press '2' to change heater status, Currently: " << (heaterList[c - 1]->get_pos() == true ? "On" : "Off") << std::endl;
            std::cout << "Press '3' to change temperature (\370C)\n";
            std::cout << "Press '4' for all options\n";
            std::cout << "Press '0' else to return to main menu\n";
            std::cin >> c2;
            if (c2 == 1 || c2 == 4) {
                std::cout << "Set new name: ";
                std::cin >> n_name;
                heaterList[c - 1]->set_name(n_name);
            }
            if (c2 == 2 || c2 == 4) {
                std::cout << "Set position ('Y' = On \/ 'N' = Off): ";
                std::cin >> c3;
                if (c3 == 'Y' || c3 == 'y') {
                    heaterList[c - 1]->set_pos(Position::On);
                }
                else if (c3 == 'N' || c3 == 'n') {
                    heaterList[c - 1]->set_pos(Position::Off);
                }
                else
                {
                    std::cout << "Invalid input, no change in status\n";
                }
            }
            if (c2 == 3 || c2 == 4) {
                std::cout << "Set new temperature (\370C): ";
                std::cin >> c4;
                heaterList[c - 1]->set_temperature(c4);
            }
            heaterList[c - 1]->print_out();
        }
    }
}

void Room::configure_coffee(int choice) {
    std::cout << "configure coffee...\n";
    int c;
    int c2;
    char c3;
    int c4;
    char c5;
    int c6;
    std::string n_name;
    int size = coffeeList.size();
    print_coffee(1);
    if (size > 0) {
        std::cout << "Press 1 - " << size << " to configure a coffee machine\n";
        std::cout << "Press '0' to go back to main menu\n";
        std::cin >> c;
        if (c != 0) {
            std::cout << "Press '1' for name change on " << coffeeList[c - 1]->get_name() << std::endl;
            std::cout << "Press '2' to change coffee machine status, Currently: " << (coffeeList[c - 1]->get_pos() == true ? "On" : "Off") << std::endl;
            std::cout << "Press '3' to change the amount of cups of coffee\n";
            std::cout << "Press '4' change status of daily coffee time, Currently: " << (coffeeList[c - 1]->c_get_daily() ? "On" : "Off") << "\n";
            std::cout << "Press '5' to change coffe time\n";
            std::cout << "Press '6' for all options\n";
            std::cout << "Press '0' else to return to main menu\n";
            std::cin >> c2;
            if (c2 == 1 || c2 == 6) {
                std::cout << "Set new name: ";
                std::cin >> n_name;
                coffeeList[c - 1]->set_name(n_name);
            }
            if (c2 == 2 || c2 == 6) {
                std::cout << "Set position ('Y' = On \/ 'N' = Off): ";
                std::cin >> c3;
                if (c3 == 'Y' || c3 == 'y') {
                    coffeeList[c - 1]->set_pos(Position::On);
                }
                else if (c3 == 'N' || c3 == 'n') {
                    coffeeList[c - 1]->set_pos(Position::Off);
                }
                else
                {   std::cout << "Invalid input, no change in status\n";  }
            }
            if (c2 == 3 || c2 == 6) {
                std::cout << "Set new amount of cups: ";
                std::cin >> c4;
                coffeeList[c - 1]->c_set_val(c4);
            }
            if (c2 == 4 || c2 == 6) {
                std::cout << "Set daily coffe  ('Y' = On \/ 'N' = Off): ";
                std::cin >> c5;
                if (c5 == 'Y' || c5 == 'y') {
                    coffeeList[c - 1]->c_set_daily(true);
                }
                else if (c5 == 'N' || c5 == 'n') {
                    coffeeList[c - 1]->c_set_daily(false);
                }
            }
            if (c2 == 5 || c2 == 6) {
                std::cout << "Set new time for daily coffee: ";
                std::cin >> c6;
                coffeeList[c - 1]->set_coffe_time(c6);
            }
            coffeeList[c - 1]->print_out();
        }
    }
    else { std::cout << "There are no coffe machines in this room!\n"; }
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
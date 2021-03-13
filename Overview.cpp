#include "Overview.h"

void Overview::add_house() {
    std::string name;
    std::string adr_no;
    int id = houseList.size() * 200;
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Adding a house...\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "add an address to the house: ";
    std::cin >> name;
    std::cout << "Add a house number: ";
    std::cin >> adr_no;
    name = name + " " + adr_no;
    std::cout << std::endl;
    House* new_h = new House(name, id);
    houseList.push_back(new_h);
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "                   Houselist:\n";
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < houseList.size(); i++) {
        name = houseList[i]->h_get_name();
        std::cout << "House " << i + 1 << ": " << name << std::endl;
    }
    std::cout << "----------------------------------------------------------------\n";
}

void Overview::remove_house() {
    int c;
    int size = houseList.size();
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Removing a house...\n";
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        std::cout << "House " << i + 1 << ": " << houseList[i]->h_get_name() << std::endl;
    }
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Choice the number of the house you want to remove (1-" << size + 1 << ")\n";
    std::cout << "Or press '0' to return to main menu\n";
    std::cin >> c;
    if (c != 0) {
        houseList[c - 1]->remove_room(1);
        houseList[c - 1]->~House();
        houseList.erase(houseList.begin() + c - 1);
    }
}

void Overview::configure_house() {
    int val;
    int c;
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < houseList.size(); i++) {
        std::cout << "Press '" << i + 1 << "' to select " << houseList[i]->h_get_name() << std::endl;
    }
    std::cout << "Press '0' to return to overview menu\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
    if (c != 0  || c > houseList.size() + 1) {
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "Press '1' to add a room to the house\n";
        std::cout << "Press '2' to add/remove or change an instrument\n";
        std::cout << "Press '3' remove a room\n";
        std::cout << "Press '4' to turn all instruments ON/OFF\n";
        std::cout << "Press '9' to print info about the house\n";
        std::cout << "Press '0' to return to overview menu\n";
        std::cout << "----------------------------------------------------------------\n";
        std::cin >> val;
        if (val > 0 && val < 5) {
            if (val == 1) {
                houseList[c - 1]->add_room();
            }
            else if (val == 2) {
                houseList[c - 1]->configure_room();

            }
            else if (val == 3) {
                houseList[c - 1]->remove_room(0);
            }
            else if (val == 4) {
                houseList[c - 1]->all_instruments(0);
            }
        }
        else if (val == 9) {
            houseList[c - 1]->print_out(0);
        }
    }
}

void Overview::change_address() {
    std::string name;
    int c;
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Changing address...\n";
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < houseList.size(); i++) {
        std::cout << "House :" << i + 1 << " - " << houseList[i]->h_get_name() << std::endl;
    }
    std::cout << "Choose which house to change address on: (1 - " << houseList.size() + 1 << ": ";
    std::cin >> c;
    std::cout << "Add a new address: ";
    std::cin >> name;
    houseList[c - 1]->h_set_name(name);
}

void Overview::print_houses() {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "                   - PRINTING ALL HOUSES -\n";
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < houseList.size(); i++) {
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "                   House: " << houseList[i]->h_get_name() << std::endl;
        std::cout << "----------------------------------------------------------------\n";
        houseList[i]->print_out(1);
    }
    std::cout << "----------------------------------------------------------------\n";
}
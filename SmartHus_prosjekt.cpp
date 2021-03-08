// SmartHus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Room.h"
#include "Instrument.h"
#include "Coffee_Machine.h"
#include "Heater.h"
#include "Door.h"
#include "Light.h"

void house_menu() {

}

void room_menu(int& c) {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Press '1' to add a DOOR to the room\n";
    std::cout << "Press '2' to add a LIGHT to the room\n";
    std::cout << "Press '3' to add a heater to the room\n";
    std::cout << "Press '4' to add a coffemachine to the room\n";
    std::cout << "Press '5' to remove an instrument from the room\n";
    std::cout << "Press '6' to reconfigure an instrument\n";
    std::cout << "Press '7' to return to House menu\n";
    std::cout << "Press '8' to print all the instruments in the house\n";
    std::cout << "Press '9' to print all instruments in the room\n";
    std::cout << "Press '0' to close the program\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
}

void remove_instrument_menu(int& c) {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Press '1' to remove a DOOR\n";
    std::cout << "Press '2' to remove a LIGHT\n";
    std::cout << "Press '3' to remove a HEATER\n";
    std::cout << "Press '4' to remove a COFFEE MACHINE\n";
    std::cout << "Press '9' to go back to room menu\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
}

void config_menu(int& c) {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Press '1' to recofigure a DOOR\n";
    std::cout << "Press '2' to recofigure a LIGHT\n";
    std::cout << "Press '3' to recofigure a HEATER\n";
    std::cout << "Press '4' to recofigure a COFFEE MACHINE\n";
    std::cout << "Press '9' to go back to room menu\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
}
int main()
{
    bool run = true;
    Room *  new_r = new Room("Stue", 1000);
    std::cout << "Adding a room...\n";
    new_r->quick_start();
    int id = 20;
    int val;
    int val2 = 0;
    int val3 = 0;
    int menu = 0;
    while (run) {
        if (menu == 0) {
            std::thread t_menu(room_menu, std::ref(val));
            t_menu.join();
            if (val > 0 && val < 5) {
                new_r->add_instrument(id, val);
                id++;
            }
            else if (val == 5) {
                std::thread t_menu2(remove_instrument_menu, std::ref(val2));
                t_menu2.join();
                menu++;
            }
            else if (val == 6) {
                std::thread t_menu3(config_menu, std::ref(val3));
                t_menu3.join();
                menu++;
            }
            else if (val == 8) {
                new_r->print_room(0);
            }
            else if (val == 9) {
                new_r->print_room(1);
            }
            else if (val == 0) {
                run = false;
            }
        } 
        if (val2 != 0) {
            menu++;
            if (val2 == 1) {   
                new_r->delete_door(); 
            }
            else if (val2 == 2) {
                new_r->delete_light();
            }
            else if (val2 == 3) {
                new_r->delete_heater();
            }
            else if (val2 == 4) {
                new_r->delete_coffee();
            }
            else if (val2 == 9) {
                menu = 0;
            }
            val2 = 0;
        }
        if (val3 != 0) {
            menu++;
            if (val3 == 1) {
                new_r->configure_door();
            }
            else if (val == 2) {
                new_r->configure_light();
            }
            else if (val == 3) {
                new_r->configure_heater();
            }
            else if (val == 4) {
                new_r->delete_coffee();
            }
            else if (val3 == 9) {
                menu = 0;
            }
            val3 = 0;
        }
        else {
            menu = 0;
        }
    }
}
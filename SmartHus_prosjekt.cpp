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

void room_menu(int& c2) {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Press '1' to add a DOOR to the room\n";
    std::cout << "Press '2' to add a LIGHT to the room\n";
    std::cout << "Press '3' to add a heater to the room\n";
    std::cout << "Press '4' to add a coffemachine to the room\n";
    std::cout << "Press '9' to print all instruments in the room\n";
    std::cout << "Press '0' to close the program\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c2;
}

int main()
{
    bool run = true;
    Room new_room;
    std::cout << "Added a room...\n";
    new_room.quick_start();
    int id = 20;
    int val;
    while (run) {
        std::thread t_menu(room_menu, std::ref(val));
        t_menu.join();
        if (val > 0 && val < 5) {
            new_room.add_instrument(id, val);
            id++;
        }
        else if (val == 9) {
            new_room.print_room();
        }
        else if (val == 0) {
            run = false;
        }
    }
}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include "Overview.h"
#include "House.h"
#include "Room.h"
#include "Instrument.h"
#include "Coffee_Machine.h"
#include "Heater.h"
#include "Door.h"
#include "Light.h"

void main_menu(int& c) {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Press '1' to add a new house\n";
    std::cout << "Press '2' to configure a room or instrument in  house\n";
    std::cout << "Press '3' remove a house\n";
    std::cout << "Press '4' to rename the address of a house\n";
//    std::cout << "Press '5' to read from file\n";
//    std::cout << "Press '6' to write to file\n";
    std::cout << "Press '9' to print info about the all the houses\n";
    std::cout << "Press '0' to close the program\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
}
int main()
{
    bool run = true;
    Overview* new_o = new Overview("Supervisor");
    int val;
    int menu = 0;
    while (run) {
        if (menu == 0) {
            menu++;
            std::thread h_menu(main_menu, std::ref(val));
            h_menu.join();
            if (val > 0 && val < 5) {
                if (val == 1) {
                    new_o->add_house();
                }
                else if (val == 2) {
                    new_o->configure_house();
                }
                else if (val == 3) {
                    new_o->remove_house();
                }
                else if (val == 4) {
                    new_o->change_address();
                }
                menu = 0;
            }
            else if (val == 5) {
                // to be continued
                menu = 0;
            }
            else if (val == 6) {
                // to be continued
                menu = 0;
            }
            else if (val == 9) {
                new_o->print_houses();
                menu = 0;
            }
            else if (val == 0) {
                run = false;
            }
        }
    }
}
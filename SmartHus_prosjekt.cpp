

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <xlocmon>

#include "Overview.h"
#include "House.h"
#include "Room.h"
#include "Instrument.h"
#include "Coffee_Machine.h"
#include "Heater.h"
#include "Door.h"
#include "Light.h"

int time_ = 0;
bool run = true;
bool finished = false;
bool menu = false;

void main_menu() {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Press '1' to add a new house\n";
    std::cout << "Press '2' to configure a room or instrument in house\n";
    std::cout << "Press '3' remove a house\n";
    std::cout << "Press '4' to rename the address of a house\n";
    std::cout << "Press '5' to read from file\n";
    std::cout << "Press '6' to write to file\n";
    std::cout << "Press '7' to move a person\n";
    std::cout << "Press '8' to add a person\n";
    std::cout << "Press '9' to print info about the all the houses\n";
    std::cout << "Press '0' to close the program\n";
    std::cout << "----------------------------------------------------------------\n";
}

void doWork(Overview* new_o)
{
    menu = true;
    main_menu();
    /*std::string input;
    std::getline(std::cin, input);*/

    int val;
    std::cin >> val;

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
    else if (val == 5) {
        new_o->read_config_file();
        new_o->print_houses();
    }
    else if (val == 6) {
        new_o->saveToFile();
    }
    else if (val == 7) {
        new_o->move_person();
    }
    else if (val == 8) {
        new_o->add_person();
    }
    else if (val == 9) {
        new_o->print_houses();
    }
    else if (val == 0) {
        run = false;
        finished = true;
    }
    menu = false;
}

void waitInput()
{
    while (!finished)
    {
        while (run && !menu)
        {
            std::cin.ignore(); //dont remember the last input https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer

            char input;
            std::cin.get() >> input;
            run = false;
        }
    }
}

void simulateClock(int n, Overview* ov)
{
    if (time_ == 0)
    {
        doWork(ov);
    }
    while (time_ < 24 && !finished)
    {
        if (!run)
        {
            system("CLS"); //to clear console
            doWork(ov);
            run = true;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(n));
        
        time_++;
        std::cout << "------- Time is Now: "<< (time_ < 10 ? "0" : "") << time_ << ":00 ---------" << std::endl;
        ov->set_time(&time_);
        
    	if(time_ == 23)
    	{
            time_ = -1; // set -1 so that next time the clock is 0.
    	}
    }

}

int main()
{
    bool run = true;
    Overview* new_o = new Overview("Supervisor");
    //doWork(new_o);
    std::thread clock(simulateClock, 3000, new_o);
    std::thread waitForInput(waitInput);
    clock.join();
    finished = true;
    waitForInput.join();
	
    
}
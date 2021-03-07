#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Door.h"
#include "Light.h"
#include "Coffee_Machine.h"
#include "Heater.h"

class Room {
protected:
    std::vector<Door*> doorList;
    std::vector<Light*> lightList;
    std::vector<Heater*> heaterList;
    std::vector<Coffee_Machine*> coffeeList;

public:
    std::string r_name;
    void add_instrument(int id, int i_val);
    void add_door(int id);
    void quick_door(std::string name, int id, Position openClosed);
    void quick_light(std::string name, int id, int val, Position onOff, bool digital);
    void quick_coffee(std::string name, int id, int val, Position onOff, int time, bool daily);
    void quick_heater(std::string name, int id, int val, Position onOff);
    void add_light(int id);
    void add_coffee(int id);
    void add_heater(int id);
    void print_room();
    void quick_start();
};



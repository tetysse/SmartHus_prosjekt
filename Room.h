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
    int r_id;
    std::string r_name;
    std::vector<Door*> doorList;
    std::vector<Light*> lightList;
    std::vector<Heater*> heaterList;
    std::vector<Coffee_Machine*> coffeeList;

public:
    Room(std::string name, int id) { r_name = name, r_id = id; };
    void add_instrument(int id, int i_val);
    void add_door(int id);
    void quick_door(std::string name, int id, Position openClosed);
    void quick_light(std::string name, int id, int val, Position onOff, bool digital);
    void quick_coffee(std::string name, int id, int val, Position onOff, int time, bool daily);
    void quick_heater(std::string name, int id, int val, Position onOff);
    void delete_door(int choice);
    void delete_light(int choice);
    void delete_heater(int choice);
    void delete_coffee(int choice);
    void add_light(int id);
    void add_coffee(int id);
    void add_heater(int id);
    void print_room(int header);
    void print_door(int header);
    void print_light(int header);
    void print_coffee(int header);
    void print_heater(int header);
    void configure_door(int choice);
    void configure_light(int choice);
    void configure_heater(int choice);
    void configure_coffee(int choice);
    void quick_start();
    std::string r_get_name() { return r_name; };
    int r_get_id() { return r_id; };
};



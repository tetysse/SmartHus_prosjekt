#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include "Person.h"
#include "Room.h"

class House
{
protected:
	std::string h_name;
	int h_id;
	std::vector <Room*> roomList;
	std::vector<Person*> person_list;

public:
	House(std::string name, int id) { h_name = name, h_id = id; };
	void h_set_name(std::string name) { h_name = name; }
	std::vector<Room*> get_rooms() { return roomList; }
	std::vector<Person*>  get_persons() { return person_list; };
	void h_set_id(int id) { h_id = id; };
	void configure_room();
	void add_room();
	void remove_room(int house_c);
	void all_instruments(int house_c);
	std::string h_get_name() { return h_name; };
	int h_get_id() { return h_id; };
	int h_get_num_rooms() { return roomList.size(); };
	void print_out(int c);
	void add_room(Room* r) { roomList.push_back(r); };
	Room* get_room(int a);
	void add_person(Person* Person) {person_list.push_back(Person); };
	~House() {};
};


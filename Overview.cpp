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

void Overview::read_config_file()
{
    //Code copied from https://www.codespeedy.com/how-to-get-current-directory-in-cpp/
    const int PATH_MAX = 500;
    char buff[PATH_MAX];
    _getcwd(buff, PATH_MAX);
    std::string current_working_dir(buff);
    //std::cout << current_working_dir << std::endl;
    //std::string input = current_working_dir.substr(0, current_working_dir.find_last_of("/\\")) + "\\Input\\Config.txt";
    std::string input = current_working_dir + "\\Input\\Config.txt";
    //std::cout << input << std::endl;

	//End of copied code
	
    std::fstream newfile;

    newfile.open(input, std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {   //checking whether the file is open
        std::string line;
        while (getline(newfile, line)) { //read data from file object and put it into string.

            if (line == "House") //"House" is the condition for creating a house
            {
                getline(newfile, line); //Get next line
                int h_id = houseList.size() * 200;
                House* house = new House(line, h_id);
                houseList.push_back(house);
                getline(newfile, line); // read next line, if it is empty then this house is finished
                if (line == "" || newfile.eof())
                {
                    continue;
                }
                else
                {
                    std::vector<std::string> rooms = split(line, ";");
                    for (std::string room_string : rooms)
                    {
                        if (room_string == "") continue;

                        std::size_t pos = room_string.find('(');
                        std::size_t posend = room_string.find(')');
                        std::string RoomName = room_string.substr(0, pos);
                        std::string door = room_string.substr(pos +1, (posend - pos)-1);
                    	
                        int room_id = h_id + 200 * house->h_get_num_rooms();
						Room* room = new Room(RoomName, room_id);

                    	if(!(pos == posend))
                    	{
                            std::vector<std::string> settings = split(door, " ");
                    		
                            for (int i = 0; i < settings.size(); i+= 2)
                            {
                                room->add_door(settings[i], settings[i+1]);
                            }
                    		
                    	}
                        
                        house->add_room(room);
                    }
                    getline(newfile, line);
                    std::vector<std::string> instruments = split(line, ";");
                    for (int i = 0; i < instruments.size(); i++)
                    {
                        if (instruments[i] == "") continue;
                    	
                        add_instruments(instruments[i], house->get_room(i));
                        //house->get_rooms()[i]->add_instrument()
                    }

                }
            }

            if (line.substr(0, 6) == "Person")
            {
                std::vector<std::string> person_ = split(line, ";");
                std::vector<std::string> Person_attributes = split(person_[1], ",");
                House* house = houseList[houseList.size() - 1];
                std::vector<Room*> rooms = house->get_rooms();
                Room* room = nullptr;
                for (Room* r : rooms)
                {
                    if (r->r_get_name() == Person_attributes[3])
                    {
                        room = r;
                    }
                }
                std::string::size_type sz;   // alias of size_t
                Person* person = new Person(Person_attributes[0], house->get_persons().size() +1, std::stoi(Person_attributes[1], &sz), std::stoi(Person_attributes[2], &sz), room);
                house->add_person(person);
            }


        }
        newfile.close(); //close the file object.
    }
    else
    {
        std::cout << "Cannot find the \"Config.txt\" file" << std::endl;
    }
}

void Overview::add_instruments(std::string line, Room* room)
{
    std::vector<std::string> instruments = split(line, ",");

    for (int i = 0; i < instruments.size(); i++)
    {
        room->add_instrument(instruments[i]);
    }
}

//Split code from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> Overview::split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        //if (!token.empty())
        tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}


std::string Overview::getTypeAndValues(Instrument * instrument)
{
    if (typeid(*instrument) == typeid(Light))
    {
        Light* light = static_cast<Light*>(instrument);
        return "(Light) " + (std::to_string(light->l_get_status())) + (instrument->get_pos() == false ? " Off " : " On ") + (light->l_get_dig() == false ? "analog" : "digital");
    }
    else if (typeid(*instrument) == typeid(Heater))
    {
        Heater* heater = static_cast<Heater*>(instrument);
        return "(Heater) " + std::to_string(heater->get_temperature()) + (instrument->get_pos() == false ? " Off " : " On ");

    }
    else if (typeid(*instrument) == typeid(Coffee_Machine))
    {
        Coffee_Machine* cm = static_cast<Coffee_Machine*>(instrument);
        return "(Coffe) " + std::to_string(cm->c_get_status()) + (instrument->get_pos() == false ? " Off " : " On ") + std::to_string(cm->c_get_time()) + " " + (cm->c_get_daily() == true ? "daily" : "NA");
    }
}


void Overview::save_to_file()
{
    //Code copied from https://www.codespeedy.com/how-to-get-current-directory-in-cpp/
    const int PATH_MAX = 500;
    char buff[PATH_MAX];
    _getcwd(buff, PATH_MAX);
    std::string current_working_dir(buff);
    //std::cout << current_working_dir << std::endl;
    std::string output = current_working_dir + "\\Input\\Config.txt";
    //std::cout << input << std::endl;
    std::ofstream outputFile(output);

    // Write to the file
    for (int i = 0; i < houseList.size(); i++)
    {
        outputFile << "House\n";
        outputFile << houseList[i]->h_get_name() << "\n";
        std::string rooms = "";
        std::string instruments = "";
        for (int j = 0; j < houseList[i]->get_rooms().size(); j++)
        {
            rooms += houseList[i]->get_rooms()[j]->r_get_name();
        	if(!houseList[i]->get_rooms()[j]->get_doors().empty())
        	{
                rooms += "(";
	            for (Door* door : houseList[i]->get_rooms()[j]->get_doors())
	            {
                    rooms += door->get_name() + " " + (door->get_pos() == false ? "Off " : "On ");
	            }
                rooms = rooms.substr(0, rooms.size() - 1);
        		rooms += ")";
        	}
            rooms += ";";
            for (int k = 0; k < houseList[i]->get_rooms()[j]->get_all_instruments().size(); k++)
            {
                Instrument* instrument = houseList[i]->get_rooms()[j]->get_all_instruments()[k];
                instruments += instrument->get_name() + getTypeAndValues(instrument) + ",";
            	
            }
            instruments = instruments.substr(0, instruments.size() - 1);
            instruments += ";";
        }
        outputFile << rooms.substr(0, rooms.size() - 1) << "\n";
        outputFile << instruments.substr(0, instruments.size() - 1) << "\n";
        for (int a = 0; a < houseList[i]->get_persons().size(); a++)
        {
            Person* person = houseList[i]->get_persons()[a];
            outputFile << "Person;" << person->getPersonName() << "," << person->getPrefferedTemperature() << "," << person->getPrefferedLightStrength() << "," << person->get_room()->r_get_name() << "\n";
        }
        outputFile << "\n";
    }

    // Close the file
    outputFile.close();
}

std::vector<Coffee_Machine*> Overview::getAllCoffeMachines()
{
    std::vector<Coffee_Machine*> coffee_machines;
    for (int i = 0; i < houseList.size(); i++)
    {
        for (int j = 0; j < houseList[i]->h_get_num_rooms(); j++)
        {
            std::vector<Coffee_Machine*> cm = houseList[i]->get_room(j)->get_coffee_machines();
            coffee_machines.insert(coffee_machines.end(), cm.begin(), cm.end());
        }
    }
    return coffee_machines;
}

void Overview::set_time(int* time_)
{
    time = *time_;
    std::vector<Coffee_Machine*> coffee_machines = getAllCoffeMachines();
    for (int i = 0; i < coffee_machines.size(); i++)
    {
        if(coffee_machines[i]->c_get_time() == time)
        {
            coffee_machines[i]->set_pos(Position::On); 
            std::cout << "Coffe Machine: \"" << coffee_machines[i]->get_name() << "\" was turned on, making " << coffee_machines[i]->c_get_status() <<" cups of coffe\n";
        }else if(coffee_machines[i]->get_pos() == true)
        {
            coffee_machines[i]->set_pos(Position::Off);
            std::cout << "Coffe Machine: \"" << coffee_machines[i]->get_name() << "\" was turned off\n";
        }
    }
    //CoffeMachine* cm = static_cast<CoffeMachine*>(house_list[0]->get_rooms()[0]->get_instrument(0));
    //if (time < 10)
    //{
    //    cm->turn_on();
    //}
    //else
    //{
    //    cm->turn_off();
    //}
    //if (time > 21 || time < 8)
    //{
    //    house_list[0]->set_all_lights(10);
    //}
    //else
    //{
    //    house_list[0]->set_all_lights(70);
    //}
}

void Overview::move_person()
{
    int val, c, p, r;
    char a;
    std::cout << "First select which house:\n";
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < houseList.size(); i++) {
        std::cout << "Press '" << i + 1 << "' to select " << houseList[i]->h_get_name() << std::endl;
    }
    std::cout << "Press '0' to return to overview menu\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
    if (c != 0 || c > houseList.size() + 1) {
    	if(houseList[c - 1]->get_persons().empty())
    	{
            std::cout << "Sorry house \"" << houseList[c - 1]->h_get_name() << "\" does not have any persons"<< "\n";
            std::cout << "Do you want to add a person? (Y/N) " << "\n";
            std::cin >> a;
            if (a == 'Y' || a == 'y')
            {
                add_person(houseList[c - 1]);
            }
            else
            {
                return;
            }
            
    	}
        for (int j = 0; j < houseList[c- 1]->get_persons().size(); j++)
        {
            std::cout << "Press '" << j + 1 << "' to select " << houseList[c - 1]->get_persons()[j]->getPersonName() << std::endl;
        }
        std::cout << "----------------------------------------------------------------\n";
        std::cin >> p;
        if (p != 0 || p > houseList[c - 1]->get_persons().size() + 1)
        {
            std::cout << "Select which room to move \""<< houseList[c - 1]->get_persons()[p - 1]->getPersonName() << "\" to:\n";
            std::cout << "----------------------------------------------------------------\n";
            for (int k = 0; k < houseList[c - 1]->h_get_num_rooms(); k++) {
                Room* r = houseList[c - 1]->get_room(k);
                if (r == houseList[c - 1]->get_persons()[p - 1]->get_room()) continue;
                std::cout << "Press '" << k + 1 << "' to select " << houseList[c - 1]->get_room(k)->r_get_name() << std::endl;
            }
            std::cout << "----------------------------------------------------------------\n";
            std::cin >> r;
            if (r != 0 || r > houseList[c - 1]->h_get_num_rooms() + 1)
            {
                Move(c, p, r);
            }
        }
    }
}

void Overview::Move(int i, int j, int k)
{
    Person* person = houseList[i - 1]->get_persons()[j - 1];
    Room* room = houseList[i - 1]->get_rooms()[k - 1];
    person->Move(room);
}

void Overview::add_person()
{
    int c;
    std::cout << "First select which house:\n";
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < houseList.size(); i++) {
        std::cout << "Press '" << i + 1 << "' to select " << houseList[i]->h_get_name() << std::endl;
    }
    std::cout << "Press '0' to return to overview menu\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
    if (c != 0 || c > houseList.size() + 1) {
        add_person(houseList[c - 1]);
    }
}

void Overview::add_person(House* house)
{
    int c, t, l;
    std::string name;
    std::cout << "Select room:\n";
    std::cout << "----------------------------------------------------------------\n";
    for (int i = 0; i < house->h_get_num_rooms(); i++) {
        std::cout << "Press '" << i + 1 << "' to select " << house->get_room(i)->r_get_name() << std::endl;
    }
    std::cout << "Press '0' to return to overview menu\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cin >> c;
    if (c != 0 || c > house->h_get_num_rooms() + 1) {
        std::cout << "Add a name to the Person\n";
        std::cin >> name;
        std::cout << "What is the preffered temperature for \"" << name <<"\"\n";
        std::cin >> t;
        std::cout << "What is the preffered lightstrength for \"" << name << "\"\n";
        std::cin >> l;
        Person* p = new Person(name, house->get_persons().size() + 1, t, l, house->get_room(c-1));
        house->add_person(p);
    }
}
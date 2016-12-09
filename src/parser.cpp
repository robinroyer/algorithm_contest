#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "parser.hpp"
#include "company.hpp"
#include "table.hpp"

void parse(std::string name, std::map<int, Company*> &companies, std::vector<Table> &tables){
	
	int counter = 0;

	int forbiddenCounter = 1;
	int friendCounter = 1;
	int rivalCounter = 1;

	Company* tmp;
	Company* tmp2;

	int id;
	int id2;

	// init reading
	std::ifstream file(name);
    std::string str; 

	// get the number of table
	std::getline(file, str);
	int tableNumber = std::stoi( str );

    // create all the tables
    for (int i = 0; i < tableNumber; ++i)
    {
        tables.push_back(Table());
    }

    // get the number of company
    std::getline(file, str);
    int companyNumber = std::stoi( str );


    while (counter < companyNumber)
    {
    	std::getline(file, str);

    	tmp = new Company(counter, std::stoi( str ));

    	companies[counter] = tmp;
    	counter++;
    }

    //get number of forbidden
    std::getline(file, str);
	int forbiddenNumber = std::stoi( str );

	while (forbiddenCounter <= forbiddenNumber)
    {
    	std::getline(file, str);

    	id = std::stoi(str.substr(0, str.find(" ")));
    	id2 = std::stoi(str.substr(str.find(" "), str.size()));

        companies[id]->addForbidden(id2);
    	companies[id2]->addForbidden(id); // symetric


    	forbiddenCounter++;
    }

    //get number of friend
    std::getline(file, str);
	int friendNumber = std::stoi( str );

	while (friendCounter <= friendNumber)
    {
    	std::getline(file, str);

    	id = std::stoi(str.substr(0, str.find(" ")));
    	id2 = std::stoi(str.substr(str.find(" "), str.size()));

        companies[id]->addFriend(id2);
    	companies[id2]->addFriend(id); // symetric

    	friendCounter++;
    }

    //get number of rival
    std::getline(file, str);
	int rivalNumber = std::stoi( str );

	while (rivalCounter <= rivalNumber)
    {
    	std::getline(file, str);

    	id = std::stoi(str.substr(0, str.find(" ")));
    	id2 = std::stoi(str.substr(str.find(" "), str.size()));

        companies[id]->addRival(id2);
    	companies[id2]->addRival(id); // symetric

    	rivalCounter++;
    }
}

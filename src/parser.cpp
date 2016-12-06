#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "parser.hpp"
#include "company.hpp"
#include <map>

void parse(std::string name){
	std::cout << "hello from parser 1 : " << name << std::endl;
	
	int counter = 1;

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


	// get the number of company
	std::getline(file, str);
	int companyNumber = std::stoi( str );
	std::map<int, Company*> companies;
	
    std::cout << "il y a :" << companyNumber << " companies" << std::endl;


    while (counter <= companyNumber)
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

    	std::cout << id << " hates  " << id2 << std::endl;

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

    	std::cout << id << " loves  " << id2 << std::endl;

    	friendCounter++;
    }

 //    //get number of rival
    std::getline(file, str);
	int rivalNumber = std::stoi( str );

	while (rivalCounter <= rivalNumber)
    {
    	std::getline(file, str);

    	id = std::stoi(str.substr(0, str.find(" ")));
    	id2 = std::stoi(str.substr(str.find(" "), str.size()));

    	std::cout << id << " doesn't like  " << id2 << std::endl;
    	rivalCounter++;
    }

}

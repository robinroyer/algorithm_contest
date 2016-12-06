#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "parser.hpp"
#include "company.hpp"

void parse(std::string name){
	std::cout << "hello from parser 1 : " << name << std::endl;
	
	int counter = 0;

	int rivalNumber;
	int friendNumber;
	int forbiddenNumber;

	Company* tmp;

	// init reading
	std::ifstream file(name);
    std::string str; 

	// get the number of table
	std::getline(file, str);
	int tableNumber = std::stoi( str );


	// get the number of company
	std::getline(file, str);
	int companyNumber = std::stoi( str );
	
    std::cout << "il y a :" << companyNumber << "companies" << std::endl;

	std::vector<Company*> companies (companyNumber);

    while (std::getline(file, str))
    {
        // std::cout << str << std::endl;
        if (companyNumber >= 0)
        {
        	tmp = new Company(counter, std::stoi( str ));

        	companies.push_back(tmp);
        	counter++;
        	companyNumber--;
        }
    }

}

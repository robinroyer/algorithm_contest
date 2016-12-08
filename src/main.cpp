#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>

#include "parser.hpp"
#include "company.hpp"
#include "solution.hpp"
#include "Foncteurs.hpp"
#include "table.hpp"

int main(int argc, char* argv[])
{
	// input file
	std::string fileName = argv[1];
	// storing all the tables
	std::vector<Table> tables;
	// storing all the companies
	std::map<int, Company*> companies;
	// parse input file and create companies and tables
	parse(fileName, companies, tables);
	// tables and companies are now filled !!!



	// TODO
	// => WORK HERE


	// init une solution
	std::vector<Company*> vectCompanies;
	for (auto it = companies.begin(); it != companies.end(); ++it)
	{

		vectCompanies.push_back(it->second); // accede à la valeur
	}
	std::sort(vectCompanies.begin(), vectCompanies.end(), FoncteurCompareSizeOfEnnemies());
	Solution initSol;
	initSol.setTables(tables);
	initSol.initSol();
	initSol.printSolution();


	}
	// PANIC => we should no end as it is a time-contest
	return EXIT_SUCCESS;
}

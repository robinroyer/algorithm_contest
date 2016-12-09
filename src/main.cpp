#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <time.h>

#include "parser.hpp"
#include "company.hpp"
#include "solution.hpp"
#include "Foncteurs.hpp"
#include "table.hpp"
void recuit(Solution solution) {
	int iteration = 0;

	while (iteration <1) {
		Solution post = solution;
		int prob = rand() % 2;
		if (prob == 1) {
			solution.randomMove();
		
		}
		else {
			solution.stdMove()
		}
		iteration++;
		std::cout << solution.computeCostFunction() << " " << solution.computeCostFunction();
	}
}


int main(int argc, char* argv[])
{
	/* initialize random seed: */
	srand(time(NULL));
	// input file
	std::string fileName = argv[1];
	// storing all the tables
	std::vector<Table> tables;
	// storing all the companies
	std::map<int, Company*> companies;
	// parse input file and create companies and tables
	parse(fileName, companies, tables);
	// tables and companies are now filled !!!


	// init une solution
	std::vector<Company*> vectCompanies;
	for (auto it = companies.begin(); it != companies.end(); ++it)
	{
		vectCompanies.push_back(it->second); // accede à la valeur
	}

	std::sort(vectCompanies.begin(), vectCompanies.end(), FoncteurCompareSizeOfEnnemies());
	Solution initSol;
	initSol.setTables(tables);
	initSol.initSol(vectCompanies);
	initSol.printSolution();

	

	// test
	std::cout << "Test: le poid le solution est " << initSol.computeCostFunction() << std::endl; 

	// PANIC => we should no end as it is a time-contest
	return EXIT_SUCCESS;
}

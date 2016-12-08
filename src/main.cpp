#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parser.hpp"
#include "company.hpp"
#include <map>
#include "solution.hpp"
#include <algorithm>
#include "Foncteurs.hpp"
int main(int argc, char* argv[])
{
	std::map<int, Company*> companies = parse(argv[1]);
	return EXIT_SUCCESS;

// init une solution
	std::vector<Company*> vectCompanies;
	for (auto it = companies.begin(); it != companies.end(); ++it)
	{

		vectCompanies.push_back(it->second); // accede à la valeur
	}
	std::sort(vectCompanies.begin(), vectCompanies.end(), FoncteurCompareSizeOfEnnemies());

}

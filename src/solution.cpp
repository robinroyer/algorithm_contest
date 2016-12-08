#include <iostream>
#include "solution.hpp"

// Member functions definitions including constructor
Solution::Solution() {
	std::cout << "A solution has been created" << std::endl;
}

Solution::~Solution() {
	std::cout << "A solution has been deleted" << std::endl;
	while (tables_.size() != 0)
	{
		tables_.pop_back();
	}
}


void Solution::printSolution() {
	for (int i = 0; i < tables_.size(); i++) {
		tables_[i].printTable();
	}
	std::cout << "fin";
	}

void Solution::setTables(std::vector<Table> tables) {
	tables_ = tables;
}

void Solution::initSol(std::vector<Company*> companies) {
	int k;

	for (int j = 0; j < companies.size(); j++) {
		k = 0;
		while (!tables_[k].addCompany(companies[j])) {
			k++;
			if (k > tables_.size()) {
				std::cout << " OH SA MERE";
			}
		}
	}
}
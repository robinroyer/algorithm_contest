#include <iostream>
#include <cmath>
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
			if (k >= tables_.size()) {
				std::cout << " ... => Pas de Solution possible pour cette configuration" << std::endl;;
				break;
			}
		}
	}
}

int Solution::computeCostFunction() {
	float cost = 0.0;
	float sum = 0.0;
	float standardDeviation = 0.0;
	for (int i = 0; i < tables_.size(); i++) {
		cost += tables_[i].getWeight();
		sum += tables_[i].getCompanies().size();
	}

	float mean = sum / tables_.size();
	for (int j = 0; j < tables_.size(); j++) {
		standardDeviation+= pow(tables_[j].getCompanies().size() - mean, 2);
	}
	return cost + sqrt(standardDeviation / tables_.size());
}



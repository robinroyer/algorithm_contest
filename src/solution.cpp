#include <iostream>
#include <cmath>
#include <algorithm>

#include "solution.hpp"
#include "Foncteurs.hpp"

Solution::Solution() {}

Solution::~Solution() {
	while (tables_.size() != 0)
	{
		tables_.pop_back();
	}
}

/**
 * Display the solution
 */
void Solution::printSolution() {
	for (int i = 0; i < tables_.size(); i++) {
		tables_[i].printTable();
	}
	std::cout << "fin" << std::endl;;
}

/**
 * tables_ setter
 */
void Solution::setTables(std::vector<Table> tables) {
	tables_ = tables;
}


/**
 * Initialize solution with a dummy solution in order to iterate over it
 */
void Solution::initSol(std::vector<Company*> companies) {
	int k;

	for (int j = 0; j < companies.size(); j++) {
		k = 0;
		while (!tables_[k].addCompany(companies[j])) {
			k++;
			if (k >= tables_.size()) {
				// std::cout << " ... => Pas de Solution possible pour cette configuration" << std::endl;;
				break;
			}
		}
	}
}

/**
 * Add table weight to deviation
 */
float Solution::computeCostFunction() {
	float cost = 0.0;
	for (int i = 0; i < tables_.size(); i++)
		cost += tables_[i].getWeight();
	return cost + this->computeStandardDeviation();
}

/**
 * calculate table deviation
 */
float Solution::computeStandardDeviation() {
	float sum = 0.0;
	float standardDeviation = 0.0;
	for (int i = 0; i < tables_.size(); i++) {
		sum += tables_[i].getSize();
	}

	float mean = sum / tables_.size();
	for (int j = 0; j < tables_.size(); j++) {
		standardDeviation += pow(tables_[j].getSize() - mean, 2);
	}
	return sqrt(standardDeviation / tables_.size());
}

/**
 * Take a random Company and put it in a random Table
 */
void Solution::randomMove() {
	int id1 = rand() % tables_.size();

	while (tables_[id1].getCompanies().size() == 0) {
		id1 = rand() % tables_.size();
	}

	int companyid= rand() % tables_[id1].getCompanies().size();
	Company* comp = tables_[id1].removeCompany(tables_[id1].getCompanies()[companyid]->getId());
	int id2 = rand() % tables_.size();
	while (!tables_[id2].addCompany(comp)) {
		id2 = rand() % tables_.size();
	}
}

/**
 * Take a random Company and put it in the table with the less people that can accept him
 */
void Solution::stdMove() {
	std::sort(tables_.begin(), tables_.end(), FoncteurCompareSizeOfTables());
	int id1 = rand() % tables_.size();

	while (tables_[id1].getCompanies().size() == 0) {
		id1 = rand() % tables_.size();
	}

	int companyid = rand() % tables_[id1].getCompanies().size();
	Company* comp = tables_[id1].removeCompany(tables_[id1].getCompanies()[companyid]->getId());
	
	int k = 0;
	while (!tables_[k].addCompany(comp)) {
		k++;
	}
}

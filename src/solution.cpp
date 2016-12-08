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
		tables_[i]->printTable();
		}
	std::cout << "fin";
	}

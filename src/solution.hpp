#ifndef H_SOLUTION
#define H_SOLUTION

#include <vector>
#include "table.hpp"

class Solution {
public:
	Solution();   // This is the constructor declaration
	~Solution();  // This is the destructor: declaration
	void printSolution();
	void setTables(std::vector<Table> tables);
	void initSol(std::vector<Company*> companies);
	void randomMove();

	float computeCostFunction();
	float computeStandardDeviation();

private:
	std::vector<Table> tables_;
};

#endif

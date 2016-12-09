#ifndef H_SOLUTION
#define H_SOLUTION

#include <vector>
#include "table.hpp"

class Solution {
public:
	Solution();
	~Solution();
	void printSolution();
	void setTables(std::vector<Table> tables);
	void initSol(std::vector<Company*> companies);
	void randomMove();
	void stdMove();

	float computeCostFunction();
	float computeStandardDeviation();

private:
	std::vector<Table> tables_;
};

#endif

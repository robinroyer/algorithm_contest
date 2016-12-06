#ifndef H_TABLE
#define H_TABLE

#include "company.hpp"
#include <vector>

class Table {
public:
	Table();   // This is the constructor declaration
	~Table();  // This is the destructor: declaration

	void printTable();
	void addCompany(const Company* company);
	void removeCompany(const Company* company);
	// The following method will be applied everytime
	//a table changes so that a minor modification will only make a minor computation 
	//and  the program won't have to compute the global weights of all tables
	// only applies to weight for friends and rivals, can't compute the standard deviation
	// because that's a local var
	void computeWeight();

private:
	std::vector<Company*> companies_;
	int weight_;
	int size_;
};

#endif

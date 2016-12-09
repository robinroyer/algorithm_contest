#ifndef H_TABLE
#define H_TABLE

#include "company.hpp"
#include <vector>

class Table {
public:
	Table();   // This is the constructor declaration
	~Table();  // This is the destructor: declaration

	void printTable();
	bool addCompany( Company* company);
	Company* removeCompany( int id);
	void computeWeight();
	int getWeight();
	std::vector<Company*> getCompanies();

private:
	std::vector<Company*> companies_;
	int weight_;
	int size_;
};

#endif

#ifndef H_TABLE
#define H_TABLE

#include <vector>

#include "company.hpp"

class Table {
public:
	Table();
	~Table();

	void printTable();
	bool addCompany( Company* company);
	Company* removeCompany( int id);
	void computeWeight();
	int getWeight();
	int getSize();
	std::vector<Company*> getCompanies();

private:
	std::vector<Company*> companies_;
	int weight_;
	int size_;
};

#endif

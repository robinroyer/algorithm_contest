#include <iostream>
#include "table.hpp"

// Member functions definitions including constructor
Table::Table(void) : weight_(0) {
   std::cout << "Table is being created" << std::endl;
}

Table::~Table(void) {
   std::cout << "Table is being deleted" << std::endl;
}

void Table::printTable() {
	for (int j = 0; j < companies_.size(); j++)
	{
		if (j == companies_.size() - 1) {
			std::cout << companies_[j]->getId();
		}
		else {
			std::cout << companies_[j]->getId() << " ";
		}
	}
	std::cout << std::endl;
}

bool Table::addCompany(Company* company){
	
	std::vector<int> forbidTmp = company->getForbidden();

	for (int i = 0; i < forbidTmp.size(); i++)
	{
		for (int j = 0; j < companies_.size(); j++)
		{
			if (forbidTmp[i] == companies_[j]->getId())
			{
				return false;
			}
		}
	}

	companies_.push_back(company);
	return true;
}

int Table::getWeight(){
	return weight_;
}

std::vector<Company*> Table::getCompanies(){
	return companies_;
}




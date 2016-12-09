#include <iostream>
#include "table.hpp"

// Member functions definitions including constructor
Table::Table(void) : weight_(0), size_(0) {
   // std::cout << "Table is being created" << std::endl;
}

Table::~Table(void) {
   // std::cout << "Table is being deleted" << std::endl;
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

	// protection against stupidity
	if(company == NULL)
		return false;
	
	// CHECKING IF THE COMPANY CAN SIT AT THE TABLE
	std::vector<int> forbidTmp = company->getForbidden();

	for (int i = 0; i < forbidTmp.size(); i++)
	{
		for (int j = 0; j < companies_.size(); j++)
		{
			if (forbidTmp[i] == companies_[j]->getId())
				return false;
		}
	}

	// THE COMPANY WILL SIT AT THE TABLE !!
	companies_.push_back(company);

	// CHECKING IF THE COMPANY 'S FRIENDS & CHANGE WEIGHT
	std::vector<int> friendsTmp = company->getFriends();

	for (int i = 0; i < friendsTmp.size(); i++)
	{
		for (int j = 0; j < companies_.size(); j++)
		{
			if (friendsTmp[i] == companies_[j]->getId())
				weight_ -= 2 ; // GOOD GOOD GOOD
		}
	}


	// CHECKING IF THE COMPANY 'S RIVALS & CHANGE WEIGHT
	std::vector<int> rivalsTmp = company->getRivals();

	for (int i = 0; i < rivalsTmp.size(); i++)
	{
		for (int j = 0; j < companies_.size(); j++)
		{
			if (rivalsTmp[i] == companies_[j]->getId())
				weight_++ ; // BAD BAD BAD
		}
	}

	size_ += company->getSize();


	// WELL DONE
	return true;
}

Company* Table::removeCompany( int id){

	Company * companyRemoved = NULL;

	for (int j = 0; j < companies_.size(); j++)
	{
		if (id == companies_[j]->getId()){
			companyRemoved = companies_[j];
			companies_.erase(companies_.begin() + j );
		}
	}

	if (companyRemoved != NULL)
	{
		// CHECKING IF THE COMPANY 'S FRIENDS & CHANGE WEIGHT
		std::vector<int> friendsTmp = companyRemoved->getFriends();

		for (int i = 0; i < friendsTmp.size(); i++)
		{
			for (int j = 0; j < companies_.size(); j++)
			{
				if (friendsTmp[i] == companies_[j]->getId())
					weight_ += 2 ; // BAD BAD BAD
			}
		}

		// CHECKING IF THE COMPANY 'S RIVALS & CHANGE WEIGHT
		std::vector<int> rivalsTmp = companyRemoved->getRivals();

		for (int i = 0; i < rivalsTmp.size(); i++)
		{
			for (int j = 0; j < companies_.size(); j++)
			{
				if (rivalsTmp[i] == companies_[j]->getId())
					weight_-= 2 ; // GOOD GOOD GOOD
			}
		}

		// REMOVE PEOPLE FROM TABLE
		size_ -= companyRemoved->getSize();
	}


	return companyRemoved; // NULL is not deleted
}


int Table::getWeight(){
	return weight_;
}

int Table::getSize(){
	return size_;
}


std::vector<Company*> Table::getCompanies(){
	return companies_;
}




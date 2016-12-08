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

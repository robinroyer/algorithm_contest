#include <iostream>
#include "table.h"

// Member functions definitions including constructor
Table::Table(void) {
   std::cout << "Object is being created" << std::endl;
}

Table::~Table(void) {
   std::cout << "Object is being deleted" << std::endl;
}

void Table::printTable() {}

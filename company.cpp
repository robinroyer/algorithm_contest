#include <iostream>
#include "company.h"

// Member functions definitions including constructor
Company::Company() {
   std::cout << "Object is being created" << std::endl;
}

Company::~Company() {
   std::cout << "Object is being deleted" << std::endl;
}

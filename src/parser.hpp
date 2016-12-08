#ifndef H_PARSER
#define H_PARSER

#include <map>
#include <stdlib.h>

#include "company.hpp"
#include "table.hpp"


void parse(std::string, std::map<int, Company*> &, std::vector<Table*> &);

#endif

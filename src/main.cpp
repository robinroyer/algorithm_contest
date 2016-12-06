#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parser.hpp"
#include "company.hpp"
#include <map>

int main(int argc, char* argv[])
{
	std::map<int, Company*> companies = parse(argv[1]);
	return EXIT_SUCCESS;
}

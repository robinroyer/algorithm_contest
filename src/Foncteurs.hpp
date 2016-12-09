#ifndef  FRONTEUR
#define  FRONTEUR

#include <stdlib.h>

#include "table.hpp"
#include "company.hpp"


/**
 * Foncteur comparing size of forbidden companies
 */
class FoncteurCompareSizeOfEnnemies
{
public :
	FoncteurCompareSizeOfEnnemies() {}
	~FoncteurCompareSizeOfEnnemies() {}
	bool operator () ( Company* company1,  Company* company2) {
		return company1->getForbidden().size()>company2->getForbidden().size();
	}
};

/**
 * Foncteur comparing size of table
 */
class FoncteurCompareSizeOfTables
{
public:
	FoncteurCompareSizeOfTables() {}
	~FoncteurCompareSizeOfTables() {}
	bool operator() ( Table table1,  Table table2) {
		return table1.getSize() < table2.getSize();
	}
};

/**
 * Foncteur comparing solution based on a cost solution
 */
class FoncteurCompareCostofSolutions
{
public:
	FoncteurCompareCostofSolutions() {}
	~FoncteurCompareCostofSolutions() {}
	bool operator() (Solution* sol1, Solution* sol2) {
		return sol1->computeCostFunction() < sol2->computeCostFunction();
	}
};

#endif;
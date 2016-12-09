#ifndef  FRONTEUR
#define  FRONTEUR

#include "table.hpp"
#include "company.hpp"

#include <stdlib.h>

//Foncteur permettant de comparer les id de deux companys, à utiliser sur une table avec find_if pour savoir s'il contient la company)
class FoncteurCompanyOfSameId
{
public :
	FoncteurCompanyOfSameId(int id) : id_(id) {}
	~FoncteurCompanyOfSameId() {}

	bool operator() ( Company* comp) {
		return comp->getId() == id_;
	}
private :
	int id_;
};

class FoncteurCompareSizeOfEnnemies
{
public :
	FoncteurCompareSizeOfEnnemies() {}
	~FoncteurCompareSizeOfEnnemies() {}
	bool operator () ( Company* company1,  Company* company2) {
		return company1->getForbidden().size()>company2->getForbidden().size();
	}
};


class FoncteurCompareSizeOfTables
{
public:
	FoncteurCompareSizeOfTables() {}
	~FoncteurCompareSizeOfTables() {}
	bool operator() ( Table table1,  Table table2) {
		return table1.getSize() < table2.getSize();
	}
};


#endif;
#ifndef  FRONTEUR
#define  FRONTEUR

#include "table.hpp"
#include "company.hpp"
#include <stdlib.h>

//Foncteur permettant de comparer les id de deux companys, à utiliser sur une table avec find_if pour savoir s'il contient la company)
class FoncteurCompanyOfSameId
{
public :
	FoncteurCompanyOfSameId(unsigned int id) : id_(id) {}
	~FoncteurCompanyOfSameId() {}

	bool operator() (const Company* comp) {
		return comp->getId() == id_;
	}
private :
	unsigned int id_;
};

class FoncteurCompareSizeOfEnnemies
{
public :
	FoncteurCompareSizeOfEnnemies() {}
	~FoncteurCompareSizeOfEnnemies() {}
	bool operator () (const Company* company1, const Company* company2) {
		return company1->getForbidden().size()>company2->getForbidden().size();
	}
};




#endif;
#ifndef H_COMPANY
#define H_COMPANY

#include <vector>


class Company {
public:
	Company(unsigned int id, unsigned int size);   // This is the constructor declaration
	~Company();  // This is the destructor: declaration

	  //methode d'accès et de modification des attributs
	unsigned int getId() const;
	unsigned int getSize() const;
	std::vector<Company*> getFriends() const;
	void setFriends(const std::vector<Company*> friends);
	std::vector<Company*> getRivals() const;
	void setRivals(const std::vector<Company*> rivals);
	std::vector<Company*> getForbidden() const;
	void setForbidden(const std::vector<Company*> forbiddenCompanies);
	std::vector<Company*> getForbidden() const;


private:
	unsigned int id_;
	unsigned int size_;
	std::vector<Company*> friends_;
	std::vector<Company*> rivals_;
	std::vector<Company*> forbidden_;
};

#endif

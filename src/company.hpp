#ifndef H_COMPANY
#define H_COMPANY

#include <vector>


class Company {
public:
	Company(unsigned int id, unsigned int size);   // This is the constructor declaration
	~Company();  // This is the destructor: declaration

	void setFriends(const std::vector<Company*> friends);
	void setRivals(const std::vector<Company*> rivals);
	void setForbidden(const std::vector<Company*> forbiddenCompanies);
	//methode d'accès et de modification des attributs
	unsigned int getId() const;
	unsigned int getSize() const;
	std::vector<Company*> getForbidden() const;
	std::vector<Company*> getFriends() const;
	std::vector<Company*> getRivals() const;


private:
	unsigned int id_;
	unsigned int size_;
	std::vector<Company*> friends_;
	std::vector<Company*> rivals_;
	std::vector<Company*> forbidden_;
};

#endif

#ifndef H_COMPANY
#define H_COMPANY

#include <vector>


class Company {
public:
	Company(int id, int size);   // This is the constructor declaration
	~Company();  // This is the destructor: declaration

	void addRival(int);
	void addFriend(int);
	void addForbidden(int);
	//methode d'accès et de modification des attributs
	int getId() const;
	int getSize() const;
	std::vector<int> getForbidden() const;
	std::vector<int> getFriends() const;
	std::vector<int> getRivals() const;


private:
	int id_;
	int size_;
	std::vector<int> friends_;
	std::vector<int> rivals_;
	std::vector<int> forbidden_;
};

#endif

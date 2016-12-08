#include <iostream>
#include "company.hpp"

// Member functions definitions including constructor
Company::Company( int id, int size) : id_(id),size_(size) {
	std::cout << "company: " << id << " a " << size << " personnes"<< std::endl;
}

Company::~Company() {
   std::cout << "Object is being deleted" << std::endl;
   while (friends_.size() != 0)
   {
	   friends_.pop_back();

   }
   while (rivals_.size() != 0)
   {
	   rivals_.pop_back();
   }
   while (forbidden_.size() != 0)
   {	
	   forbidden_.pop_back();
   }
}

unsigned int Company::getId() const {
	return id_;
}

unsigned int Company::getSize() const {
	return size_;
}

std::vector<int> Company::getFriends() const {
	return friends_;
}

std::vector<int> Company::getRivals() const {
	return rivals_;
}

std::vector<int> Company::getForbidden() const {
	return forbidden_;
}

void Company::addRival(int id) {
	rivals_.push_back(id);
}

void Company::addFriend(int id) {
	friends_.push_back(id);
}

void Company::addForbidden(int id) {
	forbidden_.push_back(id);
}


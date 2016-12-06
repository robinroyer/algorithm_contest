#include <iostream>
#include "company.hpp"

// Member functions definitions including constructor
Company::Company(unsigned int id, unsigned int size) : id_(id),size_(size) {
	std::cout << "company: " << id << " a " << size << " personnes"<< std::endl;
}

Company::~Company() {
   std::cout << "Object is being deleted" << std::endl;
   while (friends_.size() != 0)
   {
	   friends_.back() = nullptr;
	   friends_.pop_back();

   }
   while (rivals_.size() != 0)
   {
	   rivals_.back() = nullptr;
	   rivals_.pop_back();
   }
   while (forbidden_.size() != 0)
   {
	   forbidden_.back() = nullptr;
	   forbidden_.pop_back();
   }
}


unsigned int Company::getId() const {
	return id_;
}

unsigned int Company::getSize() const {
	return size_;
}

std::vector<Company*> Company::getFriends() const {
	return friends_;
}

void Company::setFriends(const std::vector<Company*> friends) {
	friends_ = friends;
}

std::vector<Company*> Company::getRivals() const {
	return rivals_;
}

void Company::setRivals(const std::vector<Company*> rivals) {
	rivals_ = rivals;
}

void Company::addRival(int id) {
	//TODO
}

void Company::addFriend(int id) {
	//TODO
}

void Company::addForbidden(int id) {
	//TODO
}

void Company::setForbidden(const std::vector<Company*> forbiddenCompanies) {
	forbidden_ = forbiddenCompanies;
}

std::vector<Company*> Company::getForbidden() const {
	return forbidden_;
}
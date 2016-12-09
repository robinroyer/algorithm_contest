#include <iostream>

#include "company.hpp"

Company::Company( int id, int size) : id_(id),size_(size) {}

Company::~Company() {
   while (friends_.size() != 0)   
	   friends_.pop_back();

   while (rivals_.size() != 0)
	   rivals_.pop_back();
   
   while (forbidden_.size() != 0)
	   forbidden_.pop_back();
}

/**
 * id getter
 */
int Company::getId() const {
	return id_;
}

/**
 * size getter
 */
int Company::getSize() const {
	return size_;
}

/**
 * add a new company that can not sit at the same table
 */
std::vector<int> Company::getFriends() const {
	return friends_;
}

/**
 * rival list getter
 */
std::vector<int> Company::getRivals() const {
	return rivals_;
}

/**
 * forbidden list getter
 */
std::vector<int> Company::getForbidden() const {
	return forbidden_;
}

/**
 * add a new company that should not sit at the same table
 */
void Company::addRival(int id) {
	rivals_.push_back(id);
}

/**
 * add a new company that should sit at the same table
 */
void Company::addFriend(int id) {
	friends_.push_back(id);
}

/**
 * add a new company that can not sit at the same table
 */
void Company::addForbidden(int id) {
	forbidden_.push_back(id);
}


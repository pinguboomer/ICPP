#include "Person.h"

Entity::Person::Person()
{
}

Entity::Person::Person(int id, string name, string phone) {
	this->id = id;
	this->name = name;
	this->phone = phone;
}

Entity::Person::~Person()
{
}

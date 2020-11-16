#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Date.h"
#include "Address.h"
using namespace std;

struct Person
{
private:
	string _name;
	string _surname;
	Address _address;
	Date _birthDate;
public:
	Person();
	~Person();
	Person(string _name, string _surname, Address _address, Date _birthDate);
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend std::istream& operator>>(std::istream& is, Person& person);
};

#endif // !PERSON_H
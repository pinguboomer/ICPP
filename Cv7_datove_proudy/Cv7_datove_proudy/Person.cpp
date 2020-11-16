#include "Person.h"


Person::Person()
{
}

Person::~Person()
{
}

Person::Person(string _name, string _surname, Address _address, Date _birthDate)
{
    this->_name = _name;
    this->_surname = _surname;
    this->_address = _address;
    this->_birthDate = _birthDate;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    return os << person._name << " " << person._surname << "-" << person._address << ", " << person._birthDate;
}

std::istream& operator>>(std::istream& is, Person& person)
{
    char ch;
    is >> person._name >> person._surname >> person._address >> ch >> person._birthDate;
    return is;
}
#pragma once

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>
using namespace std;

struct Address
{
private:
	string _street;
	string _city;
	int _psc;
public:
	Address();
	~Address();
	Address(string _street, string _city, int _psc);
	friend std::ostream& operator<<(std::ostream& os, const Address& address);
	friend std::istream& operator>>(std::istream& is, Address& address);
};

#endif // !ADDRESS_H
#include "Address.h"

Address::Address()
{
}

Address::~Address()
{
}

Address::Address(string _street, string _city, int _psc)
{
	this->_street = _street;
	this->_city = _city;
	this->_psc = _psc;
}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
	return os << address._street << " " << address._city << " " << address._psc;
}

std::istream& operator>>(std::istream& is, Address& address)
{	
	return is >> address._street >> address._city >> address._psc;
}

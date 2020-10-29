#pragma once

#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include "Person.h"
#include "Element.h"

#include<stdexcept>
using namespace std;
namespace Model {
	class NumberList {
	private:
		Element* _first;
	public:
		NumberList();
		~NumberList();
		void addPerson(Entity::Person p);
		string findPhoneNumber(string name) const;
		string findPhoneNumber(int id) const;
	};
}
#endif // !NUMBERLIST_H
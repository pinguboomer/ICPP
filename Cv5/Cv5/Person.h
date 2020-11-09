#pragma once
#ifndef PERSON_H 
#define PERSON_H

#include <iostream>
#include<stdexcept>
using namespace std;
namespace Entity {
	struct Person {		
	public:
		string name;
		string phone;
		int id;
		Person();
		~Person();
		Person(int id, string name, string phone);		
	};
}
#endif // !PERSON.PERSON_H


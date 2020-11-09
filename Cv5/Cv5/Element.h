#pragma once
#include "Person.h"
#ifndef ELEMENT_H
#define ELEMENT_H

struct Element {
	
public:
	~Element();
	Entity::Person data;
	Element* next;
	Element(Entity::Person data);	
};

#endif // !ELEMENT_H
#include "Element.h"



Element::Element(Entity::Person data)
{
	this->next = nullptr;
	this->data = data;
}

Element::~Element()
{
}

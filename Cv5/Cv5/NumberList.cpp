#include "NumberList.h"

Model::NumberList::NumberList()
{
	this->_first = nullptr;
}

Model::NumberList::~NumberList()
{
	Element* element = this->_first;
	while (element != nullptr) {
		Element* temp = element->next;
		delete element;
		element = temp;
	}
}

void Model::NumberList::addPerson(Entity::Person p)
{
	Element* element = new Element(p);
	if (this->_first == nullptr) {
		this->_first = element;
	}
	else {
		Element* temp = this->_first;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = element;
	}
}

string Model::NumberList::findPhoneNumber(string name) const
{
	if (name.empty()) {
		throw invalid_argument("Name is empty");
	}
	Element* element = this->_first;
		while (element != nullptr) {
			if (element->data.name == name) {
				return element->data.phone;
			}
			element = element->next;
		}
	throw exception("Phone was not found");
}

string Model::NumberList::findPhoneNumber(int id) const
{
	if (id < 0) {
		throw invalid_argument("id is < 0");
	}
	Element* element = this->_first;
	while (element != nullptr) {
		if (element->data.id == id) {
			return element->data.phone;
		}
		element = element->next;
	}
	throw exception("Phone was not found");
}

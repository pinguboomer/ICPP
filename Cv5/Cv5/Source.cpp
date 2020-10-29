// jmenny prostor = namespace

#include "NumberList.h"
#include <stdlib.h>
#include <iostream>
#define _CRTDBG_MAP_ALLOC

using namespace Entity;
int main() {

	Model::NumberList* numberList = new Model::NumberList();
	Person* p1 = new Person(1, "Jurij", "111 222 333");
	Person* p2 = new Person(2, "Sergej", "333 444 555");
	Person* p3 = new Person(3, "Andrej", "666 777 888");
	Person* p4 = new Person(4, "Ivan", "999 000 111");
	numberList->addPerson(*p1);
	numberList->addPerson(*p2);
	numberList->addPerson(*p3);
	numberList->addPerson(*p4);

	try {
		std::cout << "Telefonni cislo je: " << numberList->findPhoneNumber(2) << std::endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	try {
		std::cout << "Telefonni cislo je: " << numberList->findPhoneNumber("Ivan") << std::endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	
	system("pause");
}
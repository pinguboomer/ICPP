#include "IncreasingContainer.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    IncreasingContainer<std::string> container = IncreasingContainer<std::string>();
	for (size_t i = 0; i < 8; i++)
	{
		container.add("igor");		
		std::cout << "pocet: " << container.quantity() << std::endl;
		std::cout << "je misto: " << container.isSpaceInArray() << std::endl;
		std::cout << "hodnota: " << container.operator[](i) << std::endl;
	}
	std::cout << "pocet prvku: " << container.quantity() << std::endl;
	container.addToIndex(5, "jarmila");
	std::cout << "Pridani na pozici 5" << std::endl;
	container.remove(4);
	std::cout << "Odstraneni na pozici 4" << std::endl;
	for (size_t i = 0; i < container.quantity(); i++)
	{
		string str = container.operator[](i);
		std::cout << i << ". hodnota: " << str << std::endl;
	}

    return 0;
}
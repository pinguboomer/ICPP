#include "IncreasingContainer.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    IncreasingContainer<std::string> container = IncreasingContainer<std::string>();
	for (size_t i = 0; i < 8; i++)
	{
		container.add("igor");		
		std::cout << "pocet: " << container.quantity() << std::endl;
		std::cout << "je misto: " << container.isSpaceInArray() << std::endl;		
	}
	container.addToIndex(5, "jarmila");
	std::cout << "index 5: " << container.operator[](5) << std::endl;
	container.remove(4);

    return 0;
}
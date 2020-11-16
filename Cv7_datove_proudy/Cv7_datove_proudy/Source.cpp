#include "Person.h"
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

#define SIZE 3

Person* loadBin()
{
	ifstream input{};
	input.open("data.bin", ios::binary);
	input.seekg(0, ios::end);
	int loadedSize = input.tellg() / sizeof(Person);
	input.seekg(0, ios::beg);
	Person* array = new Person[loadedSize];
	for (size_t i = 0; i < loadedSize; i++) {
		input.read((char*)&array[i], sizeof(Person));
	}
	input.close();
	return array;
}

void saveBin()
{
	Person array[SIZE];
	srand(time(NULL));
	for (size_t i = 0; i < SIZE; i++)
	{
		int year = rand() % 50 + 1970;
		int month = rand() % 12 + 1;
		int day = rand() % 30 + 1;
		int psc = rand() % 2000 + 1;
		Date date{ day, month, year };
		Address address{ "Studentska " + to_string(i), "Pardubice", psc };
		Person person{ "Igor", "Lodivod", address, date };
		array[i] = person;
	}
	ofstream output{};
	output.open("data.bin", ios::out | ios::binary);
	output.write((const char*)&array, sizeof(array));

	output.close();
}

void saveTxt() {
	
	Person array[SIZE];

	srand(time(NULL));
	for (size_t i = 0; i < SIZE; i++)
	{
		int year = rand() % 50 + 1970;
		int month = rand() % 12 + 1;
		int day = rand() % 30 + 1;
		int psc = rand() % 2000 + 1;
		Date date{ day, month, year };
		Address address{ "Studentska " + to_string(i), "Pardubice", psc };
		Person person{ "Igor", "Lodivod", address, date };
		array[i] = person;
	}
	ofstream output{};
	output.open("data.txt");
	for (size_t i = 0; i < SIZE; i++) {
		output << array[i];
		output << endl;
	}
	output.close(); 
}

Person* loadTxt() {

	ifstream input{};
	int loadedSize = 0;
	string line;
	Person* array;
	input.open("data.txt");
	while (getline(input, line)) {
		loadedSize++;
	}
	array = new Person[loadedSize];
	input.clear();
	input.seekg(0);
	for (size_t i = 0; i < loadedSize; i++) {
		input >> array[i];
	}
	input.close();
	return array;
}

int main(int argc, char** argv) {

	saveBin();
	Person* arrayBin = loadBin();

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arrayBin[i] << endl;
	}

	printf("\n");
	saveTxt();
	Person* arrayTxt = loadTxt();

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arrayTxt[i] << endl;
	}


	return 0;
}
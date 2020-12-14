#include "ITube.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void loadTxt() {
	ITube* tube;
	int size = 0;
	ifstream in;
	string line;
	char c;
	in.open("data.txt");
	if (in.is_open()) {
		getline(in, line);
		size = stoi(line);
		tube = new Tube(size);
		int i = 0;
		while (getline(in, line)) {
			for (int j = 0; j < line.length(); j++) {
				c = line.at(j);
				switch (c) {
				case '-':
					tube->addNode(new Node(i, j, 1));
					break;
				case 'I':
					tube->addNode(new Node(i, j, 2));
					break;
				case '+':
					tube->addNode(new Node(i, j, 3));
					break;
				case 'O':
					tube->addNode(new Node(i, j, 0));
					break;
				case 'T':
					tube->addNode(new Node(i, j, 4));
					break;
				}
			}
			i++;
		}
		cout << "Is tube ok? ";
		cout << tube->isTubeOK() << endl;
		in.close();
	}
} 

int main() {

	loadTxt();
	return 0;
}

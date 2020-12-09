#include "ITube.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ITube* loadTxt() {
    string line;
    int velikost;
    Tube tube = Tube(0);
    std::ifstream file("data.txt", std::ifstream::in);
        if (file.is_open()) {
            std::getline(file, line);
            velikost = stoi(line);
            tube = Tube(velikost);
            file >> tube;
            cout << tube.isTubeOK() << endl;
        }
    return 0;
}

int main() {

    loadTxt();
	return 0;
}

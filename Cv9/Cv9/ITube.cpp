#include "ITube.h"


Tube::Tube(int size)
{
	this->size = size;
	matrix = new ATubeNode * *[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new ATubeNode * [size];
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
}

Tube::~Tube()
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			delete matrix[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		delete matrix[i];
	}
	delete matrix;

}

void Tube::addNode(ATubeNode* node)
{
	if (node->x > size && node->y > size) {
		throw std::out_of_range("Wrong node parameters");
	}
	else {
		matrix[node->x][node->y] = node;
	}

}

const ATubeNode* Tube::getNode(int x, int y) const
{
	if (x > size && y > size) {
		throw std::out_of_range("Wrong parameters");
	}
	else {
		return matrix[x][y];
	}

}

bool Tube::isTubeOK() const
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] != nullptr) {
				if (!(matrix[i][j]->isCorrect(this))) {
					return false;
				}
			}
		}
	}
	return true;

}

const int Tube::getSize() const
{
	return size;
}


Node::Node()
{
}

Node::Node(int x, int y, int type)
{
	this->x = x;
	this->y = y;
	this->type = type;

}

ITube::~ITube()
{
}

Node::~Node()
{
}

ATubeNode::~ATubeNode()
{
}

bool Node::isCorrect(const ITube* tube) const
{
	if (this->type == 1) {
		return tube->getNode(x, y - 1) != nullptr
			&& tube->getNode(x, y + 1) != nullptr
			&& tube->getNode(x, y - 1)->type != 2
			&& tube->getNode(x, y + 1)->type != 2;
	}

	if (this->type == 2) {
		return tube->getNode(x - 1, y) != nullptr
			&& tube->getNode(x + 1, y) != nullptr
			&& tube->getNode(x - 1, y)->type != 1
			&& tube->getNode(x + 1, y)->type != 1
			&& tube->getNode(x - 1, y)->type != 4;
	}

	if (this->type == 3) {
		return tube->getNode(x - 1, y) != nullptr
			&& tube->getNode(x + 1, y) != nullptr
			&& tube->getNode(x, y - 1) != nullptr
			&& tube->getNode(x, y + 1) != nullptr
			&& tube->getNode(x, y - 1)->type != 1
			&& tube->getNode(x, y + 1)->type != 1
			&& tube->getNode(x - 1, y)->type != 2
			&& tube->getNode(x + 1, y)->type != 2
			&& tube->getNode(x, y - 1)->type != 4;
	}

	if (this->type == 4) {
		return tube->getNode(x - 1, y) != nullptr
			&& tube->getNode(x + 1, y) != nullptr
			&& tube->getNode(x, y - 1) != nullptr
			&& tube->getNode(x, y - 1)->type != 1
			&& tube->getNode(x - 1, y)->type != 2
			&& tube->getNode(x + 1, y)->type != 2
			&& tube->getNode(x, y - 1)->type != 4;
	}

	return true;

}


std::ifstream& operator >> (std::ifstream& input, Tube& tube)
{
	char c = 0;
	ATubeNode* newNode = nullptr;
	std::string line;

	while (std::getline(input, line)) {
		int j = 0;
		for (int i = 0; i < line.length(); i++) {
			c = line.at(i);

			switch (c) {
			case '-':
				newNode = new Node(i, j, 1);
				break;
			case 'I':
				newNode = new Node(i, j, 2);
				break;
			case '+':
				newNode = new Node(i, j, 3);
				break;
			case 'T':
				newNode = new Node(i, j, 4);
				break;
			case 'O':
				newNode = new Node(i, j, 0);
				break;
			}
			if (newNode != nullptr) {
				tube.addNode(newNode);
			}
			j++;
		}
	}

	return input;
}



#include "ITube.h"


Tube::Tube()
{
}

Tube::Tube(int size)
{
	if (size < 1) {
		throw std::out_of_range("Wrong size");
	}
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

void Tube::addNode(ATubeNode* node) const
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
	if (this->type == 1) { // "-"
		return tube->getNode(x, y - 1) != nullptr
			&& tube->getNode(x, y + 1) != nullptr
			&& tube->getNode(x, y - 1)->type != 2
			&& tube->getNode(x, y + 1)->type != 2;
	}

	if (this->type == 2) { // "I"
		return tube->getNode(x - 1, y) != nullptr
			&& tube->getNode(x + 1, y) != nullptr
			&& tube->getNode(x - 1, y)->type != 1
			&& tube->getNode(x + 1, y)->type != 1
			&& tube->getNode(x + 1, y)->type != 4;
	}

	if (this->type == 3) { // "+"
		return tube->getNode(x - 1, y) != nullptr
			&& tube->getNode(x + 1, y) != nullptr
			&& tube->getNode(x, y - 1) != nullptr
			&& tube->getNode(x, y + 1) != nullptr
			&& tube->getNode(x - 1, y)->type != 1
			&& tube->getNode(x + 1, y)->type != 1
			&& tube->getNode(x, y - 1)->type != 2
			&& tube->getNode(x, y + 1)->type != 2
			&& tube->getNode(x + 1, y)->type != 4;
	}

	if (this->type == 4) { // "T"
		return tube->getNode(x + 1, y) != nullptr
			&& tube->getNode(x, y - 1) != nullptr
			&& tube->getNode(x, y + 1) != nullptr
			&& tube->getNode(x + 1, y)->type != 1
			&& tube->getNode(x, y - 1)->type != 2
			&& tube->getNode(x, y + 1)->type != 2
			&& tube->getNode(x - 1, y)->type != 4;
	}

	// "O"
	return true;

}

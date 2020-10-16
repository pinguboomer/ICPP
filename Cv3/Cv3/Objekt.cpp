#include "Objekt.h"

Objekt::Objekt(int id)
{
	this->id = id;
}

Objekt::~Objekt()
{
}

void Objekt::SetX(double x)
{
	this->x = x;
}


double Objekt::GetX() const
{
	return x;
}


void Objekt::SetY(double y)
{
	this->y = y;
}

double Objekt::GetY() const
{
	return y;
}

int Objekt::GetId() const
{
	return id;
}

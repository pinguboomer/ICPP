#include"receipt.h"

void Receipt::SetId(int id)
{
	this->id = id;
}

int Receipt::GetId() const
{
	return id;
}

void Receipt::SetCost(double cost)
{
	this->cost = cost;
}

double Receipt::GetCost() const
{
	return cost;
}

void Receipt::SetDph(double dph)
{
	this->dph = dph;
}

double Receipt::GetDph() const
{
	return dph;
}

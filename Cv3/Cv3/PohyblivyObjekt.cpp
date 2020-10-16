#include "PohyblivyObjekt.h"

PohyblivyObjekt::PohyblivyObjekt(int id) : Objekt(id)
{
	this->id = id;
}

void PohyblivyObjekt::SetUhelNatoceni(double uhelNatoceni)
{
	this->uhelNatoceni = uhelNatoceni;
}

double PohyblivyObjekt::GetUhelNatoceni() const
{
	return uhelNatoceni;
}

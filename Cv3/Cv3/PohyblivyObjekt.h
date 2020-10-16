#pragma once
#ifndef POHYBLIVYOBJEKT_H
#define POHYBLIVYOBJEKT_H

#include "Objekt.h"

class PohyblivyObjekt : public Objekt {
	double uhelNatoceni;
public:
	PohyblivyObjekt(int id);
	void SetUhelNatoceni(double uhelNatoceni);
	double GetUhelNatoceni() const;
};

#endif
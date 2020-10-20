#pragma once
#ifndef HRA_H
#define HRA_H
#include "Objekt.h"
#include "PohyblivyObjekt.h"
#include "StatickyObjekt.h"
#include<string>

class Hra {
	int pocitadlo = 0;
	Objekt** objekty;
	
public:
	Hra();
	~Hra();
	void vlozObjekt(Objekt* o);
	int* najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);

};
#endif
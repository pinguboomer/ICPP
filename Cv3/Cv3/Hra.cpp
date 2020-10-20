#include "Hra.h"
#include <iostream>
#include <math.h>

Hra::Hra()
{
	objekty = new Objekt * [4];
}

Hra::~Hra()
{
	delete[] objekty;
}

void Hra::vlozObjekt(Objekt* o)
{
	if (pocitadlo < sizeof(objekty)) {
		objekty[pocitadlo] = o;
		pocitadlo++;
	}
}


int* Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax)
{	
	int pocetStatickych = 0;
	for (int i = 0; i < sizeof(objekty); i++)
	{
		if (dynamic_cast<StatickyObjekt*>(objekty[i]) != nullptr) {
			if (xmin <= objekty[i]->GetX() && xmax >= objekty[i]->GetX() && ymax >= objekty[i]->GetY() && ymax >= objekty[i]->GetY()) {
				pocetStatickych++;
			}			
		}
	}
	if (pocetStatickych != 0) {
		int k = 0;
		int* poleId = new int[pocetStatickych];
		for (int i = 0; i < sizeof(objekty); i++)
		{
			if (dynamic_cast<StatickyObjekt*>(objekty[i]) != nullptr) {
				if (xmin <= objekty[i]->GetX() && xmax >= objekty[i]->GetX() && ymax >= objekty[i]->GetY() && ymax >= objekty[i]->GetY()) {
					poleId[k] = objekty[i]->GetId();
					k++;
					if (k == pocetStatickych) {
						return poleId;
					}
				}
			}
		}
		return poleId;
	}
	return 0;
}

PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r)
{
	double d;
	int pocetUvnitr = 0;
	for (int i = 0; i < sizeof(objekty); i++)
	{
		if (dynamic_cast<PohyblivyObjekt*>(objekty[i]) != nullptr) {
			double s = (pow(x - objekty[i]->GetX(), 2)) + pow(y - objekty[i]->GetY(), 2);
			d = sqrt(s);
			if (d < r) {
				pocetUvnitr++;
			}		
		}
	}
	if(pocetUvnitr > 0) {
	PohyblivyObjekt** pole = new PohyblivyObjekt * [pocetUvnitr];
	int k = 0;
	for (int i = 0; i < sizeof(objekty); i++)
	{
		if (dynamic_cast<PohyblivyObjekt*>(objekty[i]) != nullptr) {
			double s = (pow(x - objekty[i]->GetX(), 2)) + pow(y - objekty[i]->GetY(), 2);
			d = sqrt(s);
			if (d < r) {
				pole[k] = dynamic_cast<PohyblivyObjekt*>(objekty[i]);				
				k++;
				if (k == pocetUvnitr) {
					return pole;
				}
			}
		} else {
		}
	}
	return pole;
	}
	return nullptr;	
}

PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax)
{
	double d;
	int pocetUvnitr = 0;
	for (int i = 0; i < sizeof(objekty); i++)
	{
		if (dynamic_cast<PohyblivyObjekt*>(objekty[i]) != nullptr) {
			double s = (pow(x - objekty[i]->GetX(), 2)) + pow(y - objekty[i]->GetY(), 2);
			d = sqrt(s);
			if (d < r && dynamic_cast<PohyblivyObjekt*>(objekty[i])->GetUhelNatoceni() > umin &&
				dynamic_cast<PohyblivyObjekt*>(objekty[i])->GetUhelNatoceni() < umax) {
				pocetUvnitr++;
			}
		}
	}
	if (pocetUvnitr > 0) {
		PohyblivyObjekt** pole = new PohyblivyObjekt * [pocetUvnitr];
		int k = 0;
		for (int i = 0; i < sizeof(objekty); i++)
		{
			if (dynamic_cast<PohyblivyObjekt*>(objekty[i]) != nullptr) {
				double s = (pow(x - objekty[i]->GetX(), 2)) + pow(y - objekty[i]->GetY(), 2);
				d = sqrt(s);
				if (d < r && dynamic_cast<PohyblivyObjekt*>(objekty[i])->GetUhelNatoceni() > umin &&
					dynamic_cast<PohyblivyObjekt*>(objekty[i])->GetUhelNatoceni() < umax) {
					pole[k] = dynamic_cast<PohyblivyObjekt*>(objekty[i]);
					k++;
					if (k == pocetUvnitr) {
						return pole;
					}
				}
			}
			else {
			}
		}
		return pole;
	}
	return nullptr;
}

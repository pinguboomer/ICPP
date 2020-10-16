#pragma once
#ifndef OBJEKT_H
#define OBJEKT_H

class Objekt {
	
	double x;
	double y;
public:
	int id;
	Objekt(int id);
	virtual ~Objekt();
	void SetX(double x);
	double GetX() const;
	void SetY(double y);
	double GetY() const;
	int GetId() const;
};

#endif
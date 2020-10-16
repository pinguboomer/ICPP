#pragma once
#ifndef STATICKYOBJEKT_H
#define STATICKYOBJEKT_H

#include "Objekt.h"
#include "TypPrekazky.h"

class StatickyObjekt : public Objekt {
	TypPrekazky typPrekazky;
public:	
	StatickyObjekt(int id, TypPrekazky typPrekazky);
	TypPrekazky GetTypPrekazky();
};


#endif
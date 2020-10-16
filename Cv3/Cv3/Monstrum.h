#pragma once
#ifndef MONSTRUM_H
#define MONSTRUM_H

#include "PohyblivyObjekt.h"

class Monstrum : public PohyblivyObjekt {
	int hp;
	int maxhp;
public:
	void SetHp(int hp);
	int GetHp() const;
	void SetMaxhp(int maxhp);
	int GetMaxhp() const;
};

#endif
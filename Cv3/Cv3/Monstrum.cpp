#include "Monstrum.h"

void Monstrum::SetHp(int hp)
{
	this->hp = hp;
}

int Monstrum::GetHp() const
{
	return hp;
}

void Monstrum::SetMaxhp(int maxhp)
{
	this->maxhp = maxhp;
}

int Monstrum::GetMaxhp() const
{
	return maxhp;
}

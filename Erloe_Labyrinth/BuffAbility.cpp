#include "BuffAbility.h"

const char* BuffAbility::getAbilityCategory()
{
    return "PowerUp";
}
/*
BuffAbility::BuffAbility(int basePower, int powerCoefficient, int healthCoefficient, vector<char*> specialEffects)
{
	this->basePower = basePower;
	this->powerCoefficient = powerCoefficient;
	this->healthCoefficient = healthCoefficient;
	//this->specialEffects = specialEffects;
}*/

void BuffAbility::apply(Monster& affectedMonster, int effectivePower)
{
	int initialAttackPower = affectedMonster.getAttackPower();
	affectedMonster.setAttackPower(initialAttackPower + effectivePower);
}

#include "HealAbility.h"

const char* HealAbility::getAbilityCategory()
{

	return "Health";
}
/*
HealAbility::HealAbility(int basePower, int powerCoefficient, int healthCoefficient, vector<char*> specialEffects)
{
	this->basePower = basePower;
	this->powerCoefficient = powerCoefficient;
	this->healthCoefficient = healthCoefficient;
	this->specialEffects = specialEffects;
}*/
void HealAbility::apply(Monster& affectedMonster, int effectivePower) {
	int initialHealth = affectedMonster.getHealthPoints();

	affectedMonster.setHealthPoints(initialHealth + effectivePower);
}


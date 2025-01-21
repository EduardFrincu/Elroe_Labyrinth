#pragma once
#include "Ability.h"
class HealAbility : public Ability{

public:
	const char* getAbilityCategory();
	HealAbility(char* name, int basePower, int powerCoefficient, int healthCoefficient) :Ability(name, basePower, powerCoefficient, healthCoefficient) {};
	void apply(Monster& affectedMonster, int effectivePower);
};


#pragma once
#include "Ability.h"
class BuffAbility : public Ability{
	public:
		const char* getAbilityCategory();
		BuffAbility(char* name, int basePower, int powerCoefficient, int healthCoefficient) :Ability(name, basePower, powerCoefficient, healthCoefficient) {};
		void apply(Monster& affectedMonster, int effectivePower);
};


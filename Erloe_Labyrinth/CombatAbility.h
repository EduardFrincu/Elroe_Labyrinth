#pragma once
#include "Ability.h"
#include <iostream>
#include <vector>
using namespace std;
class CombatAbility : public Ability
{		

public:
	CombatAbility() = default;
	CombatAbility(char* name, int basePower, int powerCoefficient, int healthCoefficient) :Ability(name, basePower, powerCoefficient, healthCoefficient) {};
	void apply(Monster& affectedMonster, int effectivePower);
	const char* getAbilityCategory();
};


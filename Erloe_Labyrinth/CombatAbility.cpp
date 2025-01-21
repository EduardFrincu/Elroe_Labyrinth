#include "CombatAbility.h"

void CombatAbility::apply(Monster& affectedMonster, int effectivePower) {
	int initialHealth = affectedMonster.getHealthPoints();
	
	affectedMonster.setHealthPoints(initialHealth - effectivePower);
}

const char* CombatAbility::getAbilityCategory()
{
	return "Attack";
}


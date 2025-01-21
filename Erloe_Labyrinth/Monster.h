#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "Ability.h"
using namespace std;

class Ability;

class Monster
{
private:
	char name[20];
	char species[20];

	int attackPower;
	int healthPoints;

	int i;
	int j;

	char supportBehavior[20];
	char invaderBehavior[20];
	char defenderBehavior[20];

	vector <Ability*> abilities;

public:
	Monster();
	Monster(char* name, char* species, int attackPower, int healthPoints, char* supportBehavior, char* invaderBehavior, char* defenderBehavior, int i, int j, vector <Ability*> abilities);

	Ability* getAbilityBasedOnBehavior(const char* behavior);

	const char* getName() const;
	void setName(char* name);

	const char* getSpecies() const;
	void setSpecies(char* species);

	int getAttackPower() const;
	void setAttackPower(int attackPower);
	
	int getHealthPoints() const;
	void setHealthPoints(int healthPoints);

	int getI() const;
	void setI(int i);

	int getJ() const;
	void setJ(int j);

	const char* getSupportBehavior() const;
	void setSupportBehavior(char* supportBehavior);
	
	const char* getInvaderBehavior() const;
	void setInvaderBehavior(char*invaderBehavior);

	const char* getDefenderBehavior() const;
	void setDefenderBehavior(char* defenderBehavior);

	vector <Ability*> getAbilities();
	void setAbilities(vector <Ability* > abilities);

	void useAbilityOnOtherMonster(Monster& affectedMonster, char* abilityName);

	void useAbilityOnSameMonster(char* abilityName);

	friend std::istream& operator>>(std::istream& is, Monster& monster);
	friend std::ostream& operator<<(std::ostream& os, const Monster& monster);
};


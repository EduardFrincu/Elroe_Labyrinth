#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "Monster.h"
using namespace std;
class Monster;
class Ability {

protected:
	char name[20];
	int basePower;
	int powerCoefficient;
	int healthCoefficient;
	//vector<char*> specialEffects;

public:
	Ability();
	Ability(char* name, int basePower, int powerCoefficient, int healthCoefficient);

	virtual int getBasePower();

	virtual void apply(Monster& affectedMonster, int effectivePower) {}; //to be implemented for each ability type.
	virtual int calculateEffectivePower(const Monster& monster); //standard for each ability type. monster is the creature that is using the ability.
	virtual ~Ability(){}
	virtual char* getName();
	//virtual vector<char*> getSpecialEffects();
	virtual const char* getAbilityCategory() { return ""; };

	friend std::istream& operator>>(std::istream& is, Ability& ability);
	friend std::ostream& operator<<(std::ostream& os, const Ability& ability);

};

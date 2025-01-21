#pragma once
#include <iostream>
#include "Monster.h"
using namespace std;

class SpecialEffect {
public:
	virtual void applyEffectOnMonster(const Monster& Monster) = 0;
	virtual ~SpecialEffect() {};
};
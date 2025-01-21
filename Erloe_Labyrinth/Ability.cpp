#include "Ability.h"
#include <iostream>
using namespace std;

Ability::Ability()
{
	strcpy_s(this->name, "");
	this->basePower = 0;
	this->healthCoefficient = 0;
	this->powerCoefficient = 0;
}

Ability::Ability(char* name, int basePower, int powerCoefficient, int healthCoefficient)
{
	strcpy_s(this->name, name);
	this->basePower = basePower;
	this->powerCoefficient = powerCoefficient;
	this->healthCoefficient = healthCoefficient;
	//this->specialEffects = specialEffects;
}

int Ability::getBasePower()
{
    return this->basePower;
}

int Ability::calculateEffectivePower(const Monster& monster)
{

	return this->basePower + static_cast<int>(this->powerCoefficient * monster.getAttackPower() / 100)
						   + static_cast<int> (this->healthCoefficient * monster.getHealthPoints() / 100);
}

char* Ability::getName() {
	return this->name;
}

/*vector<char*> Ability::getSpecialEffects() {
	return this->specialEffects;
}*/


istream& operator>>(istream& is, Ability& ability) {
    cout << "Introduceti numele abilitatii: ";
    is >> ability.name;

    cout << "Introduceti puterea de baza: ";
    is >> ability.basePower;

    cout << "Introduceti coeficientul de putere: ";
    is >> ability.powerCoefficient;

    cout << "Introduceti coeficientul de viata: ";
    is >> ability.healthCoefficient;

    return is;
}


ostream& operator<<(ostream& os, const Ability& ability) {
    os << "Nume: " << ability.name << std::endl;
    os << "Putere de baza: " << ability.basePower << std::endl;
    os << "Coeficient de putere: " << ability.powerCoefficient << std::endl;
    os << "Coeficient de viata: " << ability.healthCoefficient << std::endl;
    return os;
}

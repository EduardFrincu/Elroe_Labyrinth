#include "Monster.h"
#include "CombatAbility.h"
#include "BuffAbility.h"
#include "HealAbility.h"
#include <vector>

Monster::Monster()
{
    strcpy_s(this->name, "");
    strcpy_s(this->species, "");

    this->attackPower = 0;
    this->healthPoints = 0;

    this->i = 0;
    this->j = 0;

    strcpy_s(this->supportBehavior, "");
    strcpy_s(this->invaderBehavior, "");
    strcpy_s(this->defenderBehavior, "");

    this->abilities = vector <Ability*> ();

}

Monster::Monster(char* name, char* species, int attackPower, 
                 int healthPoints, char* supportBehavior, char* invaderBehavior, char* defenderBehavior, int i, int j, vector <Ability*> abilities)
{
    strcpy_s(this->name, name);
    strcpy_s(this->species, species);
    
    this->attackPower = attackPower;
    this->healthPoints = healthPoints;
    this->i = i;
    this->j = j;

    strcpy_s(this->supportBehavior, supportBehavior);
    strcpy_s(this->invaderBehavior, invaderBehavior);
    strcpy_s(this->defenderBehavior, defenderBehavior);

    this->abilities = abilities;

}

Ability* Monster::getAbilityBasedOnBehavior(const char* behavior)
{
    //behavior in (VIOLENT, NO_SUPPORT,CLERIC,SHAMAN)
    Ability* selectedAbility = new Ability();
    if (strcmp(behavior, "VIOLENT") == 0) {
        int maxDamage = 0;
        

        for (int i = 0; i < this->abilities.size(); i++) {

            int damage = this->abilities[i]->calculateEffectivePower(*this);

            if (strcmp(this->abilities[i]->getAbilityCategory(), "Attack") == 0 && damage > maxDamage) {

                maxDamage = damage;
                selectedAbility = this->abilities[i];
            }
        }
    }
    else if (strcmp(behavior, "NO_SUPPORT") == 0) {
        
    }
    else if (strcmp(behavior, "CLERIC") == 0) {
        int maxHealPower = 0;

        for (int i = 0; i < this->abilities.size(); i++) {
            int healPower = this->abilities[i]->calculateEffectivePower(*this);
            if (strcmp(this->abilities[i]->getAbilityCategory(), "Health") == 0 && healPower > maxHealPower) {
                maxHealPower = healPower;
                selectedAbility = this->abilities[i];
            }
        }
     
    }
    else if (strcmp(behavior, "SHAMAN") == 0) {
        int maxBuffPower = 0;

        for (int i = 0; i < this->abilities.size(); i++) {
            int buffPower = this->abilities[i]->calculateEffectivePower(*this);
            if (strcmp(this->abilities[i]->getAbilityCategory(), "PowerUp") == 0 && buffPower > maxBuffPower) {
                maxBuffPower = buffPower;
                selectedAbility = this->abilities[i];
            }
        }
        
    }

    return selectedAbility;
}

const char* Monster::getName() const
{
    return this->name;
}

void Monster::setName(char* name)
{
    strcpy_s(this->name, name);
}

int Monster::getI() const {
    return this->i;
}

void Monster::setI(int i) {
    this->i = i;
}

int Monster::getJ() const {
    return this->j;
}

void Monster::setJ(int j) {
    this->j = j;
}

const char* Monster::getSupportBehavior() const
{
    return this->supportBehavior;
}

void Monster::setSupportBehavior(char* supportBehavior)
{
    strcpy_s(this->supportBehavior, supportBehavior);
}

const char* Monster::getInvaderBehavior() const
{
    return this->invaderBehavior;
}

void Monster::setInvaderBehavior(char* invaderBehavior)
{
    strcpy_s(this->invaderBehavior, invaderBehavior);
}

const char* Monster::getDefenderBehavior() const
{
    return this->defenderBehavior;
}

void Monster::setDefenderBehavior(char* defenderBehavior)
{
    strcpy_s(this->defenderBehavior, defenderBehavior);
}

vector<Ability*> Monster::getAbilities()
{
    return this->abilities;
}

void Monster::setAbilities(vector<Ability*> abilities)
{
    this->abilities = abilities;
}

const char* Monster::getSpecies() const
{
    return this->species;
}

void Monster::setSpecies(char* species)
{
    strcpy_s(this->species, species);
}

int Monster::getAttackPower() const
{
    return this->attackPower;
}

void Monster::setAttackPower(int attackPower) {
    this->attackPower = attackPower;
}

int Monster::getHealthPoints() const
{
    return this->healthPoints;
}

void Monster::setHealthPoints(int healthPoints)
{
    this->healthPoints = healthPoints;
}

void Monster::useAbilityOnOtherMonster(Monster& affectedMonster, char* abilityName)
{  

    for (int i = 0; i < this->abilities.size(); ++i) {
        Ability& a = *this->abilities[i];
        if (strcmp(a.getName(), abilityName)) {
            int effectivePower = a.calculateEffectivePower(*this);
            a.apply(affectedMonster, effectivePower);
        }
    }
}

void Monster::useAbilityOnSameMonster(char* abilityName) {

    for (int i = 0; i < this->abilities.size(); ++i) {
        Ability& a = *this->abilities[i];
        if (strcmp(a.getName(), abilityName)) {
            int effectivePower = a.calculateEffectivePower(*this);
            a.apply(*this, effectivePower);
        }
    }
}

istream& operator>>(istream& is, Monster& monster) {
    cout << "Introduceti numele: "<<endl;
    is>>monster.name;

    cout << "Introduceti specia: " << endl;
    is>>monster.species;

    cout << "Introduceti puterea de atac: " << endl;
    is >> monster.attackPower;

    cout << "Introduceti punctele de viata: " << endl;
    is >> monster.healthPoints;

    cout << "Introduceti coordonata i: " << endl;
    is >> monster.i;

    cout << "Introduceti coordonata j: " << endl;
    is >> monster.j;


    cout << "Introduceti numarul de abilitati: " << endl;

    int abilityCount;
    cin >> abilityCount;

    cout << "Introduceti comportamentul de invadator: " << endl;
    is>>monster.invaderBehavior;

    cout << "Introduceti comportamentul de aparator: " << endl;
    is>>monster.defenderBehavior;

    cout << "Introduceti comportamentul de suport: " << endl;
    is >> monster.supportBehavior;

    vector <Ability*> abilities;

    for (int i = 0; i < abilityCount; i++) {
        char abilityName[20], type[10];
        int basePower, powerCoefficient, healthCoefficient;

        cout << "Introduceti numele abilitatii: " << i + 1 << ": " << endl;
        cin >> abilityName;

        cout << "Introduceti puterea de baza: " << i + 1 << ": " << endl;
        cin >> basePower;

        cout << "Introduceti puterea de atac: " << i + 1 << ": " << endl;
        cin >> powerCoefficient;

        cout << "Introduceti coeficientul de viata: " << i + 1 << ": " << endl;
        cin >> healthCoefficient;

        cout << "Introduceti tipul abilitatii: " << endl;
        cin >> type;

        if (strcmp(type, "COMBAT") == 0) {
            abilities.push_back(new CombatAbility(abilityName, basePower, powerCoefficient, healthCoefficient));


        }
        else if (strcmp(type, "HEAL") == 0) {
            abilities.push_back(new HealAbility(abilityName, basePower, powerCoefficient, healthCoefficient));


        }
        else if (strcmp(type, "BUFF") == 0) {
            abilities.push_back(new BuffAbility(abilityName, basePower, powerCoefficient, healthCoefficient));

        }
    }
    monster.setAbilities(abilities);




    return is;
}

ostream& operator<<(ostream& os, const Monster& monster) {
    os << "Nume: " << monster.name << endl;
    os << "Specie: " << monster.species << endl;
    os << "Putere de atac: " << monster.attackPower << endl;
    os << "Puncte de viata: " << monster.healthPoints << endl;
    os << "Comportament de suport: " << monster.supportBehavior << endl;
    os << "Comportament de invadator: " << monster.invaderBehavior << endl;
    os << "Comportament de aparator: " << monster.defenderBehavior << endl;
    os << "Coordonata i: " << monster.i << endl;
    os << "Coordonata j: " << monster.j << endl;
    os << "Abilitati: " << endl;

    for (int i = 0; i < monster.abilities.size(); i++) {
        os << "\tAbilitatea " << i + 1 << ": " << *(monster.abilities[i]) << std::endl;
    }

    return os;
}
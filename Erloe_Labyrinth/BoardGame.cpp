#include "BoardGame.h"

BoardGame::BoardGame()
{
	this->n = 0;
	this->m = 0;
	this->board = vector<vector<char>>(0, vector<char>());
	this->directions = vector<vector<char>>(0, vector<char>());
	this->monsterCount = 0;
	this->days = 0;
}

BoardGame::BoardGame(vector<vector<char>> matrix, vector <Monster> monsters, vector <vector <char>> directions, int n, int m, int monsterCount, int days) {
	//this->monsters.reserve(monsterCount);
	this->monsters = monsters;

	this->board = matrix;
	this->directions = directions;
	this->n = n;
	this->m = m;
	this->monsterCount = monsterCount;
	this->days = days;
}

bool BoardGame::moveMonster(Monster& monster, char direction)
{
	int new_i = monster.getI();
	int new_j = monster.getJ();

	int n = this->board.size();
	int m = this->board[0].size();
	//cout << new_i << " " << new_j << endl;
	//cout << direction<<endl;

	switch (direction)
	{
		
		case 'N':
			if (new_i > 1) {
				new_i--;
			}
			break;
		case 'S':
			if (new_i < n ) {
				new_i++;
			}
			break;
		case 'E':
			if (new_j < m ) {
				new_j++;
			}
			break;
		case 'V':
			if (new_j > 1) {
				new_j--;
			}
			break;
		default:
			break;
	}

	if(new_i)

	if (this->board[new_i-1][new_j-1] != '#') {
		if (new_i != monster.getI()) {
			monster.setI(new_i);
			return true;
		}
		else if (new_j != monster.getJ()) {
			monster.setJ(new_j);
			return true;
		}
	}
	return false;
	//cout << monster << endl;
}

void BoardGame::fleeMonster(Monster& monster)
{
	char directions[] = "NESV";

	for (int i = 0; i < 4; i++) {
		if (this->moveMonster(monster, directions[i])) {
			return;
		}
	}
}

bool BoardGame::checkIfThereIsAnotherMonster(const Monster& monster)
{
	for (int i = 0; i < this->monsters.size(); i++) {
		if (this->monsters[i].getI() == monster.getI() && 
			this->monsters[i].getJ() == monster.getJ() &&
			strcmp(this->monsters[i].getName(), monster.getName()) != 0) {
			return true;
		}
	}

	return false;
}

Monster* BoardGame::getDefender(const Monster& monster)
{
	for (int i = 0; i < this->monsters.size(); i++) {
		if (this->monsters[i].getI() == monster.getI() && 
			this->monsters[i].getJ() == monster.getJ() && 
			strcmp(this->monsters[i].getName(), monster.getName()) != 0) {
				return &this->monsters[i];
		}
	}
	return nullptr;
}

void BoardGame::removeDeadMonsters()
{
	this->monsters.erase(
		remove_if(this->monsters.begin(), this->monsters.end(), [](const Monster& monster) {
			return monster.getHealthPoints() <= 0;
		}),
		this->monsters.end()
	);
}

void BoardGame::removeDeadFromTableMonsters() {
	for (int i = 0; i < this->monsters.size(); i++) {
		if (this->monsters[i].getHealthPoints() <= 0 && this->monsters[i].getJ() > 0 && this->monsters[i].getI() > 0) {
			this->monsters[i].setJ(-1);
			this->monsters[i].setI(-1);
			this->monsterCount--;
			//remove from directions the set of directions for this monster

			for (auto& row : this->directions) {
				if (i >= 0 && i < row.size()) {
					row.erase(row.begin() + i);
				}
			}
		}
	}
	
}

void BoardGame::game()
{
	for (int i = 0; i < this->days; i++) {
		for (int j = 0; j < this->monsterCount; j++) {
			
			this->moveMonster(this->monsters[j],directions[i][j]);

			bool fight = this->checkIfThereIsAnotherMonster(this->monsters[j]);
			if (fight) {
				
				Monster* defender = this->getDefender(this->monsters[j]);
				if (defender->getHealthPoints() > 0 && this->monsters[j].getHealthPoints() > 0) {
					this->fight((this->monsters[j]), *defender);			
					this->removeDeadFromTableMonsters();
					
				}


			}


		}
	}

}
void BoardGame::printMonsters() {
	for (int i = 0; i < this->monsters.size(); i++) {
		   cout << this->monsters[i];

	}
}

void BoardGame::printTableMonsters() {
	for (int i = 0; i < this->monsters.size(); i++) {
		if (this->monsters[i].getI() > 0 && this->monsters[i].getJ() > 0) {
			cout << this->monsters[i].getName() << " " << this->monsters[i].getSpecies() << " "
				<< this->monsters[i].getAttackPower() << " " << this->monsters[i].getHealthPoints() << " "
				<< this->monsters[i].getI() << " " << this->monsters[i].getJ() << endl;
		}

	}
}

void BoardGame::fight(Monster& invader, Monster& defender)
{
	bool sameSpecies = false;
	bool fled = false;
	bool bothSupport = false;

	const char* invaderSpecies = invader.getSpecies();
	const char* defenderSpecies = defender.getSpecies();

	const char* invaderBehavior;
	const char* defenderBehavior;

	if (strcmp(invaderSpecies, defenderSpecies) == 0) {
		invaderBehavior = invader.getSupportBehavior();
		defenderBehavior = defender.getSupportBehavior();
		sameSpecies = true;
	}
	else {
		invaderBehavior = invader.getInvaderBehavior();
		defenderBehavior = defender.getDefenderBehavior();
	}

	do
	{
		Ability* invaderAbility = invader.getAbilityBasedOnBehavior(invaderBehavior);
		Ability* defenderAbility = defender.getAbilityBasedOnBehavior(defenderBehavior);

		//to apply damage simultaneously we had to calculate the damage before applying it
		int invaderEffectivePower = invaderAbility->calculateEffectivePower(invader);
		int defenderEffectivePower = defenderAbility->calculateEffectivePower(defender);


		if (sameSpecies) {
			invaderAbility->apply(defender, invaderEffectivePower);
			defenderAbility->apply(invader, defenderEffectivePower);

			this->fleeMonster(invader);
			fled = true;
		}
		else {
			invaderAbility->apply(defender, invaderEffectivePower);
			defenderAbility->apply(invader, defenderEffectivePower);

		}

	} while (invader.getHealthPoints() > 0 && defender.getHealthPoints() > 0 && !fled);

	
}





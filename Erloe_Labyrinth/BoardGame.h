#pragma once
#include <iostream>
#include <vector>
#include "Monster.h"
using namespace std;
class BoardGame
{
	private:
		vector <Monster> monsters;
		vector <vector <char>> board;
		vector <vector <char>> directions;
		int n;
		int m;
		int monsterCount;
		int days;
public:
	BoardGame();
	BoardGame(vector <vector <char>> matrix, vector <Monster> monsters, vector <vector <char>> directions,  int n, int m, int monsterCount, int days);
	bool moveMonster(Monster& monster, char direction);
	void fleeMonster(Monster& monster);
	bool checkIfThereIsAnotherMonster(const Monster& monster);
	Monster* getDefender(const Monster& monster);
	void removeDeadMonsters();
	void removeDeadFromTableMonsters();
	void game();
	void printMonsters();
	void printTableMonsters();
	void fight(Monster& invader, Monster& defender);




};


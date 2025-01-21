// Erloe_Labyrinth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Monster.h"
#include "CombatAbility.h"
#include "HealAbility.h"
#include "BuffAbility.h"
#include "BoardGame.h"
using namespace std;


int main()
{

    int n, m, k, d;

    cout << "Dimensiunile matricei: " << endl;
    cin >> n >> m;

    cout << "Introduceti numarul de monstri: " << endl;
    cin >> k;

    cout << "Introduceti numarul de zile: " << endl;
    cin >> d;

    vector<vector<char>> board(n, vector<char>(m));

    cout << "Matricea: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<Monster> monsters(k);
    cout << "Introduceti monstrii: " << endl;

    for (int i = 0; i < k; i++) {
        cin >> monsters[i];
    }

    vector <vector < char >> directions(d, vector<char>(k));

    cout << "Introduceti directiile: " << endl;

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < k; j++) {
            cin >> directions[i][j];
        }
    }

    //create BoardGame;

    BoardGame boardGame = BoardGame(board, monsters, directions, n, m, k, d);

    boardGame.game();

    boardGame.printTableMonsters();

}

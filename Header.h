#pragma once

#ifndef __HEADER_H__

#include "console.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <xstring>
#include <fstream>
#include <synchapi.h>

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

using namespace std;

struct player
{
	string name;
	int win;
	int move;
};

struct setting
{
	bool _5inARow = true;
	bool blockEnds = true;
	int vrt = 10;
	int hrz = 1;
	int n = 13;
	int lan = 1;
	int colX = 249;
	int colO = 252;
	bool X_turn = true;
};

struct index
{
	int i = 0;
	int j = 0;
};

void main();

//Menu functions
int printMenu();
void printTitle(setting st);
void option(int c);
void set(setting& st);

//Save and Load functions
void save(char board[14][14], player p1, player p2, setting st);
string loadMenu(setting st);
void load(char board[14][14], string loadName, player& p1, player& p2, setting& st);
void loadGame(char board[14][14], player& p1, player& p2, index pos, setting st);

//Newgame functions
void inputName(player& p1, player& p2, setting st);
void newGame(player& p1, player& p2, setting st, char board[14][14]);
void createBlankBoard(char board[14][14]);

//Printscreen functions
void printBoard(int n);
void printPlayer(player p1, player p2, setting st);
void printTurn(bool X_turn, setting st);
void printXO(setting st, char board[14][14]);
void printFunc(setting st);
void blinkXO(setting st, int x, int y, int n, int style, bool X_turn);
void printWinner(player p1, player p2, bool X_turn, setting st);
void printCredit();
void printCup(bool X_turn, setting st);
void printDraw(setting st);

//Gameplay functions
void move(setting st, index& pos, char board[14][14], bool& X_turn, player& p1, player& p2, bool& funcCalled);
void gamePlay(setting st, index& pos, char board[14][14], player& p1, player& p2);
void check_tictactoe(setting st, char a[14][14], bool X_turn, bool& endCondition);
void checkVertical(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn);
void checkHorizontal(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn);
void checkSlash(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn);
void checkBackslash(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn);
bool checkDraw(player p1, player p2, setting st);

#endif // !__HEADER_H__


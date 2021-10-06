#include "Header.h"

bool named = false;

string lineNewGame[][2] = { {"Player 1's default checker is ","Nguoi choi 1 mac dinh la " }, {"Player 2's default checker is ","Nguoi choi 2 mac dinh la "}, {"Input player 1's name: ","Hay nhap ten nguoi choi 1: "},{"Input player 2's name: ","Hay nhap ten nguoi choi 2: "},{"Do you want to create new players? ","Ban co muon tao nguoi choi moi? "},{"LOADING","DANG TAI"}};

void inputName(player& p1, player& p2, setting st) //hàm hiện giao diện nhập tên và nhập tên cho trò chơi mới
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	system("cls");
	p1.name = "";
	p2.name = "";
	gotoXY(8, 14);
	cout << lineNewGame[0][st.lan];
	SetConsoleTextAttribute(hConsole, st.colX); 
	cout << "X";
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(8, 16);
	cout << lineNewGame[1][st.lan];
	SetConsoleTextAttribute(hConsole, st.colO);
	cout << "O";
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(8, 5);
	cout << lineNewGame[2][st.lan];
	getline(cin, p1.name);
	gotoXY(8, 7);
	cout << lineNewGame[3][st.lan];
	getline(cin, p2.name);
	named = true;
}

void newGame(player& p1, player& p2, setting st, char board[14][14]) //hàm trò chơi mới, nhập tên khi tạo lần đầu và hỏi thay đổi tên cho những lần kế
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	if (!named && (p1.move == 0 && p2.move == 0))
	{
		inputName(p1, p2, st);
		p1.win = 0;
		p2.win = 0;
	}
	else
	{
		gotoXY(8, 5);
		cout << lineNewGame[4][st.lan] << "(y/n) ";
		char c;
		do
		{
			c = _getch();
		} while ((c != 'y') && (c != 'n'));
		if (c == 'y')
		{
			inputName(p1, p2, st);
			p1.win = 0;
			p2.win = 0;
		}
	}
	p1.move = 0;
	p2.move = 0;
	system("cls");
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(60, 10);
	cout << lineNewGame[5][st.lan];
	for (int i = 0;i < 25;i++)
	{
		gotoXY(50 + i, 12);
		Sleep(80);
	}
	system("cls");
	index pos;
	createBlankBoard(board);
	if (st._5inARow == true)
	{
		printBoard(14);
	}
	else
	{
		gotoXY(0, 4);
		printBoard(3);
	}
	printPlayer(p1, p2, st);
	printFunc(st);
	gamePlay(st, pos, board, p1, p2);
}

void createBlankBoard(char board[14][14]) //hàm tạo mảng game caro trắng
{
	for (int i = 0;i < 14;i++)
	{
		for (int j = 0;j < 14;j++)
		{
			board[i][j]= ' ';
		}
	}
}
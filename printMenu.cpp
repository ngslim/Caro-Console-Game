#include "Header.h"

player p1, p2;
setting st;
char board[14][14];
index pos;

string lineMenu[][2] = { {"1. New game","1. Tro choi moi"},{"2. Continue","2. Tiep tuc"},{"3. Setting","3. Cai dat"},{"4. Credit","4. Thong tin"},{"5. Exit","5. Thoat"} };

int printMenu() //hàm in giao diện đầu của trò chơi
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	system("cls");
	printTitle(st);
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(57, 16);
	cout << lineMenu[0][st.lan];
	gotoXY(57, 17);
	cout << lineMenu[1][st.lan];
	gotoXY(57, 18);
	cout << lineMenu[2][st.lan];
	gotoXY(57, 19);
	cout << lineMenu[3][st.lan];
	gotoXY(57, 20);
	cout << lineMenu[4][st.lan];
	int ipt=0;
	int c = 1;
	int y = 16;
	int x = 57;
	gotoXY(x,y);
	while (ipt != 13)
	{
		ipt = _getch();
		if ((ipt == 119 || ipt == 72) && (c != 1))
		{
			y--;
			gotoXY(x,y);
			c--;
		}
		if ((ipt == 115 || ipt == 80) && (c != 5))
		{
			y++;
			gotoXY(x, y);
			c++;
		}
	}
	return c;
}

void option(int c) //hàm thao tác ở giao diện đầu theo input của người dùng
{
	string loadName = "";
	switch (c)
	{
	case 1: 
		newGame(p1,p2,st,board);
		break;
	case 2: 
		loadName = loadMenu(st);
		if (loadName !="")
		{
			load(board, loadName, p1, p2, st);
		}
		break;
	case 3: 
		set(st);
		break;
	case 4:
		printCredit();
		break;
	case 5: exit(0);
	}
}

void printTitle(setting st) //hàm in chữ CARO bự ở màn hình
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//in C
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(45, 6);
	cout << "  " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	gotoXY(45, 7);
	cout << char(219) << char(219);
	gotoXY(45, 8);
	cout << char(219) << char(219);
	gotoXY(45, 9);
	cout << char(219) << char(219);
	gotoXY(45, 10);
	cout << "  " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	//in A
	SetConsoleTextAttribute(hConsole, st.colX);
	gotoXY(55, 6);
	cout << "  " << char(219) << char(219) << char(219) << char(219);
	gotoXY(55, 7);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	gotoXY(55, 8);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	gotoXY(55, 9);
	cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	gotoXY(55, 10);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	//in R
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(65, 6);
	cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	gotoXY(65, 7);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	gotoXY(65, 8);
	cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
	gotoXY(65, 9);
	cout << char(219) << char(219)<<"  "<< char(219) << char(219);
	gotoXY(65, 10);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	//in O;
	SetConsoleTextAttribute(hConsole, st.colO);
	gotoXY(75, 6);
	cout << "  " << char(219) << char(219) << char(219) << char(219);
	gotoXY(75, 7);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	gotoXY(75, 8);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	gotoXY(75, 9);
	cout << char(219) << char(219) << "    " << char(219) << char(219);
	gotoXY(75, 10);
	cout << "  " << char(219) << char(219) << char(219) << char(219);
}
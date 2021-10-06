#include "Header.h"

string linePrintScreen[][2] = { {"PLAYER 1: ","NGUOI CHOI 1: "},{"PLAYER 2: ","NGUOI CHOI 2: "},{"Win(s): ","Da thang: "},{" Move(s): "," So nuoc di: "},{"2 players use arrow keys or WASD to move","Nguoi choi dung phim mui ten/WASD de di chuyen"},{"and use ENTER to place checkers.","va dung ENTER de danh dau."},{"The winner is the first player to get an","Nguoi chien thang la nguoi dau tien co"},{"unbroken row of 5 X or O.","mot hang lien tuc 5 X hoac O."},{"unbroken row of 3 X or O.","mot hang lien tuc 3 X va O."} };

void printPlayer(player p1, player p2, setting st) //hàm in thông tin người chơi : tên, số bàn thắng, số lượt đã đi
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(80, 3);
	cout << linePrintScreen[0][st.lan];
	SetConsoleTextAttribute(hConsole, st.colX);
	cout << p1.name;
	gotoXY(80, 4);
	SetConsoleTextAttribute(hConsole, 240);
	cout << linePrintScreen[2][st.lan];
	SetConsoleTextAttribute(hConsole, st.colX);
	cout << p1.win;
	SetConsoleTextAttribute(hConsole, 240);
	cout << linePrintScreen[3][st.lan] << p1.move;
	gotoXY(80, 10);
	cout << linePrintScreen[1][st.lan];
	SetConsoleTextAttribute(hConsole, st.colO);
	cout << p2.name;
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(80, 11);
	cout << linePrintScreen[2][st.lan];
	SetConsoleTextAttribute(hConsole, st.colO);
	cout << p2.win;
	SetConsoleTextAttribute(hConsole, 240);
	cout << linePrintScreen[3][st.lan] << p2.move;
}

void printXO(setting st,char board[14][14]) //hàm in X O từ mảng game ra màn hình
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	for (int i = 0;i <= st.n;i++)
	{
		for (int j = 0;j <= st.n;j++)
		{
			if (board[i][j] == 'X')
			{
				SetConsoleTextAttribute(hConsole, st.colX);
				gotoXY(4 * i + st.vrt, 2 * j + st.hrz);
				cout << "X";
				SetConsoleTextAttribute(hConsole, 240);
			}
			if (board[i][j] == 'O')
			{
				SetConsoleTextAttribute(hConsole, st.colO);
				gotoXY(4 * i + st.vrt, 2 * j + st.hrz);
				cout << "O";
				SetConsoleTextAttribute(hConsole, 240);
			}
		}
	}
}

string lineFunc[][2] = { {"(1): Save current game.","(1): Luu game hien tai."},{"(2): Load saved game.","(2): Tai game da luu."},{"(3): Return to main menu.","(3): Tro ve menu chinh."},{"Esc: Exit.","Esc: Thoat."},{"THE WINNER IS ","NGUOI CHIEN THANG LA "} };

void printFunc(setting st) //hàm in thông tin các nút chức năng trong game
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(70, 17);
	cout << linePrintScreen[4][st.lan];
	gotoXY(70, 18);
	cout << linePrintScreen[5][st.lan];
	switch (st._5inARow)
	{
	case true:
		gotoXY(70, 19);
		cout << linePrintScreen[6][st.lan];
		gotoXY(70, 20);
		cout << linePrintScreen[7][st.lan];
		break;
	case false:
		gotoXY(70, 19);
		cout << linePrintScreen[6][st.lan];
		gotoXY(70, 20);
		cout << linePrintScreen[8][st.lan];
	}
	gotoXY(70, 22);
	cout << lineFunc[0][st.lan];
	gotoXY(70, 23);
	cout << lineFunc[1][st.lan];
	gotoXY(70, 24);
	cout << lineFunc[2][st.lan];
	gotoXY(70, 25);
	cout << lineFunc[3][st.lan];
}

void printWinner(player p1, player p2, bool X_turn, setting st)	//hàm in người chiến thắng
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(42, 23);
	cout << lineFunc[4][st.lan];
	if (X_turn)
	{
		SetConsoleTextAttribute(hConsole, st.colO);
		cout << p2.name;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, st.colX);
		cout << p1.name;
	}
	SetConsoleTextAttribute(hConsole, 240);
	cout << " !!!";
}

void blinkXO(setting st, int x, int y, int n, int style, bool X_turn) //hàm hiệu ứng nhấp nháy cho ô cờ chiến thắng
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char checker = 'X';
	int color = st.colX;
	if (X_turn)
	{
		checker = 'O';
		color = st.colO;
	}
	char key = ' ';
	switch (style)
	{
	case 1: //horizontal
		for (int i = 0;i < 10;i++)
		{
			for (int j = 0; j < n;j++)
			{
				gotoXY(4 * x + st.vrt, 2 * (y + j) + st.hrz);
				cout << key;
			}
			if (key == ' ')
			{
				key = checker;
				SetConsoleTextAttribute(hConsole, color);
			}
			else key = ' ';
			Sleep(200);
		}
		break;
	case 2: //vertical
		for (int i = 0;i < 10;i++)
		{
			for (int j = 0; j < n;j++)
			{
				gotoXY(4 * (x + j) + st.vrt, 2 * y + st.hrz);
				cout << key;
			}
			if (key == ' ')
			{
				key = checker;
				SetConsoleTextAttribute(hConsole, color);
			}
			else key = ' ';
			Sleep(200);
		}
		break;
	case 3: //slash
		for (int i = 0;i < 10;i++)
		{
			for (int j = 0; j < n;j++)
			{
				gotoXY(4 * (x + j) + st.vrt, 2 * (y-j) + st.hrz);
				cout << key;
			}
			if (key == ' ')
			{
				key = checker;
				SetConsoleTextAttribute(hConsole, color);
			}
			else key = ' ';
			Sleep(200);
		}
		break;
	case 4: //backslash
		for (int i = 0;i < 10;i++)
		{
			for (int j = 0; j < n;j++)
			{
				gotoXY(4 * (x + j) + st.vrt, 2 * (y + j) + st.hrz);
				cout << key;
			}
			if (key == ' ')
			{
				key = checker;
				SetConsoleTextAttribute(hConsole, color);
			}
			else key = ' ';
			Sleep(200);
		}
	}
}

void printCredit() //hàm in thông tin người làm đồ án
{
	system("cls");
	gotoXY(30, 8);
	cout << "Lam Hong Thanh\t\t\t\t\t18120564";
	gotoXY(30, 11);
	cout << "Pham Dinh Thuc\t\t\t\t\t18120584";
	gotoXY(30, 14);
	cout << "Le Thi Thu Hien\t\t\t\t\t19120224";
	gotoXY(30, 17);
	cout << "Nguyen Si Liem\t\t\t\t\t19120272";
	gotoXY(30, 20);
	cout << "Pham Nhut Quang\t\t\t\t\t19120341";
	_getch();
}

void printTurn(bool X_turn,setting st)	//hàm in hiển thị đang là lượt của người nào
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (X_turn)
	{
		gotoXY(75, 3);
		SetConsoleTextAttribute(hConsole, st.colX);
		cout << char(219) << char(219) << ' ' << char(219);
		gotoXY(75, 10);
		cout << "    ";
	}
	else
	{
		gotoXY(75, 3);
		cout << "    ";
		gotoXY(75, 10);
		SetConsoleTextAttribute(hConsole, st.colO);
		cout << char(219) << char(219) << ' ' << char(219);
	}
	SetConsoleTextAttribute(hConsole, 240);
}


void printCup(bool X_turn, setting st) //hàm in cup chiến thắng
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	char c = 219;
	gotoXY(38, 4);
	SetConsoleTextAttribute(hConsole, 244);
	cout << "  " << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 254);
	cout << c << c << c << c << c << c << c << c << c << c << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 244);
	cout << c << c << c << c;
	gotoXY(38, 5);
	cout << "  " << c << c << "  ";
	SetConsoleTextAttribute(hConsole, 254);
	cout << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 252);
	cout << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 254);
	cout << c << c << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 244);
	cout << "  " << c << c;
	gotoXY(38, 6);
	cout << "  " << c << c << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 254);
	cout << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 252);
	cout << c << c;
	SetConsoleTextAttribute(hConsole, 254);
	cout << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 244);
	cout << c << c << c << c << c << c;
	gotoXY(38, 7);
	cout << "      " << c << c;
	SetConsoleTextAttribute(hConsole, 254);
	cout << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 252);
	cout << c << c;
	SetConsoleTextAttribute(hConsole, 254);
	cout << c << c << c << c;
	SetConsoleTextAttribute(hConsole, 244);
	cout << c << c;
	gotoXY(38, 8);
	SetConsoleTextAttribute(hConsole, 254);
	cout << "        " << c << c << c << c << c << c<<c<<c<<c<<c;
	gotoXY(38, 9);
	SetConsoleTextAttribute(hConsole, 244);
	cout << "          " << c << c << c << c << c << c;
	gotoXY(38, 10);
	cout << "            " << c << c;
	gotoXY(38, 11);
	cout << "            " << c << c;
	gotoXY(38, 12);
	cout << "          " << c << c << c << c << c << c;
	gotoXY(38, 13);
	SetConsoleTextAttribute(hConsole, 246);
	cout << "    " << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c;
	gotoXY(38, 14);
	cout << "    " << c << c << "              " << c << c;
	gotoXY(38, 15);
	cout << "    " << c << c << "              " << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c;
	gotoXY(38, 16);
	cout << "    " << c << c << "              " << c << c << "              " << c << c;
	gotoXY(38, 17);
	cout << "    " << c << c << "              " << c << c << "              " << c << c;
	gotoXY(38, 18);
	cout << "    " << c << c << "              " << c << c << "              " << c << c;
	gotoXY(38, 19);
	cout << "    " << c << c << "              " << c << c << "              " << c << c;
	gotoXY(38, 21);
	SetConsoleTextAttribute(hConsole, 241);
	for (int i = 1;i <= 42;i++)
	{
		cout << c;
	}
	Sleep(400);
	if (X_turn)
	{
		gotoXY(48, 15);
		SetConsoleTextAttribute(hConsole, st.colO);
		cout << c << c << c << c << c << c;
		Sleep(50);
		gotoXY(48, 16);
		cout << c << c << "  " << c << c;
		Sleep(50);
		gotoXY(48, 17);
		cout << c << c << c << c << c << c;
		Sleep(50);
		gotoXY(64, 17);
		SetConsoleTextAttribute(hConsole, st.colX);
		cout << c << c << "  " << c << c;
		Sleep(50);
		gotoXY(64, 18);
		cout << "  " << c << c;
		Sleep(50);
		gotoXY(64, 19);
		cout << c << c << "  " << c << c;
	}
	else
	{
		gotoXY(48, 15);
		SetConsoleTextAttribute(hConsole, st.colX);
		cout << c << c << "  " << c << c;
		Sleep(50);
		gotoXY(48, 16);
		cout << "  " << c << c;
		Sleep(50);
		gotoXY(48, 17);
		cout << c << c << "  " << c << c;
		Sleep(400);
		gotoXY(64, 17);
		SetConsoleTextAttribute(hConsole, st.colO);
		cout << c << c << c << c << c << c;
		Sleep(50);
		gotoXY(64, 18);
		cout << c << c << "  " << c << c;
		Sleep(50);
		gotoXY(64, 19);
		cout << c << c << c << c << c << c;
	}
}

void printDraw(setting st) //hàm in hai người chơi hòa
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	char c = 219;
	system("cls");
	switch (st.lan)
	{
	case 0:
		for (int i = 1;i <= 5;i++)
		{
			gotoXY(40, 12);
			cout << c << c << c << c << c << c << "    " << c << c << c << c << c << c << "      " << c << c << c << c << "    " << c << c << "    " << c << c;
			gotoXY(40, 13);
			cout << c << c << "    " << c << c << "  " << c << c << "    " << c << c << "  " << c << c << "    " << c << c << "  " << c << c << "    " << c << c;
			gotoXY(40, 14);
			cout << c << c << "    " << c << c << "  " << c << c << c << c << c << c << c << c << "  " << c << c << "    " << c << c << "  " << c << c << "    " << c << c;
			gotoXY(40, 15);
			cout << c << c << "    " << c << c << "  " << c << c << "  " << c << c << "    " << c << c << c << c << c << c << c << c << "  " << c << c << c << c << c << c << c << c;
			gotoXY(40, 16);
			cout << c << c << c << c << c << c << "    " << c << c << "    " << c << c << "  " << c << c << "    " << c << c << "  " << c << c << "    " << c << c;
			Sleep(300);
			system("cls");
			Sleep(300);
		}
		break;
	case 1:
		for (int i = 1;i <= 5;i++)
		{
			gotoXY(44, 12);
			cout << c << c << "    " << c << c << "  " << c << c << c << c << c << c << c << c << "    " << c << c << c << c;
			gotoXY(44, 13);
			cout << c << c << "    " << c << c << "  " << c << c << "    " << c << c << "  " << c << c << "    " << c << c;
			gotoXY(44, 14);
			cout << c << c << c << c << c << c << c << c << "  " << c << c << "    " << c << c << "  " << c << c << "    " << c << c;
			gotoXY(44, 15);
			cout << c << c << "    " << c << c << "  " << c << c << "    " << c << c << "  " << c << c << c << c << c << c << c << c;
			gotoXY(44, 16);
			cout << c << c << "    " << c << c << "  " << c << c << c << c << c << c << c << c << "  " << c << c << "    " << c << c;
			Sleep(300);
			system("cls");
			Sleep(300);
		}
	}
}
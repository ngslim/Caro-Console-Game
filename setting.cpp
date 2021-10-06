#include "Header.h"

string lineSetting[][2] = { {"SETTING","CAI DAT"},{"Game mode: ","Kieu game: "},{"Block ends rule? (5-in-a-row only)","Luat chan hai dau? (5-in-a-row only)"},{"Yes","Co   "},{"No ","Khong"},{"Language: ","Ngon ngu: "},{"English   ","Tieng Anh"},{"Vietnamese","Tieng Viet "},{"X's color:","Mau cua X:"},{"O's color:","Mau cua O:"},{"Who goes first?","Ai la nguoi di truoc?"} };

void set(setting& st) //hàm in menu cài đặt và thao tác cài đặt
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	system("cls");
	gotoXY(55, 10);
	cout << lineSetting[0][st.lan];
	gotoXY(30, 13);
	cout << lineSetting[1][st.lan];
	gotoXY(70, 13);
	if (st._5inARow == true)
	{
		cout << "5-in-a-row     ";
	}
	else cout << "Tic tac toe    ";
	gotoXY(30, 15);
	cout << lineSetting[2][st.lan];
	gotoXY(70, 15);
	if (st.blockEnds == true)
	{
		cout << lineSetting[3][st.lan];
	}
	else cout << lineSetting[4][st.lan];
	gotoXY(30, 17);
	cout << lineSetting[5][st.lan];
	gotoXY(70, 17);
	if (st.lan == 0)
	{
		cout << lineSetting[6][st.lan];
	}
	else cout << lineSetting[7][st.lan];
	gotoXY(30, 19);
	cout << lineSetting[8][st.lan];
	gotoXY(70, 19);
	SetConsoleTextAttribute(hConsole, st.colX);
	cout << "X";
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(30, 21);
	cout << lineSetting[9][st.lan];
	gotoXY(70, 21);
	SetConsoleTextAttribute(hConsole, st.colO);
	cout << "O";
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(30, 23);
	cout << lineSetting[10][st.lan];
	gotoXY(70, 23);
	if (st.X_turn)
	{
		cout << "X";
	}
	else cout << "O";
	int c = 1;
	int ipt = 0;
	int y = 13;
	int x = 70;
	gotoXY(x, y);
	while (ipt != 13)
	{
		ipt = _getch();
		if ((ipt == 119 || ipt == 72) && (c != 1))
		{
			y -= 2;
			gotoXY(x, y);
			c--;
		}
		if ((ipt == 115 || ipt == 80) && (c != 6))
		{
			y += 2;
			gotoXY(x, y);
			c++;
		}
		if ((ipt == 'a') || (ipt == 'd') || (ipt == 75) || (ipt == 77))
		{
			switch (c)
			{
			case 1:
				st._5inARow = !st._5inARow;
				if (st._5inARow == true)
				{
					cout << "5-in-a-row     ";
					st.vrt = 10;
					st.hrz = 1;
					st.n = 13;
				}
				else
				{
					cout << "Tic tac toe    ";
					st.vrt = 10;
					st.hrz = 5;
					st.n = 2;
				}
				gotoXY(x, y);
				break;
			case 2:
				st.blockEnds = !st.blockEnds;
				if (st.blockEnds == true)
				{
					cout << lineSetting[3][st.lan];
				}
				else cout << lineSetting[4][st.lan];
				gotoXY(x, y);
				break;
			case 3:
				if (st.lan == 0)
				{
					st.lan = 1;
				}
				else st.lan = 0;
				if (st.lan == 0)
				{
					cout << lineSetting[6][st.lan];
				}
				else cout << lineSetting[7][st.lan];
				gotoXY(x, y);
				break;
			case 4:
				if ((ipt == 'a') || (ipt == 75))
				{
					if (st.colX == 240)
					{
						st.colX = 254;
					}
					else st.colX--;
				}
				if ((ipt == 'd') || (ipt == 77))
				{
					if (st.colX == 254)
					{
						st.colX = 240;
					}
					else st.colX++;
				}
				gotoXY(70, 19);
				SetConsoleTextAttribute(hConsole, st.colX);
				cout << "X";
				SetConsoleTextAttribute(hConsole, 240);
				gotoXY(x, y);
				break;
			case 5:
				if ((ipt == 'a') || (ipt == 75))
				{
					if (st.colO == 240)
					{
						st.colO = 254;
					}
					else st.colO--;
				}
				if ((ipt == 'd') || (ipt == 77))
				{
					if (st.colO == 254)
					{
						st.colO = 240;
					}
					else st.colO++;
				}
				gotoXY(70, 21);
				SetConsoleTextAttribute(hConsole, st.colO);
				cout << "O";
				SetConsoleTextAttribute(hConsole, 240);
				gotoXY(x, y);
				break;
			case 6:
				st.X_turn = 1 - st.X_turn;
				if (st.X_turn)
				{
					cout << "X";
				}
				else cout << "O";
				gotoXY(x, y);
			}
		}
	}
}

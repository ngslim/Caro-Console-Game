#include "Header.h"

string lineSave[][2] = { {"Input save file name: ","Nhap ten file save cua ban: "},{"Your current game has been saved....","Tro choi cua ban da duoc luu...."},{"No save file available....","Khong co file nao duoc luu...."},{"Choose your save file: ","Chon file save cua ban: "} };

void save(char board[14][14], player p1, player p2, setting st) //hàm lưu ván cờ hiện tại
{
	system("cls");
	gotoXY(8, 5);
	cout << lineSave[0][st.lan];
	string savName;
	cin >> savName;
	savName += ".txt";
	ofstream fileSave(savName.c_str());
	p1.name += "\n";
	p2.name += "\n";
	fileSave << p1.name << p2.name;
	fileSave << p1.win << " " << p2.win << endl << p1.move << " " << p2.move << endl;
	fileSave << st._5inARow << " " << st.blockEnds << " " << st.colX << " " << st.colO << " " << st.X_turn;
	for (int i = 0;i < 14;i++)
	{
		for (int j = 0; j < 14;j++)
		{
			fileSave << board[i][j];
		}
	}
	fileSave.close();
	ofstream fileLog("saveLog.txt", ofstream::app);
	fileLog << savName << endl;
	system("cls");
	gotoXY(8, 5);
	cout << lineSave[1][st.lan];
	Sleep(1500);
	fileLog.close();
}

void load(char board[14][14], string loadName, player& p1, player& p2, setting& st) //hàm load ván cờ đã lưu
{
	index pos;
	system("cls");
	ifstream fileLoad(loadName);
	if (!fileLoad)
	{
		gotoXY(8, 5);
		if (st.lan == 0)
		{
			cout << "File has been deleted or no longer available.";
		}
		else
		{
			cout << "File da bi xoa hoac khong the truy cap.";
		}
		_getch();
		return;
	}
	fileLoad >> noskipws;
	int i = 0;
	getline(fileLoad, p1.name);
	getline(fileLoad, p2.name);
	fileLoad >> skipws;
	fileLoad >> p1.win;
	fileLoad >> p2.win;
	fileLoad >> p1.move;
	fileLoad >> p2.move;
	fileLoad >> st._5inARow;
	fileLoad >> st.blockEnds;
	fileLoad >> st.colX;
	fileLoad >> st.colO;
	fileLoad >> st.X_turn;
	fileLoad >> noskipws;
	if (!st._5inARow)
	{
		st.vrt = 10;
		st.hrz = 5;
		st.n = 2;
	}
	else 
	{
		st.vrt = 10;
		st.hrz = 1;
		st.n = 13;
	};
	while (!fileLoad.eof() && i < 14)
	{
		for (int j = 0;j < 14;j++)
		{
			fileLoad >> board[i][j];
		}
		i++;
	}
	fileLoad.close();
	loadGame(board, p1, p2, pos, st);
}

string loadMenu(setting st) //hàm in menu load
{
	system("cls");
	int i = 0;
	string fileList[20];
	ifstream fileLog("saveLog.txt");
	fileLog >> noskipws;
	while (!fileLog.eof())
	{
		getline(fileLog, fileList[i]);
		if (fileList[i] == "") break;
		i++;
	}
	if (fileList[0] == "")
	{
		gotoXY(10, 5);
		cout << lineSave[2][st.lan];
		_getch();
		return "";
	}
	int count = 0;
	i = 0;
	while (fileList[i] != "")
	{
		gotoXY(8, 7 + i);
		cout << fileList[i] << endl;
		count++;
		i++;
	}
	int ipt = 0;
	int c = 0;
	int y = 5;
	int x = 8;
	gotoXY(x, y);
	cout << lineSave[3][st.lan];
	y = 7;
	gotoXY(x, y);
	while (ipt != 13)
	{
		ipt = _getch();
		if ((ipt == 119 || ipt == 72) && (c != 0))
		{
			y--;
			gotoXY(x, y);
			c--;
		}
		if ((ipt == 115 || ipt == 80) && (c != count-1))
		{
			y++;
			gotoXY(x, y);
			c++;
		}
	}
	string loadName = fileList[c];
	return loadName;
}

void loadGame(char board[14][14], player &p1, player &p2, index pos, setting st) //hàm khởi tạo trò chơi đã lưu
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	gotoXY(60, 10);
	if (st.lan == 0)
	{
		cout << "LOADING";
	}
	else cout << "DANG TAI";
	for (int i = 0;i < 25;i++)
	{
		gotoXY(50 + i, 12);
		Sleep(80);
	}
	system("cls");
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
	printXO(st, board);
	gamePlay(st, pos, board, p1, p2);
}
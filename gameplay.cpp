#include "Header.h"

void move(setting st, index& pos, char board[14][14], bool& X_turn, player& p1, player& p2, bool& funcCalled) //hàm di chuyển trên bàn cờ + tương tác với phím input của người chơi
{
	gotoXY(4 * pos.i + st.vrt, 2 * pos.j + st.hrz);
	int c = 0;
	while (c != 13)
	{
		c=_getch();
		if (c == 72 || c == 'w')
		{
			if (pos.j > 0)
			{
				pos.j--;
				gotoXY(4 * pos.i + st.vrt, 2 * pos.j + st.hrz);
			}
		}
		if (c == 80 || c == 's')
		{
			if (pos.j < st.n)
			{
				pos.j++;
				gotoXY(4 * pos.i + st.vrt, 2 * pos.j + st.hrz);
			}
		}
		if (c == 75 || c == 'a')
		{
			if (pos.i > 0)
			{
				pos.i--;
				gotoXY(4 * pos.i + st.vrt, 2 * pos.j + st.hrz);
			}
		}
		if (c == 77 || c == 'd')
		{
			if (pos.i < st.n)
			{
				pos.i++;
				gotoXY(4 * pos.i + st.vrt, 2 * pos.j + st.hrz);
			}
		}
		if (c == '1')
		{
			save(board, p1, p2,st);
			funcCalled = true;
		}
		if (c == '2')
		{
			string loadName = loadMenu(st);
			if (loadName != "")
			{
				load(board, loadName, p1, p2, st);
			}
			funcCalled = true;
		}
		if (c == '3')
		{
			main();
			funcCalled = true;
		}
		if (c == 27)
		{
			exit(0);
		}
	}
	if (board[pos.i][pos.j] == ' ')
	{
		if (X_turn)
		{
			board[pos.i][pos.j] = 'X';
			p1.move++;
			X_turn = false;
		}
		else
		{
			board[pos.i][pos.j] = 'O';
			p2.move++;
			X_turn = true;
		}
	}
	
}

void gamePlay(setting st, index& pos, char board[14][14],player& p1, player& p2) //hàm chơi game, quyết định những gì xảy ra trong mỗi ván chơi
{
	bool X_turn = !st.X_turn;
	bool endCondition = false;
	if (p1.move==p2.move) X_turn = st.X_turn;
	while (1)
	{
		printXO(st, board);
		printPlayer(p1, p2, st);
		bool funcCalled = false;
		printTurn(X_turn, st);
		move(st, pos, board, X_turn, p1, p2, funcCalled);
		if (funcCalled) break;
		if (st._5inARow == true)
		{
			checkVertical(st, pos.i, pos.j, board, endCondition, X_turn);
			checkHorizontal(st, pos.i, pos.j, board, endCondition, X_turn);
			checkSlash(st, pos.i, pos.j, board, endCondition, X_turn);
			checkBackslash(st, pos.i, pos.j, board, endCondition, X_turn);
		}
		else check_tictactoe(st, board, X_turn, endCondition);
		if (endCondition)
		{
			if (X_turn)
			{
				p2.win++;
			}
			else p1.win++;
			printPlayer(p1, p2, st);
			printCup(X_turn, st);
			printWinner(p1, p2, X_turn, st);
			_getch();
			break;
		}
		if (checkDraw(p1, p2, st))
		{
			printDraw(st);
			break;
		}
	}
}

void check_tictactoe(setting st, char a[14][14], bool X_turn, bool& endCondition) //hàm kiểm tra điều kiện thắng cho bàn cờ 3x3
{
	char check = 'X';
	if (X_turn) check = 'O';
	if (a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][0] == check)
	{
		blinkXO(st, 0, 0, 3, 1, X_turn);
		endCondition = true;
	}
	if (a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][0] == check)
	{
		blinkXO(st, 1, 0, 3, 1, X_turn);
		endCondition = true;
	}
	if (a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][0] == check)
	{
		blinkXO(st, 2, 0, 3, 1, X_turn);
		endCondition = true;
	}
	if (a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[0][0] == check)
	{
		blinkXO(st, 0, 0, 3, 2, X_turn);
		endCondition = true;
	}
	if (a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[0][1] == check)
	{
		blinkXO(st, 0, 1, 3, 2, X_turn);
		endCondition = true;
	}
	if (a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[0][2] == check)
	{
		blinkXO(st, 0, 2, 3, 2, X_turn);
		endCondition = true;
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] == check)
	{
		blinkXO(st, 0, 2, 3, 3, X_turn);
		endCondition = true;
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == check)
	{
		blinkXO(st, 0, 0, 3, 4, X_turn);
		endCondition = true;
	}
}

void checkVertical(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn) //hàm kiểm tra thắng cho 5 ô theo hàng
{
	int i = x;
	int j = y;
	while (a[i - 1][j] == a[i][j])
	{
		i--;
	}
	int count = 1;
	while (a[i][j] == a[i + count][j])
	{
		count++;
	}
	if (count == 4)	if (a[i - 1][j] == ' ' && a[i + count][j] == ' ' && i - 1 >= 0 && i + count < 14)
	{
		blinkXO(st, i, j, 4, 2, X_turn);
		endCondition = true;
		return;
	}
	if (count >= 5) if (!st.blockEnds)
	{
		blinkXO(st, i, j, count, 2, X_turn);
		endCondition = true;
	}
	else if ((a[i - 1][j] == ' ' || a[i + count][j] == ' '))
	{
		blinkXO(st, i, j, count, 2, X_turn);
		endCondition = true;
	}
}

void checkHorizontal(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn) //hàm kiểm tra thắng cho 5 ô theo cột
{
	int i = x;
	int j = y;
	while (a[i][j - 1] == a[i][j])
	{
		j--;
	}
	int count = 1;
	while (a[i][j] == a[i][j + count])
	{
		count++;
	}
	if (count == 4)	if (a[i][j - 1] == ' ' && a[i][j + count] == ' ' && j - 1 >= 0 && j + count < 14)
	{
		blinkXO(st, i, j, 4, 1, X_turn);
		endCondition = true;
		return;
	}
	if (count >= 5) if (!st.blockEnds)
	{
		blinkXO(st, i, j, count, 1, X_turn);
		endCondition = true;
	}
	else if (a[i][j - 1] == ' ' || a[i][j + count] == ' ')
	{
		blinkXO(st, i, j, count, 1, X_turn);
		endCondition = true;
	}
}

void checkSlash(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn) //hàm kiểm tra thắng cho 5 ô theo chéo phải
{
	int i = x;
	int j = y;
	while (a[i - 1][j + 1] == a[i][j])
	{
		j++;
		i--;
	}
	int count = 1;
	while (a[i][j] == a[i + count][j - count])
	{
		count++;
	}
	if (count == 4)	if (a[i - 1][j + 1] == ' ' && a[i + count][j - count] == ' ' && (i + count) < 14 && (j - count) >= 0 && i - 1 >= 0 && j + 1 < 14)
	{
		blinkXO(st, i, j, 4, 3, X_turn);
		endCondition = true;
		return;
	}
	if (count >= 5) if (!st.blockEnds)
	{
		blinkXO(st, i, j, count, 3, X_turn);
		endCondition = true;
	}
	else if (a[i - 1][j + 1] == ' ' || a[i + count][j - count] == ' ')
	{
		blinkXO(st, i, j, count, 3, X_turn);
		endCondition = true;
	}
}

void checkBackslash(setting st, int x, int y, char a[14][14], bool& endCondition, bool X_turn) //hàm kiểm tra thắng cho 5 ô theo chéo trái
{
	int i = x;
	int j = y;
	while (a[i - 1][j - 1] == a[i][j])
	{
		j--;
		i--;
	}
	int count = 1;
	while (a[i][j] == a[i + count][j + count])
	{
		count++;
	}
	if (count == 4)	if (a[i - 1][j - 1] == ' ' && a[i + count][j + count] == ' ' && i + count < 14 && j + count < 14 && i - 1 >= 0 && j - 1 >= 0)
	{
		blinkXO(st, i, j, 4, 4, X_turn);
		endCondition = true;
		return;
	}
	if (count >= 5) if (!st.blockEnds)
	{
		blinkXO(st, i, j, count, 4, X_turn);
		endCondition = true;
	}
	else if (a[i - 1][j - 1] == ' ' || a[i + count][j + count] == ' ')
	{
		blinkXO(st, i, j, count, 4, X_turn);
		endCondition = true;
	}
}

bool checkDraw(player p1, player p2, setting st) //hàm kiểm tra điều kiện hòa
{
	if (st._5inARow)
	{
		if (p1.move + p2.move == 196) return true;
	}
	else if (p1.move + p2.move == 9) return true;
	return false;
}

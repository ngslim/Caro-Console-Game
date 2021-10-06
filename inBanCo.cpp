#include "Header.h"

void printBoard()
{
	int n = 14;
	cout << "\t" << char(218) << char(196) << char(196);
	for (int i = 0; i < n - 1; ++i)
	{
		cout << char(196) << char(194) << char(196) << char(196);
	}
	cout << char(196) << char(191) << endl;
	for (int k = 1;k < n;k++)
	{
		cout << "\t";
		for (int i = 0; i < n; ++i) cout << char(179) << "   ";

		cout << char(179) << endl;
		cout << "\t" << char(195) << char(196) << char(196);
		for (int i = 0; i < n - 1; ++i)
		{
			cout << char(196) << char(197) << char(196) << char(196);
		}
		cout << char(196) << char(180) << endl;
	}
	cout << "\t";
	for (int i = 0; i < n; ++i) cout << char(179) << "   ";

	cout << char(179) << endl;
	cout << "\t" << char(192) << char(196) << char(196);
	for (int i = 0; i < n - 1; ++i)
	{
		cout << char(196) << char(193) << char(196) << char(196);
	}
	cout << char(196) << char(217);
}
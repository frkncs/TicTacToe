#include <iostream>

// https://github.com/haarcuba/cpp-text-table
#include "../headers/TextTable.h"

using namespace std;

void InitializeTable(string array[3][3]);

int main()
{
	string inputs[3][3] = { {" ", " ", " "} };

	short row, column;
	bool isPlayerOne = true;

	InitializeTable(inputs);

	while (true)
	{
		char character = isPlayerOne ? 'X' : 'O';

		cout << endl << "Player " << (isPlayerOne ? "1 (X)" : "2 (O)") << endl << "Row : ";
		cin >> row;

		cout << "Column: ";
		cin >> column;

		if (inputs[row][column] != "" && inputs[row][column] != " ")
		{
			system("cls");

			InitializeTable(inputs);

			cout << endl << "Can't place here!" << endl;
			continue;
		}

		inputs[row][column] = isPlayerOne ? "X" : "O";

		InitializeTable(inputs);

		isPlayerOne = !isPlayerOne;
	}

    return 0;
}

void InitializeTable(string inputs[3][3])
{
	TextTable tt = TextTable('-', '|', '+');

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tt.add(" " + inputs[i][j] + " ");
		}
		tt.endOfRow();
	}

	system("cls");

	cout << tt;
}
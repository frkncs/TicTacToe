#include <iostream>
#include <string>

#include "../headers/WinnerChecker.h"

// https://github.com/haarcuba/cpp-text-table
#include "../headers/TextTable.h"

void InitializeTable(std::string (*array)[3]);

int main()
{
	std::string(*inputs)[3] = new std::string[3][3]{
		" ",
		" ",
		" "
	};

	short row, column;
	bool isPlayerOne = true;

	InitializeTable(inputs);

	while (true)
	{
		char character = isPlayerOne ? 'X' : 'O';

		std::cout << "\nPlayer " << (isPlayerOne ? "1 (X)" : "2 (O)") << "\nRow : ";
		std::cin >> row;

		std::cout << "Column: ";
		std::cin >> column;

		if (inputs[row][column] != "" && inputs[row][column] != " ")
		{
			system("cls");

			InitializeTable(inputs);

			std::cout << "\nCan't place here!\n";
			continue;
		}

		inputs[row][column] = isPlayerOne ? "X" : "O";

		InitializeTable(inputs);

		if (WinnerChecker::CheckWinner(inputs, &character))
		{
			std::cout << "\n" << character << " Wins!\n";

			break;
		}

		isPlayerOne = !isPlayerOne;
	}

	delete[] inputs;

	std::cin.get();

    return 0;
}

void InitializeTable(std::string (*inputs)[3]) // To pass 2 dimensional array to a function
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

	std::cout << tt;
}
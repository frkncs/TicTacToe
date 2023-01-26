#include "../headers/WinnerChecker.h"

bool WinnerChecker::CheckWinner(std::string(*inputs)[3], char* charToCheck)
{
	std::string valueToCheck(1, charToCheck[0]);

	// Check rows
	if (CheckRows(inputs, &valueToCheck))
	{
		return true;
	}

	// Check columns
	if (CheckColumns(inputs, &valueToCheck))
	{
		return true;
	}

	// Check diagonal
	if (CheckDiagonal(inputs, &valueToCheck))
	{
		return true;
	}

	return false;
}

bool WinnerChecker::CheckRows(std::string(*array)[3], std::string* valueToCheck)
{
	for (int i = 0; i < 3; i++)
	{
		if (array[i][0] == *valueToCheck && array[i][1] == *valueToCheck && array[i][2] == *valueToCheck)
		{
			return true;
		}
	}

	return false;
}

bool WinnerChecker::CheckColumns(std::string(*array)[3], std::string* valueToCheck)
{
	for (int i = 0; i < 3; i++)
	{
		if (array[0][i] == *valueToCheck && array[1][i] == *valueToCheck && array[2][i] == *valueToCheck)
		{
			return true;
		}
	}

	return false;
}

bool WinnerChecker::CheckDiagonal(std::string(*array)[3], std::string* valueToCheck)
{
	if (array[0][0] == *valueToCheck && array[1][1] == *valueToCheck && array[2][2] == *valueToCheck)
	{
		return true;
	}

	if (array[0][2] == *valueToCheck && array[1][1] == *valueToCheck && array[2][0] == *valueToCheck)
	{
		return true;
	}

	return false;
}
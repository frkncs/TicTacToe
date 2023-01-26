#pragma once

#include <iostream>

class WinnerChecker
{
public:
	WinnerChecker() {}
	static bool CheckWinner(std::string(*arrayToCheck)[3], char* valueToCheck);

private:
	static bool CheckRows(std::string(*arrayToCheck)[3], std::string* valueToCheck);
	static bool CheckColumns (std::string(*arrayToCheck)[3], std::string* valueToCheck);
	static bool CheckDiagonal(std::string(*arrayToCheck)[3], std::string* valueToCheck);

};


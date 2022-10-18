#pragma warning(disable : 4996)
#ifndef USER_FILE_INC
#define USER_FILE_INC
#include <iostream>
#include <string>
#include <conio.h>
#include <regex>
#include <fstream>
#include <chrono>
#include <time.h>

using namespace std;

class userMenu
{

public:

	// ALL VARIABLES
	string username = "test";
	string pin = "pin";
	string inputtedUserName;
	string balanceAmount;
	string depositString;
	int addBalance;
	int pickedNum;
	int lineRead;
	int balanceAmountInt;
	int newBalance;
	int depositInt;
	int flag;
	int balanceFlag = 0;

	// ALL FUNCTIONS
	void openingScreen();
	void loginInput();
	void checkInput(string inputtedUserName);
		int getBalance(string inputtedUserName, int balanceAmountInt, int addBalance);
	void menuScreen(string inputtedUserName, int balanceAmountInt, int addBalance);
		void balanceInquiry(string inputtedUserName, int balanceAmountInt, int addBalance);
		void depositScreen(string inputtedUserName, int addBalance);
		/*void withdrawScreen();
		void changePinScreen();
		void transactionHistory();
		void logOutScreen();*/
	void exitScreen();

	userMenu()
	{

		openingScreen();

	}

};

#endif
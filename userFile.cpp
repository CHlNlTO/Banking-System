#pragma warning(disable : 4996)
#include "userFile.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <regex>
#include <fstream>
#include <chrono>
#include <time.h>

using namespace std;

void userMenu::openingScreen()
{
	system("cls");
	cout << "Welcome to The Bank of BennyShark Commerce!" << endl;

	cout << "1. Login" << endl;
	cout << "2. Exit" << endl << endl;
	cout << "Enter number (1 or 2): ";
	cin >> pickedNum;

	switch (pickedNum)
	{
	case 1:
		loginInput();
		break;
	case 2:
		exitScreen();
		break;
	default:
		cout << "Choose from 1 or 2 only. Try again." << endl;
		system("pause");
		openingScreen();
		break;
	};

}

void userMenu::loginInput()
{

	system("cls");

	cout << "Enter username: ";
	cin >> inputtedUserName;

	checkInput(inputtedUserName);

}

void userMenu::checkInput(string inputtedUserName)
{

	system("cls");

	balanceAmountInt = 0;

	addBalance = 0;

	ifstream file(inputtedUserName + ".txt");

	if (file.is_open())
	{

		cout << "Account succesfully logged in." << endl;
		system("pause");
		file.close();
		menuScreen(inputtedUserName, balanceAmountInt, addBalance);

	}
	else 
		cout << "Account not found. Try again" << endl;
		system("pause");
		loginInput();

}

int userMenu::getBalance(string inputtedUserName, int balanceAmountInt, int addBalance)
{
	if (balanceFlag == 0)
	{
		ifstream depositDetails(inputtedUserName + ".txt");

		lineRead = 0;
		balanceAmount = "";

		while (lineRead != 6 && getline(depositDetails, balanceAmount))
		{

			++lineRead;

		}

		if (lineRead == 6)
		{

			depositDetails >> balanceAmount;

		}

		balanceAmountInt = stoi(balanceAmount);

		depositDetails.close();

		balanceFlag = 1;
	}
	balanceAmountInt += addBalance;

	return balanceAmountInt;

}

void userMenu::menuScreen(string inputtedUserName, int balanceAmountInt, int addBalance)
{

	system("cls");

	pickedNum = 0;

	cout << "Welcome, " << inputtedUserName << ", to The Bank of BennyShark Commerce!" << endl;
	cout << "1. Balance Inquiry" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Change Pin" << endl;
	cout << "5. Transaction History" << endl;
	cout << "6. Log out" << endl << endl;
	cout << "Enter number (1-6): ";
	cin >> pickedNum;

	switch (pickedNum)
	{

		case 1:
			balanceInquiry(inputtedUserName, balanceAmountInt, addBalance);
			break;
		case 2:
			depositScreen(inputtedUserName, addBalance);
			break;
		/*case 3:
			withdrawScreen();
			break;
		case 4:
			changePinScreen();
			break;
		case 5:
			transactionHistory();
			break;
		case 6:
			logOutScreen();
			break;*/
		default:
			cout << "Choose from 1-6 only. Try again." << endl;
			menuScreen(inputtedUserName, balanceAmountInt, addBalance);
			break;
	};

}

void userMenu::balanceInquiry(string inputtedUserName, int balanceAmountInt, int addBalance)
{

	system("cls");

	auto startTime = chrono::system_clock::now();
	auto currentTime = chrono::system_clock::to_time_t(startTime);

	
	cout << "Your balance is " << getBalance(inputtedUserName, balanceAmountInt, addBalance) << " pesos." << endl << "As of " << ctime(&currentTime) << endl
	system("pause");
	menuScreen(inputtedUserName, balanceAmountInt, addBalance);

}

void userMenu::depositScreen(string inputtedUserName, int addBalance)
{

	system("cls");
	
	cout << "Enter amount to deposit: ";
	cin >> depositString;

	for (int i = 0; i < depositString.length(); i++)
	{

		if (isdigit(depositString[i]) == false)
		{

			flag = 1;
			break;

		}
		else
			flag = 0;

	}

	if (flag == 0)
	{

		pickedNum = 0;

		system("cls");

		depositInt = stoi(depositString);

		balanceAmountInt = getBalance(inputtedUserName, balanceAmountInt, addBalance) + depositInt;

		cout << "Your new balance is: " << newBalance << " pesos." << endl;

		/*
		ofstream inputNewBalance;
		inputNewBalance.open(inputtedUserName + ".txt");

		inputNewBalance << newBalance;*/

		system("pause");

		system("cls");

		cout << "1. Deposit Again" << endl;
		cout << "2. Exit Deposit" << endl;
		cout << "Enter number (1 or 2): ";
		cin >> pickedNum;
		
		switch (pickedNum)
		{
			case 1:
				depositScreen(inputtedUserName, addBalance);
				break;
			case 2:
				menuScreen(inputtedUserName, balanceAmountInt, addBalance);
				break;
			default:
				cout << "Choose from 1 or 2 only. Try again." << endl;
				system("pause");
				openingScreen();
				break;



		}

	}
	else if (flag == 1)
	{
		cout << "Input invalid. Try again." << endl;
		system("pause");
		depositScreen(inputtedUserName, addBalance);
	}

}

void userMenu::exitScreen()
{

	system("cls");
	cout << "Thank you for using The Bank of BennyShark Commerce!" << endl << endl << endl << endl << endl;
	exit(0);

}
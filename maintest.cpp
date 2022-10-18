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
    string sessionName;
    int pickedNum;


	// ALL FUNCTIONS
	void openingScreen();
	void loginInput();
	void checkInput(string inputtedUserName);
    void setUserName(string inputtedUserName);
    string getUserName();
    void setDeposit(int initialBalance);
    void getDeposit(int currentBalance);
    void menuScreen();
	/*int getBalance();
	
		void balanceInquiry();
		void depositScreen();
		void withdrawScreen();
		void changePinScreen();
		void transactionHistory();
		void logOutScreen();*/
	void exitScreen();



};


// Main Function
int main()
{

	userMenu userObj;
    userObj.openingScreen();
    
	return 0;

}



// All Function Definitions
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


	ifstream file(inputtedUserName + ".txt");

	if (file.is_open())
	{

        userMenu userObj;
		cout << "Account succesfully logged in." << endl;
		system("pause");
		file.close();
        userObj.setUserName(inputtedUserName);
		menuScreen();

	}
	else 
		cout << "Account not found. Try again" << endl;
		system("pause");
		loginInput();

}

void userMenu::setUserName(string inputtedUserName)
{

    sessionName = inputtedUserName;

}

string userMenu::getUserName()
{

    return sessionName;

}

void userMenu::set

/*
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

}*/

void userMenu::menuScreen()
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
			depositScreen(inputtedUserName, balanceAmountInt, addBalance);
			break;
		case 3:
			withdrawScreen(inputtedUserName, balanceAmountInt, addBalance);
			break;
		case 4:
			changePinScreen();
			break;
		case 5:
			transactionHistory();
			break;
		case 6:
			logOutScreen();
			break;
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
	
	balanceAmountInt = getBalance(inputtedUserName, balanceAmountInt, addBalance);
	
	cout << "Your balance is " << balanceAmountInt << " pesos." << endl << "As of " << ctime(&currentTime) << endl;
	system("pause");
	menuScreen(inputtedUserName, balanceAmountInt, addBalance);

}

void userMenu::depositScreen(string inputtedUserName, int balanceAmountInt, int addBalance)
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

		flag = 0;

		system("cls");

		depositInt = stoi(depositString);

		if (depositInt <= 499)
		{

			system("cls");
			cout << "Deposit must be 500 or higher only. Try Again, hampaslupa." << endl;
			system("pause");
			depositScreen(inputtedUserName, balanceAmountInt, addBalance);
			
		} else

			balanceAmountInt = getBalance(inputtedUserName, balanceAmountInt, addBalance) + depositInt;

			cout << "Your new balance is: " << balanceAmountInt << " pesos." << endl;

			
			ofstream inputNewBalance;
			inputNewBalance.open(inputtedUserName + ".txt");
			inputNewBalance << newBalance;

			system("pause");


			do
			{
				system("cls");
				cin.ignore();
				cout << "1. Deposit Again" << endl;
				cout << "2. Exit Deposit" << endl;
				cout << "Enter number (1 or 2): ";
				cin >> pickedNum;
				
				switch (pickedNum)
				{
					case 1:
						flag = 1;
						depositScreen(inputtedUserName, balanceAmountInt, addBalance);
						break;
					case 2:
						flag = 1;
						menuScreen(inputtedUserName, balanceAmountInt, addBalance);
						break;
					default:
						cout << "Choose from 1 or 2 only. Try again." << endl;
						cin.ignore();
						system("pause");
						break;
				}

			} while (flag == 0);	

	}
	else if (flag == 1)
	{
		cout << "Input invalid. Try again." << endl;
		system("pause");
		depositScreen(inputtedUserName, balanceAmountInt, addBalance);
	}

}

void userMenu::withdrawScreen(string inputtedUserName, int balanceAmountInt, int addBalance)
{

	system("cls");

	cout << "Enter amount to withdraw: ";
	cin >> withdrawString;


}
}*/

void userMenu::exitScreen()
{

	system("cls");
	cout << "Thank you for using The Bank of BennyShark Commerce!" << endl << endl << endl << endl << endl;
	exit(0);
}
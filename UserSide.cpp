#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <chrono>
#include <time.h>
#include <regex>
#include <vector>

using namespace std;

class userSession
{
    private:
        // Private Variables
        string userName;
        string userPin;
    
    public:
        // Public Variables
        string inputName;
        string inputPin;
        string retrievedPin;
        string balanceString;
        string depositString;
        string withdrawString;
        string updatePin;
        string showDetails;
        string pickedString;
        string accountNumber;
        string saveString;
        string checkString;
        int pickedNum = 0;
        int pinFlag = 0;
        int lineRead = 0;
        int balanceFlag = 0;
        int balanceInt = 0;
        int currentBalance = 0;
        int depositInt = 0;
        int depositFlag = 0;
        int withdrawInt = 0;
        int withdrawFlag = 0;
        vector<string> saveBalance;

        // All Functions
        string introDesign();
        string mainDesign();
        void introMenu();
        void loginName();
        void checkName(string inputName);
        void setName(string inputName);
        string getName();
        string takePasswdFromUser();
        void loginPin();
        void checkPin(string inputPin);
        void setPin(string inputPin);
        string getPin();
        void mainMenu();
        void retrieveBalance();
        void setBalance(int balanceInt);
        int getBalance();
        string getTime();
        void balanceMenu();
        bool stringCheck(string depositString);
        void depositMenu();
        void savingBalance();
        void savingDeposit(string saveDeposit);
        void withdrawMenu();
        void savingWithdraw(string saveWithdraw);
        void changePinMenu();
        void changePinScreen();
        string retrieveAccountNumber();
        void transactionHistoryMenu();
        void showTransactionHistoryScreen();
        void logOutMenu();
        void exitScreen();
        enum IN 
        {

        IN_BACK = 8,
        IN_RET = 13
 
        };
};

// Main Function
int main()
{
    // Calling the userSession class to start the program.
    userSession userObj;
    userObj.introMenu();

    return 0;

}

// ALL FUNCTION DEFINITIONS

// Automated Opening Design Function For Multiple Use
string userSession::introDesign()
{

    string introDesign = "\t\t\t\t\t\t\t\t--------------------------------------------------------------------\n\t\t\t\t\t\t\t\t|                                                                  |\n\t\t\t\t\t\t\t\t|                       Welcome To The Bank                        |\n\t\t\t\t\t\t\t\t|                          of BennyShark                           |\n\t\t\t\t\t\t\t\t|                                                                  |\n\t\t\t\t\t\t\t\t--------------------------------------------------------------------\n\t\t\t\t\t\t\t\t|                                                                  |\n";

    // Returns the design to the caller
    return introDesign;
}

// Automated Main UI Design Function For Multiple Use
string userSession::mainDesign()
{
    
    string mainDesign = "\t\t\t\t\t\t\t\t--------------------------------------------------------------------\n\t\t\t\t\t\t\t\t|                                                                  |\n\t\t\t\t\t\t\t\t|                      The Bank Of BennyShark                      |\n\t\t\t\t\t\t\t\t|                                                                  |\n\t\t\t\t\t\t\t\t--------------------------------------------------------------------\n";

    // Returns the design to the caller
    return mainDesign;

}

void userSession::introMenu()
{

    // Clear Screen
    system("cls");

    // Clears The cin For Any Contents
    cin.clear();
    // Print Statements
    cout << introDesign();
    cout << "\t\t\t\t\t\t\t\t|                            1. Login                              |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                            2. Exit                               |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\tEnter number (1 or 2): ";

	cin >> pickedString;
    cin.ignore();

    // Condition Statement
    if (pickedString == "1")
    {

        loginName();

    }
    if (pickedString == "2")
    {

        exitScreen();

    }
    if (pickedString != "1" && pickedString != "2")
        cout << endl << "\t\t\t\t\t\t\t\tChoose from 1 or 2 only. Try again." << endl << endl << "\t\t\t\t\t\t\t\t";
		system("pause");
		introMenu();

}

void userSession::loginName()
{

    // Clear Screen
    system("cls");

    // Print Statement
    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\tEnter username (Press 0 to exit): ";
    getline(cin, inputName);

    // Function Call
    checkName(inputName);

}

// Checking the Database for an Existing File
void userSession::checkName(string inputName)
{

    // Clear Screen
    system("cls");

    if (inputName == "0")
    {

        introMenu();

    }

    // Open File
    ifstream nameFile("DATA\\" + inputName + ".txt");

    // Condition Statement
    if (nameFile.is_open())
    {

        // Close file
        nameFile.close();

        // Passing of name to set function. 
        setName(inputName);

        // Function Call to Proceed
        loginPin();

    }

    else
        cout << mainDesign();
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                   Account not found. Try again.                  |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------"<< endl;
        cout << endl << endl << "\t\t\t\t\t\t\t\t";
        system("pause");
        loginName();

}

// Setting the inputName as the account name for the session.
void userSession::setName(string inputName)
{

    userName = inputName;

}

// Get Function for returning the user session name to be used as an object.
string userSession::getName()
{

    return userName;

}

// Function to hide the password input of user
string userSession::takePasswdFromUser()
{
    // Declares a character to be used for hiding the password
    char sp = '*';

    string passwd = "";
    char ch_ipt;
 
    while (true) 
    {
 
        ch_ipt = getch();
 
        if (ch_ipt == IN::IN_RET)
        {

            cout << endl;
            return passwd;
        
        }
        else if (ch_ipt == IN::IN_BACK && passwd.length() != 0)
        {

            passwd.pop_back();
 
            cout << "\b \b";
 
            continue;
        }
 
        else if (ch_ipt == IN::IN_BACK && passwd.length() == 0)
        {

            continue;
        
        }
 
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

void userSession::loginPin()
{

    system("cls");
    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\tEnter pin (Press 0 to exit): ";
    inputPin = takePasswdFromUser();

    checkPin(inputPin);

}

void userSession::checkPin(string inputPin)
{

    // Clear Screen
    system("cls");

    if (inputPin == "0")
    {

        introMenu();

    }

    // Retrieving pin from the file.
    if (pinFlag == 0)
	{
		ifstream pinFile("DATA\\" + inputName + ".txt");

		lineRead = 0;
		retrievedPin = "";

		while (lineRead != 1 && getline(pinFile, retrievedPin))
		{

			++lineRead;

		}

		if (lineRead == 1)
		{

			pinFile >> retrievedPin;

		}

		pinFlag = 1;

	}

    // Comparing input pin to retrieved pin.
    if (inputPin == retrievedPin)
    {
        cout << mainDesign();
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                   Account succesfully logged in.                 |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------"<< endl;
        setPin(inputPin);
        cout << endl << endl << "\t\t\t\t\t\t\t\t";
        system("pause");
        mainMenu();

    }
    else
        cout << mainDesign();
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                     Incorrect pin. Try again.                    |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------"<< endl;
        cout << endl << endl << "\t\t\t\t\t\t\t\t";
        system("pause");
        loginPin();

}

void userSession::setPin(string inputPin)
{

    userPin = inputPin;

    ifstream readFile("DATA\\" + getName() + ".txt");

    vector<string> accountDetails;
    string line;

    while (getline(readFile, line))
    {
        accountDetails.push_back(line);
    }

    readFile.close();

    ofstream writeFile("DATA\\" + getName() + ".txt");

    for (int i = 0; i < accountDetails.size(); i++)
    {

        if(i != 1)
        {
            writeFile << accountDetails[i] << endl;
        }
        else
            writeFile << userPin << endl;

    }

    writeFile.close();

}

string userSession::getPin()
{

    return userPin;

}

void userSession::mainMenu()
{

    system("cls");

    pickedNum = 0;
    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                 Welcome, " << getName() << "!                         " << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
	cout << "\t\t\t\t\t\t\t\t|                        1. Balance Inquiry                        |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                        2. Deposit                                |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                        3. Withdraw                               |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                        4. Change Pin                             |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                        5. Transaction History                    |" << endl;
	cout << "\t\t\t\t\t\t\t\t|                        6. Log out                                |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\tEnter number (1-6): ";
	cin >> pickedString;

    if (pickedString == "1")
    {    
        balanceMenu();
    }
    if (pickedString == "2")
    { 
        depositMenu();
    }
    if (pickedString == "3")
    {     
        withdrawMenu();
    }
    if (pickedString == "4")
    {    
        changePinMenu();
    }
    if (pickedString == "5")
    {   
        transactionHistoryMenu();
    }
    if (pickedString == "6")
    {     
        logOutMenu();
    }
    if (pickedString != "1" && pickedString != "2" && pickedString != "3" && pickedString != "4" && pickedString != "5" && pickedString != "6")
    {
        cout << endl << "\t\t\t\t\t\t\t\tInput error. Try again.";
        cout << endl << endl << "\t\t\t\t\t\t\t\t";
        system("pause");
        mainMenu();
    }

}

void userSession::retrieveBalance()
{

    system("cls");

    balanceInt = 0;

    if (balanceFlag == 0)
    {

        ifstream depositFile("DATA\\" + getName() + ".txt");

        lineRead = 0;
        
        balanceString = "";

        while (lineRead != 5 && getline(depositFile, balanceString))
        {

            ++lineRead;

        }

        if (lineRead == 5)
        {

            depositFile >> balanceString;

        }

        balanceInt = stoi(balanceString);
        depositFile.close();
        balanceFlag = 1;

        setBalance(balanceInt);

    }

    void getBalance();

}

void userSession::setBalance(int balanceInt)
{

    currentBalance = balanceInt;

}

int userSession::getBalance()
{

    return currentBalance;

}

string userSession::getTime()
{

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    char *timeNow = ctime(&currentTime);

    timeNow[strlen(timeNow) - 1] = '\0';

    return timeNow;

}

void userSession::balanceMenu()
{

    system("cls");

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    retrieveBalance();

    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                    Your balance is " << getBalance() << " pesos.                   |" << endl; 
    cout << "\t\t\t\t\t\t\t\t|                   As of " << getTime() << "                 |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t";
    system("pause");
    mainMenu();

}

bool userSession::stringCheck(string checkString)
{

    for (int i = 0; i < checkString.length(); i++)
    {

        if (isdigit(checkString[i]) == false)
        {

            return false;

        }

    }

    return true;

}

void userSession::depositMenu()
{

    system("cls");

    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\tEnter amount to deposit (Press 0 to exit): ";
    cin >> depositString;

    if (depositString == "0")
    {

        mainMenu();

    }

    if (stringCheck(depositString))
    {

        depositFlag = 0;

    }
    else
        
        depositFlag = 1;


    if(depositFlag == 1)
    {

        system("cls");
        cout << mainDesign();
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                    Input invalid. Try again.                     |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
        cout << endl << "\t\t\t\t\t\t\t\t";
        system("pause");
        depositString = "";
        depositFlag = 0;
        depositMenu();

    }

    if (depositFlag == 0)
    {

        pickedNum = 0;

        system("cls");

        depositInt = stoi(depositString);

        if (depositInt <= 499)
        {

            system("cls");
            
            cout << mainDesign();
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t|               Deposit must be 500 or higher only.                |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
            cout << endl << "\t\t\t\t\t\t\t\t";

            system("pause");

            depositMenu();

        } 
        else

            savingDeposit(depositString);

            retrieveBalance();

            setBalance(getBalance() + depositInt);

            cout << mainDesign();
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t|                 Your new balance is: " << getBalance() << " pesos.                 |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                   As of " << getTime() << "                 |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
            cout << endl << "\t\t\t\t\t\t\t\t";
            system("pause");

            savingBalance();

            setBalance(getBalance());

            do
			{

				system("cls");

                cin.clear();
                // Print Statements
                cout << mainDesign();
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t|                            1. Deposit                            |" << endl;
                cout << "\t\t\t\t\t\t\t\t|                            2. Exit                               |" << endl;
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t\tEnter number (1 or 2): ";

                cin >> pickedString;
                cin.ignore();

                // Condition Statement
                if (pickedString == "1")
                {
                    depositFlag = 1;
                    depositMenu();

                }
                if (pickedString == "2")
                {
                    depositFlag = 1;
                    mainMenu();

                }
                if (pickedString != "1" && pickedString != "2")
                    cout << endl << "\t\t\t\t\t\t\t\tChoose from 1 or 2 only. Try again." << endl << endl << "\t\t\t\t\t\t\t\t";
                    system("pause");

			} while (depositFlag == 0);

    }

}

void userSession::savingBalance()
{

    string updatedBalance = to_string(getBalance());

    ifstream readFile("DATA\\" + getName() + ".txt");

    vector<string> accountDetails;
    string line;

    while (getline(readFile, line))
    {
        accountDetails.push_back(line);
    }

    readFile.close();

    ofstream writeFile("DATA\\" + getName() + ".txt");

    for (int i = 0; i < accountDetails.size(); i++)
    {

        if(i != 5)
        {
            writeFile << accountDetails[i] << endl;
        }
        else
            writeFile << updatedBalance << endl;

    }

    writeFile.close();

}

void userSession::savingDeposit(string saveDeposit)
{

    string depositD = "D";

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    ofstream saveDepositFile("DATA\\" + getName() + ".txt",ios::app);

    saveDepositFile << saveDeposit << "\t\t" << depositD << "\t\t" << ctime(&currentTime);

}

void userSession::withdrawMenu()
{

    system("cls");

    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\tEnter amount to withdraw (Press 0 to exit): ";
    cin >> withdrawString;

    if (withdrawString == "0")
    {

        mainMenu();

    }

    if (stringCheck(withdrawString))
    {

        withdrawFlag = 0;

    }
    else
        
        withdrawFlag = 1;


    if (withdrawFlag == 1)
    {

        system("cls");
        cout << mainDesign();
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                    Input invalid. Try again.                     |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
        cout << endl << "\t\t\t\t\t\t\t\t";
		system("pause");
        withdrawMenu();

    }

    if (withdrawFlag == 0)
    {

        pickedNum = 0;

        system("cls");

        withdrawInt = stoi(withdrawString);

        if (withdrawInt <= 499 )
        {

            system("cls");
            
            cout << mainDesign();
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t|              Withdraw must be 500 or higher only.                |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
            cout << endl << "\t\t\t\t\t\t\t\t";

            system("pause");

            withdrawMenu();

        }

        if (withdrawInt % 100 != 0)
        {

            system("cls");
            
            cout << mainDesign();
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t|            Withdraw must be divisble by 100s only.               |" << endl;
            cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
            cout << endl << "\t\t\t\t\t\t\t\t";

            system("pause");

            withdrawMenu();

        }

        else

            retrieveBalance();

            if (getBalance() - withdrawInt <= 499)
            {

                cout << mainDesign();
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t| Your withdraw amount exceeded the maintaining amount. Try again. |" << endl;
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
                cout << endl << "\t\t\t\t\t\t\t\t";

                system("pause");

                withdrawMenu();

            } else

                savingWithdraw(withdrawString);

                setBalance(getBalance() - withdrawInt);

                cout << mainDesign();
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t|                 Your new balance is: " << getBalance() << " pesos.                 |" << endl;
                cout << "\t\t\t\t\t\t\t\t|                   As of " << getTime() << "                 |" << endl;
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
                cout << endl << "\t\t\t\t\t\t\t\t";
                
                system("pause");
                
                savingBalance();

                setBalance(getBalance());

                

                do
                {
                    system("cls");

                    cin.clear();
                    // Print Statements
                    cout << mainDesign();
                    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                    cout << "\t\t\t\t\t\t\t\t|                            1. Withdraw                           |" << endl;
                    cout << "\t\t\t\t\t\t\t\t|                            2. Exit                               |" << endl;
                    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t\t\t\tEnter number (1 or 2): ";

                    cin >> pickedString;
                    cin.ignore();

                    // Condition Statement
                    if (pickedString == "1")
                    {
                        withdrawFlag = 1;
                        withdrawMenu();

                    }
                    if (pickedString == "2")
                    {
                        withdrawFlag = 1;
                        mainMenu();

                    }
                    if (pickedString != "1" && pickedString != "2")
                        cout << endl << "\t\t\t\t\t\t\t\tChoose from 1 or 2 only. Try again." << endl << endl << "\t\t\t\t\t\t\t\t";
                        system("pause");

                } while (withdrawFlag == 0);

    }

    

}

void userSession::savingWithdraw(string saveWithdraw)
{

    string withdrawW = "W";

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    ofstream saveWithdrawFile("DATA\\" + getName() + ".txt",ios::app);

    saveWithdrawFile << saveWithdraw << "\t\t" << withdrawW << "\t\t" << ctime(&currentTime);

}

void userSession::changePinMenu()
{

    system("cls");

    pickedNum = 0;

    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                           1. Change Pin                          |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                           2. Exit to Menu                        |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\tEnter number (1 or 2 only): ";
    cin >> pickedString;
    cin.ignore();

    // Condition Statement
    if (pickedString == "1")
    {

        changePinScreen();

    }
    if (pickedString == "2")
    {

        mainMenu();

    }
    if (pickedString != "1" && pickedString != "2")
        cout << endl << "\t\t\t\t\t\t\t\tChoose from 1 or 2 only. Try again." << endl << endl << "\t\t\t\t\t\t\t\t";
		system("pause");
		changePinMenu();

}

void userSession::changePinScreen()
{

    system("cls");

    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\tEnter current pin (Press 0 to exit): ";
    inputPin = takePasswdFromUser();

    if (inputPin == "0")
    {

        mainMenu();

    }

    if(inputPin != userPin)
    {

        system("cls");
        cout << mainDesign();
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                    Incorrect pin. Try again.                     |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
        cout << endl << "\t\t\t\t\t\t\t\t";

        system("pause");
        changePinScreen();

    }
    else if (inputPin == userPin)
    {

        while(updatePin.length() != 4 || updatePin == inputPin || stringCheck(updatePin) == false)
        {

            system("cls");
            cout << mainDesign();
            cout << "\t\t\t\t\t\t\t\tEnter new 4-digit pin: ";
            updatePin = takePasswdFromUser();
            
            if (updatePin.length() != 4 || updatePin == inputPin || stringCheck(updatePin) == false)
            {
                system("cls");
                cout << mainDesign();
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t|              Pin must be a new 4-digit combination               |" << endl;
                cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
                cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
                cout << endl << "\t\t\t\t\t\t\t\t";

                system("pause");
            }

        }


        setPin(updatePin);
        system("cls");
        cout << mainDesign();
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                     Pin succesfully updated.                     |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
        cout << endl << "\t\t\t\t\t\t\t\t";

        system("pause");
        mainMenu();

    }

}

string userSession::retrieveAccountNumber()
{

    ifstream accountNumberFile("DATA\\" + getName() + ".txt");

    lineRead = 0;
    
    accountNumber = "";

    while (lineRead != 2 && getline(accountNumberFile, accountNumber))
    {

        ++lineRead;

    }

    if (lineRead == 2)
    {

        accountNumberFile >> accountNumber;

    }

    accountNumberFile.close();

    return accountNumber;

}

void userSession::transactionHistoryMenu()
{

    system("cls");

    pickedString = "";

    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                    1. Show Transaction History                   |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                    2. Exit to Main Menu                          |" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\tEnter number (1 or 2 only): ";
    cin >> pickedString;

    if (pickedString == "1")
    {

        showTransactionHistoryScreen();

    }
    if (pickedString == "2")
    {

        mainMenu();

    }
    if (pickedString != "1" && pickedString != "2")
        cout << endl << "\t\t\t\t\t\t\t\tChoose from 1 or 2 only. Try again." << endl << endl << "\t\t\t\t\t\t\t\t";
		system("pause");
		transactionHistoryMenu();

    

}

void userSession::showTransactionHistoryScreen()
{

    system("cls");
    cout << mainDesign();
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|   Name: " << getName() << endl;
    cout << "\t\t\t\t\t\t\t\t|   Account Number: " << retrieveAccountNumber() << "                                     |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|    Amount            Type             Date of Transaction        |" << endl;

    ifstream showDeetsFile("DATA\\" + getName() + ".txt");
        
    lineRead = 0;
        
    showDetails = "";

    while (lineRead != 6 && getline(showDeetsFile, showDetails))
    {

        ++lineRead;

    }

    if (lineRead == 6)
    {

        while (getline(showDeetsFile, showDetails))
        {
            cout << "\t\t\t\t\t\t\t\t|    " << showDetails << "   |" << endl;
        }
        cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
        cout << "\t\t\t\t\t\t\t\t|                                 As of " << getTime() << "   |" << endl;
        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;

    }

    showDeetsFile.close();


    cout << endl << "\t\t\t\t\t\t\t\t";
    system("pause");
    mainMenu();
    
    
}

void userSession::logOutMenu()
{


    userName = "";
    userPin  = "";
    inputName = "";
    inputPin  = "";
    retrievedPin  = "";
    balanceString  = "";
    depositString  = "";
    withdrawString  = "";
    updatePin  = "";
    showDetails  = "";
    pickedString  = "";
    accountNumber  = "";
    saveString  = "";
    pickedNum = 0;
    pinFlag = 0;
    lineRead = 0;
    balanceFlag = 0;
    balanceInt = 0;
    currentBalance = 0;
    depositInt = 0;
    depositFlag = 0;
    withdrawInt = 0;
    withdrawFlag = 0;

    introMenu();

}

// Exit Function to terminate the program.
void userSession::exitScreen()
{

    system("cls");
	cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                      Thank you for using the                     |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                        Bank of BennyShark                        |"<< endl;
    cout << "\t\t\t\t\t\t\t\t|                                                                  |"<< endl;
    cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------" << endl;
	exit(0);

} 
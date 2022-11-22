#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>    
#include <time.h>   
#include <string>
#include <vector>
#include <regex>
#include <cstdlib>
#include <math.h>
#include <chrono>

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
        string accountType;
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
        string retrieveAccountType();
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


int main()
{
	
    // Calling the userSession class to start the program.
    userSession userObj;
    userObj.introMenu();

    return 0;
}


/*void admin::buffer( string uu ) 
{
    cout << endl << uu << endl;
    for ( int i = 0; i < 18; i++ ) {
        for ( int j = 0; j < i; j++ ) {
            system( "break" );
        }
        system( "break" );
        cout << '\xDF';
        system( "break" );
        for ( int k = 0; k < i; k++ ) {
            system( "break" );
        }
    }
    cout << endl;
}

void admin::loading()
{
	for( int a = 0; a < 30; a++ )
	{
		system("break");
		cout << '\xDF';
		system("break");
	}
}*/

// ALL FUNCTION DEFINITIONS

// Automated Opening Design Function For Multiple Use
string userSession::introDesign()
{
    system("Color 01");
    string introDesign = "--------------------------------------------------------------------\n|                                                                  |\n|                       Welcome To The Bank                        |\n|                          of BennyShark                           |\n|                                                                  |\n--------------------------------------------------------------------\n|                                                                  |\n";

    // Returns the design to the caller
    return introDesign;
}

// Automated Main UI Design Function For Multiple Use
string userSession::mainDesign()
{
    
    string mainDesign = "--------------------------------------------------------------------\n|                                                                  |\n|                      The Bank Of BennyShark                      |\n|                                                                  |\n--------------------------------------------------------------------\n";

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
    cout << "|                            1. Login                              |" << endl;
	cout << "|                            2. Exit                               |" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number (1 or 2): ";

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
        system ("Color 04");
        cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl << "";
		system("pause");
		introMenu();

}

void userSession::loginName()
{

    // Clear Screen
    system("cls");

    // Print Statement
    system("Color 01");
    cout << mainDesign();
    cout << "Enter username (Press 0 to exit): ";
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

        // Close file1
        nameFile.close();

        // Passing of name to set function. 
        setName(inputName);

        // Function Call to Proceed
        loginPin();

    }

    else
        system("Color 04");
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                   Account not found. Try again.                  |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------"<< endl;
        cout << endl << endl << "";
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
    system("Color 01");
    system("cls");
    cout << mainDesign();
    cout << "Enter pin (Press 0 to exit): ";
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
        system("Color 02");
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                   Account succesfully logged in.                 |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------"<< endl;
        setPin(inputPin);
        cout << endl << endl << "";
        system("pause");
        mainMenu();

    }
    else
        system("Color 04");
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                     Incorrect pin. Try again.                    |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------"<< endl;
        cout << endl << endl << "";
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
    system("Color 01");
    pickedNum = 0;
    cout << mainDesign();
    cout << "|                                                                  |" << endl;
    cout << "|                 Welcome, " << getName() << "!                    " << endl;
    cout << "|                                                                  |" << endl;
	cout << "|                        1. Balance Inquiry                        |" << endl;
	cout << "|                        2. Deposit                                |" << endl;
	cout << "|                        3. Withdraw                               |" << endl;
	cout << "|                        4. Change Pin                             |" << endl;
	cout << "|                        5. Transaction History                    |" << endl;
	cout << "|                        6. Log out                                |"<< endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
	cout << "Enter number (1-6): ";
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
        system("Color 04");
        cout << endl << "Input error. Try again.";
        cout << endl << endl << "";
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
    system("Color 02");
    cout << mainDesign();
    cout << "|                                                                  |"<< endl;
    cout << "|                    Your balance is " << getBalance() << " pesos.                   " << endl; 
    cout << "|                   As of " << getTime() << "                 |" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << endl << "";
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
    system("Color 01");
    cout << mainDesign();
    cout << "Enter amount to deposit (Press 0 to exit): ";
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
        system("Color 04");
        system("cls");
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                    Input invalid. Try again.                     |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << endl << "";
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
            system("Color 04");
            cout << mainDesign();
            cout << "|                                                                  |"<< endl;
            cout << "|               Deposit must be 500 or higher only.                |" << endl;
            cout << "|                                                                  |"<< endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << endl << "";

            system("pause");

            depositMenu();

        } 
        else

            savingDeposit(depositString);

            retrieveBalance();

            setBalance(getBalance() + depositInt);
            system("Color 02");
            cout << mainDesign();
            cout << "|                                                                  |"<< endl;
            cout << "|                  Your new balance is: PHP " << getBalance() << "                 " << endl;
            cout << "|                   As of " << getTime() << "                 |" << endl;
            cout << "|                                                                  |"<< endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << endl << "";
            system("pause");

            savingBalance();

            setBalance(getBalance());

            do
			{

				system("cls");
                system("Color 01");
                cin.clear();
                // Print Statements
                cout << mainDesign();
                cout << "|                                                                  |"<< endl;
                cout << "|                            1. Deposit                            |" << endl;
                cout << "|                            2. Exit                               |" << endl;
                cout << "|                                                                  |"<< endl;
                cout << "--------------------------------------------------------------------" << endl;
                cout << "Enter number (1 or 2): ";

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
                system("Color 04");
                if (pickedString != "1" && pickedString != "2")
                    cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl << "";
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
    system("Color 01");
    cout << mainDesign();
    cout << "Enter amount to withdraw (Press 0 to exit): ";
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
        system("Color 04");
        system("cls");
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                    Input invalid. Try again.                     |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << endl << "";
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
            system("Color 04");
            cout << mainDesign();
            cout << "|                                                                  |"<< endl;
            cout << "|              Withdraw must be 500 or higher only.                |" << endl;
            cout << "|                                                                  |"<< endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << endl << "";

            system("pause");

            withdrawMenu();

        }

        if (withdrawInt % 100 != 0)
        {

            system("cls");
            system("Color 04");
            cout << mainDesign();
            cout << "|                                                                  |"<< endl;
            cout << "|            Withdraw must be divisble by 100s only.               |" << endl;
            cout << "|                                                                  |"<< endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << endl << "";

            system("pause");

            withdrawMenu();

        }

        else

            retrieveBalance();

            if (getBalance() - withdrawInt <= 499)
            {
                system("Color 04");
                cout << mainDesign();
                cout << "|                                                                  |"<< endl;
                cout << "| Your withdraw amount exceeded the maintaining amount. Try again. |" << endl;
                cout << "|                                                                  |"<< endl;
                cout << "--------------------------------------------------------------------" << endl;
                cout << endl << "";

                system("pause");

                withdrawMenu();

            } else

                savingWithdraw(withdrawString);

                setBalance(getBalance() - withdrawInt);
                system("Color 02");
                cout << mainDesign();
                cout << "|                                                                  |"<< endl;
                cout << "|                 Your new balance is: PHP " << getBalance() << "                   " << endl;
                cout << "|                   As of " << getTime() << "                 |" << endl;
                cout << "|                                                                  |"<< endl;
                cout << "--------------------------------------------------------------------" << endl;
                cout << endl << "";
                
                system("pause");
                
                savingBalance();

                setBalance(getBalance());

                

                do
                {
                    system("cls");
                    system("Color 01");
                    cin.clear();
                    // Print Statements
                    cout << mainDesign();
                    cout << "|                                                                  |"<< endl;
                    cout << "|                            1. Withdraw                           |" << endl;
                    cout << "|                            2. Exit                               |" << endl;
                    cout << "|                                                                  |"<< endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    cout << "Enter number (1 or 2): ";

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
                    system ("Color 04");
                    if (pickedString != "1" && pickedString != "2")
                        cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl << "";
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
    system("Color 01");
    cout << mainDesign();
    cout << "|                                                                  |"<< endl;
    cout << "|                           1. Change Pin                          |" << endl;
    cout << "|                           2. Exit to Menu                        |" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number (1 or 2 only): ";
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
    system("Color 04");
    if (pickedString != "1" && pickedString != "2")
        cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl << "";
		system("pause");
		changePinMenu();

}

void userSession::changePinScreen()
{

    system("cls");
    system("Color 01");
    cout << mainDesign();
    cout << "Enter current pin (Press 0 to exit): ";
    inputPin = takePasswdFromUser();

    if (inputPin == "0")
    {

        mainMenu();

    }

    if(inputPin != userPin)
    {
        system("Color 04");
        system("cls");
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                    Incorrect pin. Try again.                     |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << endl << "";

        system("pause");
        changePinScreen();

    }
    else if (inputPin == userPin)
    {

        while(updatePin.length() != 4 || updatePin == inputPin || stringCheck(updatePin) == false)
        {
            system("Color 01");
            system("cls");
            cout << mainDesign();
            cout << "Enter new 4-digit pin: ";
            updatePin = takePasswdFromUser();
            
            if (updatePin.length() != 4 || updatePin == inputPin || stringCheck(updatePin) == false)
            {
                system("Color 04");
                system("cls");
                cout << mainDesign();
                cout << "|                                                                  |"<< endl;
                cout << "|              Pin must be a new 4-digit combination               |" << endl;
                cout << "|                                                                  |"<< endl;
                cout << "--------------------------------------------------------------------" << endl;
                cout << endl << "";

                system("pause");
            }

        }

        system("Color 02");
        setPin(updatePin);
        system("cls");
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                     Pin succesfully updated.                     |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << endl << "";

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

string userSession::retrieveAccountType()
{

    ifstream accountTypeFile("DATA\\" + getName() + ".txt");

    lineRead = 0;
    
    accountType = "";

    while (lineRead != 3 && getline(accountTypeFile, accountType))
    {

        ++lineRead;

    }

    if (lineRead == 3)
    {

        accountTypeFile >> accountType;

    }

    accountTypeFile.close();

    return accountType;

}

void userSession::transactionHistoryMenu()
{

    system("cls");

    pickedString = "";
    system("Color 01");
    cout << mainDesign();
    cout << "|                                                                  |"<< endl;
    cout << "|                    1. Show Transaction History                   |" << endl;
    cout << "|                    2. Exit to Main Menu                          |" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number (1 or 2 only): ";
    cin >> pickedString;

    if (pickedString == "1")
    {

        showTransactionHistoryScreen();

    }
    if (pickedString == "2")
    {

        mainMenu();

    }
    system("Color 04");
    if (pickedString != "1" && pickedString != "2")
        cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl << "";
		system("pause");
		transactionHistoryMenu();

    

}

void userSession::showTransactionHistoryScreen()
{
    system("Color 02");
    system("cls");
    cout << mainDesign();
    cout << "|                                                                  |"<< endl;
    cout << "|   Name: " << getName() << endl;
    cout << "|   Account Number: " << retrieveAccountNumber() << "                                     |"<< endl;
    cout << "|   Account Type: " << retrieveAccountType() << "                                          |" << endl;
    cout << "|                                                                  |" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "|    Amount            Type             Date of Transaction        |" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "|                                                                  |"<< endl;
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
            cout << "|    " << showDetails << "   |" << endl;
        }
        cout << "|                                                                  |"<< endl;
        cout << "|                                 As of " << getTime() << "   |" << endl;
        cout << "--------------------------------------------------------------------" << endl;

    }

    showDeetsFile.close();


    cout << endl << "";
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
    system("Color 02");
	cout << "--------------------------------------------------------------------" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "|                      Thank you for using the                     |"<< endl;
    cout << "|                        Bank of BennyShark                        |"<< endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    system("pause");
	exit(0);

} 



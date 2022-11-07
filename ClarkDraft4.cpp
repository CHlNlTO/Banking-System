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
        void introMenu();
        void loginName();
        void checkName(string inputName);
        void setName(string inputName);
        string getName();
        void loginPin();
        void checkPin(string inputPin);
        void setPin(string inputPin);
        string getPin();
        void mainMenu();
        void retrieveBalance();
        void setBalance(int balanceInt);
        int getBalance();
        void balanceMenu();
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
};

// Main Function
int main()
{

    userSession userObj;
    userObj.introMenu();

    return 0;

}

// All Function Definitions
void userSession::introMenu()
{

    // Clear Screen
    system("cls");

    cin.clear();
    // Print Statement
    cout << "Welcome to the Bank of BennyShark Commerce!" << endl;
    cout << "1. Login" << endl;
	cout << "2. Exit" << endl << endl;
	cout << "Enter number (1 or 2): ";

	cin >> pickedNum;
    cin.ignore();
    
    // Condition Statement
    switch (pickedNum)
	{
	case 1:
		loginName();
		break;
	case 2:
		exitScreen();
		break;
	default:
		cout << "Choose from 1 or 2 only. Try again." << endl;
		system("pause");
		introMenu();
		break;
	};

}

void userSession::loginName()
{

    // Clear Screen
    system("cls");

    // Print Statement
    cout << "Enter username: ";
    getline(cin, inputName);

    // Function Call
    checkName(inputName);

}

void userSession::checkName(string inputName)
{

    // Clear Screen
    system("cls");

    // Open File
    ifstream nameFile(inputName + ".txt");

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
        cout << "Account not found. Try again." << endl;
        system("pause");
        loginName();

}

// Setting the inputName as the account name for the session.
void userSession::setName(string inputName)
{

    userName = inputName;

}

// Get Function for the name. To be used as an object.
string userSession::getName()
{

    return userName;

}

void userSession::loginPin()
{

    system("cls");

    cout << "Enter pin: ";
    getline(cin, inputPin);

    checkPin(inputPin);

}

void userSession::checkPin(string inputPin)
{

    // Clear Screen
    system("cls");

    // Retrieving pin from the file.
    if (pinFlag == 0)
	{
		ifstream pinFile(inputName + ".txt");

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

        cout << "Account succesfully logged in." << endl;
        setPin(inputPin);
        system("pause");
        mainMenu();

    }
    else
        cout << "Incorrect pin. Try again." << endl;
        system("pause");
        loginPin();

}

void userSession::setPin(string inputPin)
{

    userPin = inputPin;

    ifstream readFile(getName() + ".txt");

    vector<string> accountDetails;
    string line;

    while (getline(readFile, line))
    {
        accountDetails.push_back(line);
    }

    readFile.close();

    ofstream writeFile(getName() + ".txt");

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

    cout << "Welcome, " << getName() << ", to The Bank of BennyShark Commerce!" << endl;
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
            balanceMenu();
            break;
        case 2:
            depositMenu();
            break;
        case 3:
            withdrawMenu();
            break;
        case 4:
            changePinMenu();
            break;
        case 5:
            transactionHistoryMenu();
            break;
        case 6:
            logOutMenu();
            break;
        default:
            cout << "Input error. Try again.";
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

        ifstream depositFile(getName() + ".txt");

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

void userSession::balanceMenu()
{

    system("cls");

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    retrieveBalance();

    cout << "Your balance is " << getBalance() << " pesos." << endl << "As of " << ctime(&currentTime) << endl;
    system("pause");
    mainMenu();

}

void userSession::depositMenu()
{

    system("cls");

    cout << "Enter amount to deposit (Press 0 to exit): ";
    cin >> depositString;

    if (depositString == "0")
    {

        mainMenu();

    }

    for (int i = 0 ; i < depositString.length(); i++)
    {

        if (isdigit(depositString[i] == false))
        {

            depositFlag = 1;
            break;

        }
        else

            depositFlag = 0;

    }

    if (depositFlag == 0)
    {

        pickedNum = 0;

        system("cls");

        depositInt = stoi(depositString);

        if (depositInt <= 499)
        {

            system("cls");
            
            cout << "Deposit must be 500 or higher only. Try again, hampaslupa." << endl;

            system("pause");

            depositMenu();

        } 
        else

            savingDeposit(depositString);

            retrieveBalance();

            setBalance(getBalance() + depositInt);

            cout << "Your new balance is: " << getBalance() << " pesos." << endl;
            
            savingBalance();

            setBalance(getBalance());

            system("pause");

            do
			{
				system("cls");

                pickedNum = 0;

				cin.ignore();
				cout << "1. Deposit Again" << endl;
				cout << "2. Exit Deposit" << endl;
				cout << "Enter number (1 or 2): ";
				cin >> pickedNum;
				
				switch (pickedNum)
				{
					case 1:
						depositFlag = 1;
						depositMenu();
						break;
					case 2:
						depositFlag = 1;
						mainMenu();
						break;
					default:
						cout << "Choose from 1 or 2 only. Try again." << endl;

						cin.ignore();
						
                        system("pause");
						break;
				}

			} while (depositFlag == 0);

    }

    else if (depositFlag == 1)
    {

        cout << "Input invalid. Try again." << endl;
		system("pause");
        depositMenu();

    }

}

void userSession::savingBalance()
{

    string updatedBalance = to_string(getBalance());

    ifstream readFile(getName() + ".txt");

    vector<string> accountDetails;
    string line;

    while (getline(readFile, line))
    {
        accountDetails.push_back(line);
    }

    readFile.close();

    ofstream writeFile(getName() + ".txt");

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

    ofstream saveDepositFile(getName() + ".txt",ios::app);

    saveDepositFile << saveDeposit << "\t\t" << depositD << "\t\t" << ctime(&currentTime);

}

void userSession::withdrawMenu()
{

    system("cls");

    cout << "Enter amount to withdraw (Press 0 to exit): ";
    cin >> withdrawString;

    if (withdrawString == "0")
    {

        mainMenu();

    }

    for (int i = 0 ; i < withdrawString.length(); i++)
    {

        if (isdigit(withdrawString[i] == false))
        {

            withdrawFlag = 1;
            break;

        }
        else

            withdrawFlag = 0;

    }

    if (withdrawFlag == 0)
    {

        pickedNum = 0;

        system("cls");

        withdrawInt = stoi(withdrawString);

        if (withdrawInt <= 499 || withdrawInt % 100 != 0)
        {

            system("cls");
            
            cout << "Withdraw must be 500 or higher only. Try again, hampaslupa." << endl;

            system("pause");

            withdrawMenu();

        } 
        else

            retrieveBalance();

            if (getBalance() - withdrawInt <= 499)
            {

                cout << "Your withdraw amount exceeded the maintaining amount. Try again." << endl;

                system("pause");

                mainMenu();

            } else

                savingWithdraw(withdrawString);

                setBalance(getBalance() - withdrawInt);

                cout << "Your new balance is: " << getBalance() << " pesos." << endl;
                
                savingBalance();

                setBalance(getBalance());

                system("pause");

                do
                {
                    system("cls");

                    pickedNum = 0;

                    cin.ignore();
                    cout << "1. Withdraw Again" << endl;
                    cout << "2. Exit Withdraw" << endl;
                    cout << "Enter number (1 or 2): ";
                    cin >> pickedNum;
                    
                    switch (pickedNum)
                    {
                        case 1:
                            withdrawFlag = 1;
                            withdrawMenu();
                            break;
                        case 2:
                            withdrawFlag = 1;
                            mainMenu();
                            break;
                        default:
                            cout << "Choose from 1 or 2 only. Try again." << endl;

                            cin.ignore();
                            
                            system("pause");
                            break;
                    }

                } while (withdrawFlag == 0);

    }

    else if (withdrawFlag == 1)
    {

        cout << "Input invalid. Try again." << endl;
		system("pause");
        withdrawMenu();

    }

}

void userSession::savingWithdraw(string saveWithdraw)
{

    string withdrawW = "W";

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    ofstream saveWithdrawFile(getName() + ".txt",ios::app);

    saveWithdrawFile << saveWithdraw << "\t\t" << withdrawW << "\t\t" << ctime(&currentTime);

}

void userSession::changePinMenu()
{

    system("cls");

    pickedNum = 0;

    cout << "1. Change Pin" << endl;
    cout << "2. Exit to Menu" << endl;
    cout << "Enter number (1 or 2 only): ";
    cin >> pickedNum;
    cin.ignore();

    switch (pickedNum)
    {

        case 1:
            changePinScreen();
            break;
        case 2:
            mainMenu();
            break;
        default:
            cout << "Input error. Try again.";
            system("pause");
            changePinMenu();
    
    }

}

void userSession::changePinScreen()
{

    system("cls");

    cout << "Enter current pin: ";
    getline(cin, inputPin);

    if(inputPin != userPin)
    {

        cout << "Incorrect pin. Try again." << endl;
        system("pause");
        changePinScreen();

    }
    else if (inputPin == userPin)
    {

        cout << "Enter new pin: ";
        cin >> updatePin;
        setPin(updatePin);
        cout << "Pin successfully updated.";
        system("pause");
        mainMenu();

    }

}

string userSession::retrieveAccountNumber()
{

    ifstream accountNumberFile(getName() + ".txt");

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

    pickedNum = 0;

    cout << "1. Show Transaction History" << endl;
    cout << "2. Exit to Main Menu" << endl;
    cout << "Enter number (1 or 2 only): ";
    cin >> pickedNum;

    switch (pickedNum)
    {

        case 1:
            showTransactionHistoryScreen();
            break;
        case 2:
            mainMenu();
            break;
        default:
            cout << "Choose from 1 or 2 only. Try again." << endl;
            system("pause");
            system("cls");
            transactionHistoryMenu();

    }

}

void userSession::showTransactionHistoryScreen()
{

    system("cls");

    cout << "Name: " << getName() << endl;
    cout << "Account Number: " << retrieveAccountNumber() << endl << endl; 
    cout << "Amount         Type             Date of Transaction" << endl;

    ifstream showDeetsFile(getName() + ".txt");
        
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
            cout << showDetails << endl;
        }

    }

    showDeetsFile.close();

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
	cout << "Thank you for using The Bank of BennyShark Commerce!" << endl << endl << endl;
	exit(0);

}

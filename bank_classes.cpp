#include "bank_classes.h"

// START OF ALL MENU DEFINITIONS

void mainMenu::main_menu()
{

    system("cls");

    admin adminObj;
    user userObj;

    string choose;

    system ("Color 01");
    cout << adminObj.introdesign();
    cout << "|                                                                  |"<<endl;
    cout << "|                         1.) User Login                           |" << endl;
    cout << "|                         2.) Admin Login                          |" << endl;
    cout << "|                         3.) Exit                                 |" << endl;
    cout << "|                                                                  |"<<endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number (1-3): ";
    getline(cin, choose);

    if (choose != "1" && choose != "2" && choose != "3")
    {

        cout << endl << "Choose from 1 to 3 only. Try again." << endl << endl;
        system("Color 04");
		system("pause");
		main_menu();
    
    }
    
    if (choose == "1")
    {

        userObj.loginName();

    }
    if (choose == "2")
    {

        adminObj.login();

    }
    if (choose == "3")
    {

        exit_screen();

    }

    main_menu();
    
}

// Exit Function to terminate the program.
void mainMenu::exit_screen()
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

// END OF ALL MENU DEFINITIONS





//--------------------------------------------------------------------------//





// START OF ALL USER_SIDE FUNCTION DEFINITIONS

// Automated Main UI Design Function For Multiple Use
string user::mainDesign()
{
    
    string mainDesign = "--------------------------------------------------------------------\n|                                                                  |\n|                      The Bank Of BennyShark                      |\n|                                                                  |\n--------------------------------------------------------------------\n";

    // Returns the design to the caller
    return mainDesign;

}

void user::loginName()
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
void user::checkName(string inputName)
{

    // Clear Screen
    system("cls");

    if (inputName == "0")
    {

        main_menu();

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
    {
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

}

// Setting the inputName as the account name for the session.
void user::setName(string inputName)
{

    userName = inputName;

}

// Get Function for returning the user session name to be used as an object.
string user::getName()
{

    return userName;

}

// Function to hide the password input of user
string user::takePasswdFromUser()
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
            cin.ignore();
        
        }
 
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

void user::loginPin()
{
    system("Color 01");
    system("cls");
    cout << mainDesign();
    cout << "Enter pin (Press 0 to exit): ";
    inputPin = takePasswdFromUser();

    checkPin(inputPin);

}

void user::checkPin(string inputPin)
{

    // Clear Screen
    system("cls");



    if (inputPin == "0")
    {

        main_menu();

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
        elapsedTime();
        mainMenu();

    }
    else
    {
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

}

void user::setPin(string inputPin)
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

string user::getPin()
{

    return userPin;

}

int user::elapsedTime()
{

    static auto start = chrono::steady_clock::now();

    if (interestFlag == 0)
    {
        interestFlag = 1;
        mainMenu();
    }

    auto end = chrono::steady_clock::now();

    return chrono::duration_cast<chrono::seconds>(end - start).count();

}

void user::mainMenu()
{

    system("cls");
    system("Color 01");

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
	getline(cin, pickedString);
    
    if (pickedString != "1" && pickedString != "2" && pickedString != "3" && pickedString != "4" && pickedString != "5" && pickedString != "6" && pickedString != "0")
    {
        system("Color 04");
        //cout << endl << pickedString << endl;
        cout << endl << "Input error. Try again.";
        cout << endl << endl << "";
        system("pause");
        mainMenu();
    }
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
    if (pickedString == "0")
    {     
        logOutMenu();
    }

}

void user::retrieveBalance()
{

    system("cls");

    balanceDouble = 0;

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

        balanceDouble = stod(balanceString);
        depositFile.close();
        balanceFlag = 1;

        setBalance(balanceDouble);

    }

    void getBalance();

}

void user::setBalance(double balanceDouble)
{

    currentBalance = balanceDouble;

}

double user::getBalance()
{

    return currentBalance;

}

string user::getTime()
{

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    char *timeNow = ctime(&currentTime);

    timeNow[strlen(timeNow) - 1] = '\0';

    return timeNow;

}

void user::balanceMenu()
{

    system("cls");

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

bool user::stringCheck(string checkString)
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

void user::depositMenu()
{

    system("cls");
    system("Color 01");
    cout << mainDesign();
    cout << "Enter amount to deposit (Press 0 to exit): ";
    cin >> depositString;

    if (depositString == "0")
    {

        cin.ignore();
        mainMenu();

    }

    if (stringCheck(depositString))
    {

        depositFlag = 0;

    }
    else
        
        depositFlag = 1;


    if(depositFlag == 1 || depositString.length() >= 10)
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

            depositAgain();

    }

}

void user::depositAgain()
{

    system("cls");
    system("Color 01");
    // Print Statements
    cout << mainDesign();
    cout << "|                                                                  |"<< endl;
    cout << "|                            1. Deposit                            |" << endl;
    cout << "|                            2. Exit                               |" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number (1 or 2 only): ";

    cin >> pickedString;
    cin.ignore();

    // Condition Statement
    if (pickedString == "1")
    {

        depositMenu();

    }
    if (pickedString == "2")
    {

        mainMenu();

    }
    if (pickedString != "1" && pickedString != "2")
    {
        system("Color 04");
        cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl;
        system("pause");
        depositAgain();
    }

}

void user::savingBalance()
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

void user::savingDeposit(string saveDeposit)
{

    string depositD = "D";

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    ofstream saveDepositFile("DATA\\" + getName() + ".txt",ios::app);

    saveDepositFile << saveDeposit << "\t\t" << depositD << "\t\t" << ctime(&currentTime);

}

void user::withdrawMenu()
{

    system("cls");
    system("Color 01");
    cout << mainDesign();
    cout << "Enter amount to withdraw (Press 0 to exit): ";
    cin >> withdrawString;

    if (withdrawString == "0")
    {

        cin.ignore();
        mainMenu();

    }

    if (stringCheck(withdrawString))
    {

        withdrawFlag = 0;

    }
    else
        
        withdrawFlag = 1;


    if (withdrawFlag == 1 || withdrawString.length() >= 10)
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

void user::savingWithdraw(string saveWithdraw)
{

    string withdrawW = "W";

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    ofstream saveWithdrawFile("DATA\\" + getName() + ".txt",ios::app);

    saveWithdrawFile << saveWithdraw << "\t\t" << withdrawW << "\t\t" << ctime(&currentTime);

}

void user::changePinMenu()
{

    system("cls");

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
    
    if (pickedString != "1" && pickedString != "2")
        system("Color 04");
        cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl;
		system("pause");
		changePinMenu();

}

void user::changePinScreen()
{

    system("cls");
    system("Color 01");
    cout << mainDesign();
    cout << "Enter current pin (Press 0 to exit): ";
    inputPin = takePasswdFromUser();

    if (inputPin == "0")
    {

        changePinMenu();

    }

    if(inputPin != userPin)
    {

        system("cls");
        
        cout << mainDesign();
        cout << "|                                                                  |"<< endl;
        cout << "|                    Incorrect pin. Try again.                     |" << endl;
        cout << "|                                                                  |"<< endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << endl << "";
        system("Color 04");

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
            cout << "Enter new 4-digit pin (Press 0 to exit): ";
            updatePin = takePasswdFromUser();

            if (updatePin == "0")
            {

                changePinMenu();

            }
            
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

string user::retrieveAccountNumber()
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

string user::retrieveAccountType()
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


    if (accountType == "Savings")
    {

        interestRate = 0.04;
        interestPercentage = "4%";

    }

    if (accountType == "Current")
    {

        interestRate = 0.05;
        interestPercentage = "5%";

    }

    return accountType;

}

void user::transactionHistoryMenu()
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

        calculateInterest();

    }
    if (pickedString == "2")
    {

        cin.ignore();
        mainMenu();

    }
    system("Color 04");
    if (pickedString != "1" && pickedString != "2")
        cout << endl << "Choose from 1 or 2 only. Try again." << endl << endl << "";
		system("pause");
		transactionHistoryMenu();

    

}

void user::savingInterest(double interestRate)
{

    string interestI = "I";

    auto startTime = chrono::system_clock::now();
    auto currentTime = chrono::system_clock::to_time_t(startTime);

    ofstream saveInterestFile("DATA\\" + getName() + ".txt",ios::app);

    saveInterestFile << fixed << setprecision(2) << interestRate << "\t\t" << interestI << "\t\t" << ctime(&currentTime);

}

int user::calculateInterest()
{

    retrieveAccountType();
    retrieveBalance();

    int tempBalanceHolder;

    elapsedSeconds = elapsedTime();

    elapsedSeconds -= initialElapsedSeconds;

    if (elapsedSeconds >= 5)
    {

        initialElapsedSeconds = elapsedSeconds;

        interestRate /= 12;

        interestRate *= getBalance();

        getBalance() + interestRate;

        setBalance(getBalance() + interestRate);

        savingBalance();

        savingInterest(interestRate);

    }

    showTransactionHistoryScreen();

    return 0;

}

void user::showTransactionHistoryScreen()
{
    system("Color 02");
    system("cls");
    cout << mainDesign();
    cout << "|                                                                  |"<< endl;
    cout << "|   Name: " << getName() << endl;
    cout << "|   Account Number: " << retrieveAccountNumber() << "                                   |"<< endl;
    cout << "|   Account Type: " << retrieveAccountType() << "                                          |" << endl;
    cout << "|   Monthly Interest Rate: " << interestPercentage << "                                      |" << endl;
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
    cin.ignore();
    mainMenu();
    
}

void user::logOutMenu()
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
    pinFlag = 0;
    lineRead = 0;
    balanceFlag = 0;
    balanceDouble = 0;
    currentBalance = 0;
    depositInt = 0;
    depositFlag = 0;
    withdrawInt = 0;
    withdrawFlag = 0;
    interestFlag = 0;

    loginName();

}


// END OF ALL USER_SIDE FUNCTION DEFINITIONS





//--------------------------------------------------------------------------//





// START OF ALL ADMIN_SIDE DEFINITIONS

string admin::introdesign()
{
    system ("Color 01");
	 string introDesign = "--------------------------------------------------------------------\n|                                                                  |\n|                       Welcome To The Bank                        |\n|                          of BennyShark                           |\n|                                                                  |\n--------------------------------------------------------------------\n";
	
	return introDesign;
}

string admin::banner()
{   
     system ("Color 01");
	 string baNner = "--------------------------------------------------------------------\n|                                                                  |\n|                        The Bank of BennyShark                    |\n|                                                                  |\n--------------------------------------------------------------------\n";
	
	return baNner;
}

string admin::top_banner()
{

    string topBanner = "|                                                                  |\n";
	
	return topBanner;

}

string admin::bot_banner()
{

    string botBanner = 
    "\n|                                                                  |\n--------------------------------------------------------------------\n";

    return botBanner;

}

void admin::buffer( string uu ) 
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
}

string admin::hidePassWord()
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

//LOGIN AS USER OR ADMIN
void admin::login()
{

    system("cls");

	const string name = "admin";
	const string pass = "1234"; 
	string uname;
	string upass;
	
	cout << banner();
    system ("Color 01");
	cout << "Username (Press 0 to exit): ";
	getline(cin,uname);

    if (uname == "0")
    {

        main_menu();

    }

	cout << "Password (Press 0 to exit): ";
	upass = hidePassWord();

    if (upass == "0")
    {

        main_menu();

    }

	if (name == uname && pass == upass)
	{

		menu();
		
	}
	
	else
	{
        system("cls");
        
        cout << introdesign();
        cout << top_banner();
		cout << "|\t\t     Wrong Username or Password." << "\t\t   |";
        cout << bot_banner();
		system ("Color 04");
        system("pause");
		login();
	}

}

//MAIN MENU ADMIN
void admin::menu()
{
    system("cls");

	string pck;

    system ("Color 01");
    cout << banner();
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t  Welcome, Admin!\t\t\t   |" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t  1. Create Account\t\t\t   |" << endl;
    cout << "|\t\t\t  2. Update Account\t\t\t   |" << endl;
    cout << "|\t\t\t  3. Delete Account\t\t\t   |" << endl;
    cout << "|\t\t\t  4. Show All Users\t\t\t   |"<< endl;
    cout << "|\t\t\t  5. Logout\t\t\t\t   |"<< endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Enter number (1-5): ";
    cin >> pck;
    cin.ignore();

    if (pck == "1")
    {

        crtaccnt();


    }
    if (pck == "2")
    {

        updtaccnt();

    }
    if (pck == "3")
    {

        delaccnt();

    }
    if (pck == "4")
    {

        showallusers();

    }
    if (pck == "5")
    {

        main_menu();

    }
    if (pck != "1" && pck != "2" && pck != "3" && pck != "4" && pck != "5")
    {

        system("Color 04");
        cout << endl << "Input error. Try again." << endl << endl;
		system("pause");
		menu();

    }

}

//FUNCTIONS
void admin::crtaccnt()
{
    system("cls");

    accname = "";

	
    cout << banner();
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t    Register Account\t\t\t   |"<<endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
	cout << "Enter Account Name (Press 0 to exit): ";
    system ("Color 01");
    getline(cin, accname);

    if (accname == "0")
    {

        menu();

    }

    oldaccname = accname;
	convert_to_lowercase();
	regex_check1();
	check_duplicate();
    get_acctype();

}

void admin::get_acctype()
{
    system("cls");

    acctype = "";
    
    string pick;

    cout << banner();
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t  Choose Account Type\t\t\t   |"<< endl;
    cout << "|\t\t\t  1. Savings\t\t\t\t   |" << endl;
    cout << "|\t\t\t  2. Current\t\t\t\t   |" << endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Enter number (Press 0 to Exit): ";
    getline(cin, pick);

    if (pick != "1" && pick != "2" && pick != "0")
    {
        system ("Color 04");
        cout << endl <<"Incorrect input. Try again.\n";
        
        system("pause");
        get_acctype();

    }
    if(pick == "1")
    {

        acctype = "Savings";
    
    }
    if (pick == "2")
    {

        acctype = "Current";
    
    }
    if (pick == "0")
    {

        menu();
    
    }
    
    check_initial_depo();

}

void admin::updtaccnt()
{

    system("cls");    
    
    cout << banner();
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t    Update Account\t\t           |" << endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Enter Account Name (Press 0 to exit): ";
    system ("Color 01");
	getline(cin, accname);

    if (accname == "0")
    {

        menu();



    }

    check_accnt_in_db();

}

void admin::delaccnt()
{

    system("cls");
    
    cout << banner();
    cout << top_banner();
    cout << "|\t\t\t     Delete Account\t\t\t   |";
    cout << bot_banner();
	cout << "Enter Account Name (Press 0 to exit): ";
    system ("Color 01");
	getline(cin,accname);

    if (accname == "0")
    {

        menu();



    }

    ifstream filedelete("DATA\\" + accname + ".txt");

    if (filedelete.is_open())
    {

        system("cls");

        filedelete.close();

        if (delaccnt_ask() == 1)
        {

        string deleteaccnt = "DATA\\" + accname + ".txt";

	    remove(deleteaccnt.c_str());

        system("cls");

        cout << banner();
        cout << top_banner();
        cout << "|\t\t       Account successfully deleted.\t\t   |";
		cout << bot_banner();
        system ("Color 02");


        system("pause");

		menu();

        }



    }


    if (!filedelete.is_open())
    {

        system("cls");

        cout << banner();
        cout << top_banner();
        cout << "|\t\t\t Account does not exists.\t\t   |";
		cout << bot_banner();
        system ("Color 04");

        system("pause");

		delaccnt();



    }

	
}

int admin::delaccnt_ask()
{

    system("cls");
    
    string choose;

    cout << banner();
    cout << "|                                                                  |" << endl;
	cout << "|\t\t\t  Delete " << accname << "?" << endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Enter Y or N: ";
    getline(cin, choose);

    if (choose == "N" || choose == "n")
    {

        delaccnt();


    }

    if (choose != "Y" && choose != "y" && choose != "N" && choose != "n")
    {

        cout << endl << "Input error. Try Again." << endl;
        system("Color 04");
        system("pause");
        delaccnt_ask();



    }

    return 1;

}

void admin::showallusers()
{

    system("cls");

	string allaccnames = "AccountNames.txt";
	ifstream readFile(allaccnames);
	

    string line; 

    cout << banner();
    cout << top_banner();
    while (getline(readFile, line))
    {
        
		cout << "| " << line << "   |" << endl;
    
    }
    cout << "|                                                                  |\n--------------------------------------------------------------------\n";
	
    readFile.close();

    system("pause");
    menu();
}	

//CHOICES FOR UPDATE
void admin::choices_updt()
{

    system("cls");

	string pck;

    cout << banner();
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t     Update Account\t\t\t   |" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t1. Change Account Name\t\t\t   |" << endl;
    cout << "|\t\t\t2. Change Pin\t\t\t\t   |" << endl;
    cout << "|\t\t\t3. Change Account Type\t\t\t   |" << endl;
    cout << "|\t\t\t4. Back to Menu\t\t\t\t   |" << endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Enter number (1-4): ";
    system("Color 01");
    cin >> pck;
    cin.ignore();

    if (pck == "1")
    {

        change_accname();



    }
    if (pck == "2")
    {

        change_pin();



    }
    if (pck == "3")
    {

        change_acctype();



    }
    if (pck == "4")
    {

        menu();



    }
    if (pck != "1" && pck != "2" && pck != "3" && pck != "4")
    {

        cout << endl << "Input error. Try Again." << endl;
        system("Color 04");
        system("pause");
        choices_updt();



    }    


}

//SELECTIONS FOR UPDATE
void admin::change_accname()
{

    system("cls");

	//READ
    ifstream readFile("DATA\\" + accname + ".txt");
	
    vector<string> accountDetails;//accnt details ng buong text file
    string line; 

    while (getline(readFile, line))
    {
        accountDetails.push_back(line);
    }

    readFile.close();
	//READ

	//REWRITE
    cout << banner();
    cout << "|                                                                  |" << endl;
	cout << "|\t\t\t  Change Account Name\t\t           |" << endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
	cout << "Enter New Account Name (Press 0 to exit): ";
    system ("Color 01");
	getline(cin,newaccname);

    if (newaccname == "0")
    {

        choices_updt();

    }

    regex_check2();

    check_duplicate2();

    if (change_accname_ask() == 1)
    {
        ofstream writeFile("DATA\\"+ newaccname + ".txt");

        for (int i = 0; i < accountDetails.size(); i++)
        {

            if(i != 0)//ilalagay yung mga hindi papalitan
            {
                writeFile << accountDetails[i] << endl;
            }
            else
                writeFile << newaccname << endl;//DITO NA MAGPAPALIT

        }
        

        writeFile.close();
        //REWRITE
        
        //DELETE OLD ACCNAME
        accname.append(".txt");

        string deleteaccname = "DATA\\";

        deleteaccname.append(accname);

        remove(deleteaccname.c_str());

        system("cls");

        cout << banner();
        cout << top_banner();
        cout << "|\t\t     Account succesfully changed.   \t\t   |";
        cout << bot_banner();
        system("Color 02");

        system("pause");

        menu();
    }

}

int admin::change_accname_ask()
{

    system("cls");
    
    string choose;

    cout << banner();
    cout << "|                                                                  |" << endl;
	cout << "|\t\t\t  Change " << accname << " to " << newaccname << "?" << endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Enter Y or N: ";
    getline(cin, choose);

    if (choose == "N" || choose == "n")
    {

        change_accname();
        return 0;

    }

    if (choose != "Y" && choose != "y" && choose != "N" && choose != "n")
    {

        cout << endl << "Input error. Try Again." << endl;
        system("Color 04");
        system("pause");
        change_accname_ask();

        return 0;

    }

    return 1;

}

//for change pin
string admin::check_Pin()
{

    pinFlag = 0;

    // Retrieving pin from the file.
    if (pinFlag == 0)
	{
		ifstream pinFile("DATA\\" + accname + ".txt");

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

        pinFile.close();

	}

    return retrievedPin;
    
}

void admin::change_pin()
{

    system("cls");

    check_Pin();

    while(updatePin.length() != 4 || updatePin == retrievedPin || stringCheck(updatePin) == false)
    {
        system("Color 01");
        system("cls");
        cout << banner();
        cout << "Enter new 4-digit pin (Press 0 to exit): ";
        updatePin = hidePassWord();

        if (updatePin == "0")
        {

            choices_updt();

        }

        if (updatePin.length() != 4 || updatePin == retrievedPin || stringCheck(updatePin) == false)
        {
            
            system("cls");
            
            cout << banner();
            cout << "|                                                                  |"<< endl;
            cout << "|              Pin must be a new 4-digit combination.              |" << endl;
            cout << "|                                                                  |"<< endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << endl << "";
            system("Color 04");

            system("pause");
        }

    }

	//READ
    ifstream readFile("DATA\\" + accname + ".txt");
	
    vector<string> accountDetails;//accnt details ng buong text file
    string line; 

    while (getline(readFile, line))
    {
        accountDetails.push_back(line);
    }

    readFile.close();
	//READ

	//REWRITE

    ofstream writeFile("DATA\\"+ accname + ".txt");

    for (int i = 0; i < accountDetails.size(); i++)
    {

        if(i != 1)//ilalagay yung mga hindi papalitan
        {
            writeFile << accountDetails[i] << endl;
        }
        else
            writeFile << updatePin << endl;//DITO NA MAGPAPALIT

    }
	
    writeFile.close();

	system("cls");
    cout << introdesign();
    cout << top_banner();
    cout << "|\t\t     Pin succesfully changed.   \t\t   |";
    cout << bot_banner();
    system("Color 02");

    system("pause");
	menu();
	
}

void admin::change_acctype()
{

    system("cls");

    cout << banner();
	cout << "Enter New Account Type \"Savings or Current\" (Press 0 to exit): ";
    system("Color 01");
	cin >> newacctype;

    if (newacctype == "0")
    {

        choices_updt();

    }

	regex_check3();

    checkacctype();
    
	if (newacctype == retrievedacctype)
    {	
        
        system("cls");
        cout << banner();
        cout << top_banner();
        cout << "|\t\t   Account Type must not be the same.\t\t   |";
        cout << bot_banner();
        system("Color 04");

        system("pause");
        change_acctype();

    }

    if (newacctype != "Savings" && newacctype != "Current")
    {

        system("cls");
        cout << banner();
        cout << top_banner();
        cout << "|\t\t\tInput error. Try again.\t\t\t   |";
        cout << bot_banner();
        system("Color 04");

        system("pause");
        change_acctype();

    }

	//READ
    ifstream readFile("DATA\\" + accname + ".txt");
	
    vector<string> accountDetails;//accnt details ng buong text file
    string line; 

    while (getline(readFile, line))
    {
        accountDetails.push_back(line);
    }

    readFile.close();
	//READ

	//REWRITE
    ofstream writeFile("DATA\\"+ accname + ".txt");

    for (int i = 0; i < accountDetails.size(); i++)
    {

        if(i != 3)//ilalagay yung mga hindi papalitan
        {
            writeFile << accountDetails[i] << endl;
        }
        else
            writeFile << newacctype << endl;//DITO NA MAGPAPALIT

    }
	
    writeFile.close();

	system("cls");
    cout << introdesign();
    cout << top_banner();
    cout << "|\t\t     Account Type succesfully changed.   \t   |";
    cout << bot_banner();
    system("Color 02");

    system("pause");
	menu();
	
}

//CHECKER/CONVERTER
void admin::convert_to_lowercase()
{
    transform(accname.begin(), accname.end(), accname.begin(), :: tolower);
}

//for crtaccnt
string admin::regex_check1()
{

    system("cls");

    if (!regex_match(accname,regex("[A-Za-z.\x20]++")))
    {
    
        cout << banner();
        cout << top_banner();
        cout << "|\t\t    Input contains special character\\s.\t\t   |";
        cout << bot_banner();

        system ("Color 04");
		system("pause");
		system("cls");
		crtaccnt();

    }

    if (regex_match(accname,regex("[\x20]+")))
    {
        
        cout << banner();
        cout << top_banner();
        cout << "|\t\t\tThat is not a name. Try again.\t\t   |";
		cout << bot_banner();

        system ("Color 04");
        system("pause");

		crtaccnt();

    }

    else if  (regex_match(accname,regex("[A-Za-z.\x20]++")))
    {
        return accname;
    }

    return 0;
    
}
//for crtaccnt
void admin::check_duplicate()
{

    system("cls");

    ifstream file1("DATA\\" + accname + ".txt");

    if (file1.is_open())
    {

        cout << banner();
        cout << top_banner();
        cout << "|\t\t\t Account already exists.\t\t   |";
		cout << bot_banner();

        system ("Color 04");
        system("pause");

		crtaccnt();

    }
}
//for changeaccname
string admin::regex_check2()
{
    system("cls");

    if (!regex_match(newaccname,regex("[A-Za-z.\x20]++")))
    {
    
        cout << banner();
        cout << top_banner();
        cout << "|\t\t    Input contains special character\\s.\t\t   |";
        cout << bot_banner();

        system ("Color 04");
		system("pause");
		change_accname();

    }
    
    if (regex_match(newaccname,regex("[\x20]+")))
    {
        
        cout << banner();
        cout << top_banner();
        cout << "|\t\t\tThat is not a name. Try again.\t\t   |";
		cout << bot_banner();

        system ("Color 04");
        system("pause");

		change_accname();
    }
	
    else if (regex_match(newaccname,regex("[A-Za-z.\x20]++")))
    {
        return newaccname;
    }
    
    return 0;
}

void admin::check_duplicate2()
{

    system("cls");

    ifstream file1("DATA\\" + newaccname + ".txt");

    if (file1.is_open())
    {

        cout << banner();
        cout << top_banner();
        cout << "|\t\t Account with that name already exists.\t\t   |";
		cout << bot_banner();

        system ("Color 04");
        file1.close();
        system("pause");

		change_accname();

    }
}

//for updtaccnt
void admin::check_accnt_in_db()
{

    system("cls");

    ifstream file1("DATA\\" + accname + ".txt");
    
    if (file1.is_open())
    {

		file1.close();

		choices_updt();

    }

	else
    {

        cout << banner();
        cout << top_banner();
        cout << "|\t\t\t Account Does Not Exist.\t\t   |";
        cout << bot_banner();
        system ("Color 04");

		system("pause");
		updtaccnt();

    }


}

void admin::check_initial_depo()
{
	string initial_depo;
    int depo_int;
    system("cls");

    system ("Color 01");
    cout << banner();
    cout << "Enter Initial Deposit (Press 0 to exit): ";
    cin >> initial_depo;

    if (initial_depo == "0")
    {

        menu();

    }

    if (!stringCheck(initial_depo))
    {

        system("cls");
        cout << introdesign();
        cout << top_banner();
        cout << "|                    Input invalid. Try again.                     |";
        cout << bot_banner();
        system("Color 04");
        system("pause");
        check_initial_depo();

    }

    depo_int = stoi(initial_depo);
    
    if (depo_int < 500 )
    {

        system("cls");
        cout << introdesign();
        cout << top_banner();
        cout << "|             Initial deposit must be greater than 500.            |";
        cout << bot_banner();
        system("Color 04");
        system("pause");
        check_initial_depo();
        
    }
	else
    {

        depo = depo_int;
        input_to_db();
        menu();
	}

}

//for change pin 
bool admin::stringCheck(string checkString)
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

//for change acctype
void admin::checkacctype()
{
    // Retrieving acctype from the file.

    typeflag = 0;

    if (typeflag == 0)
	{

		ifstream accountTypeFile("DATA\\" + accname + ".txt");

		lineRead = 0;
		retrievedacctype = "";

		while (lineRead != 3 && getline(accountTypeFile, retrievedacctype))
		{

			++lineRead;

		}

		if (lineRead == 3)
		{
			accountTypeFile >> retrievedacctype;
		}

		typeflag = 1;

	}
}
//for change acctype regex
string admin::regex_check3()
{
    system("cls");

    if (!regex_match(newacctype,regex("[A-Za-z.\x20]++")))
    {
    
        cout << banner();
        cout << top_banner();
        cout << "|\t\t    Input contains special character\\s.\t\t   |";
        cout << bot_banner();

        system ("Color 04");
		system("pause");
		system("cls");
		change_accname();

    }
    
    if (regex_match(newacctype,regex("[\x20]+")))
    {
        
        cout << banner();
        cout << top_banner();
        cout << "|\t\t\tThat is not a name. Try again.\t\t   |";
		cout << bot_banner();

        system ("Color 04");
        system("pause");

		change_accname();
    }
	
    else if  (regex_match(newacctype,regex("[A-Za-z.\x20]++")))
    {
        return newacctype;
    }
    
    return 0;
}
//PUT TO DB
void admin:: put_to_db_accname(ofstream& f)
{
	f << accname ;
}

void admin::put_to_db_defpin(ofstream& f)
{
		pin = "1234"; 
		f << endl << pin << endl;
}

void admin::put_to_db_accno(ofstream& f)
{
    time_t currentDate;
    tm* pointerDate;

    char accountNumber[12];
    time(&currentDate);
  
    pointerDate = localtime(&currentDate);

    strftime(accountNumber, 12, "%Y%m%d", pointerDate);

    f << accountNumber;
    srand(time(0));

    for (int  i = 1; i <= 4; i++) 
    {
            f << rand() % 10;
    }
	
	cout << endl;
}

void admin::put_to_db_acctype(ofstream& f)
{

	f << endl << acctype;

}

void admin::date_created(ofstream& f)
{

   time_t timetoday;
   time(&timetoday);
   f << endl << asctime(localtime(&timetoday));

}

void admin::put_to_db_acctype_depo(ofstream& f)
{

	f << depo;

}

void admin::save_accname_to_db(ofstream& f)
{	
	time_t timetoday;
    time (&timetoday);

	transform(accname.begin(), accname.end(), accname.begin(), :: toupper);
	
	f << accname << "\t\t\t" << asctime(localtime(&timetoday)); ;
}

//INPUT TO DB
void admin::input_to_db()
{

    system("cls");

    string choose;

    cout << introdesign();
    cout << top_banner();
    cout <<"|\t\t   Create " << accname << " account?\t\t";
    cout << bot_banner();
    cout << "Enter Y or N: ";
    cin >> choose;

    if (choose != "Y" && choose != "y" && choose != "N" && choose != "n")
    {

        cout << endl << "Input error. Try Again." << endl;
        system("Color 04");
        system("pause");
        input_to_db();

    }

    if (choose == "N" || choose == "n")
    {

        menu();

    }

    if (choose == "Y" || choose == "y")
    {

        admin adm;
        ofstream file;
        ofstream file1;
        file.open("DATA\\" + accname + ".txt",ios::app);
        file1.open("AccountNames.txt",ios::app);

        //save to text file
        put_to_db_accname(file);
        put_to_db_defpin(file);
        put_to_db_accno(file);
        put_to_db_acctype(file);
        date_created(file);
        put_to_db_acctype_depo(file);
        save_accname_to_db(file1);

        system("cls");

        cout << banner();
        cout << top_banner();
        cout << "|\t\t      Account successfully created.\t\t   |";
        cout << bot_banner();
        system("Color 02");

        system("pause");

    }

}
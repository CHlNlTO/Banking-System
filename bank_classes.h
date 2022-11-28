#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>
#include <regex>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <vector>
#include <chrono>
#include <stdio.h>
#include <filesystem>
#include <iomanip>

using namespace std;

class mainMenu
{

    public:
        // Prints the Main Menu Screen
        void main_menu();
        // Prints the Exit Screen
        void exit_screen();

};

class user: public mainMenu
{
    private:
        // Private Variable to store username information
        string userName;
        // Private Variable to store password information
        string userPin;
    
    public:
        // Public Variables

        // User-inputted variable in the current user session
        string inputName;
        
        // User-inputted variable in the current user session
        string inputPin;

        // Pin retrieved from the account text file
        string retrievedPin;

        // String that holds the current account's balance
        string balanceString;

        // User-inputted variable that will pass different functions to check for errors 
        string depositString;
        string withdrawString;

        // New user-inputted pin to change current pin
        string updatePin;
        
        // Holds lines of transaction details from text file for printing
        string showDetails;
        
        // Holds the value for picking different options. Used in multiple functions.
        string pickedString;

        // Stores the retrieved account number from the retrieveAccountNumber function
        string accountNumber;

        // Stores the retrieved account type from the retrieveAccountType function
        string accountType;

        // Flags for signal
        int interestFlag = 0;
        int pinFlag = 0;
        int balanceFlag = 0;
        int depositFlag = 0;
        int withdrawFlag = 0;
        
        // Flag that reads lines in text files
        int lineRead = 0;
        
        // Double that holds the current account's balance
        double balanceDouble = 0;
        double currentBalance = 0;

        // Int that holds user-inputted amount
        int depositInt = 0;
        int withdrawInt = 0;

        // Int that holds account's interest rate based on account type
        double interestRate = 0;
        int elapsedSeconds = 0;
        int initialElapsedSeconds = 0;
        string interestPercentage;

        // Holder of text file's details
        vector<string> saveBalance;

        // All Functions

        // Function that returns the banner design
        string mainDesign();

        // Functions for getting current session's username and password
        void loginName();
        void checkName(string inputName);
        void setName(string inputName);
        string getName();
        string takePasswdFromUser();
        void loginPin();
        void checkPin(string inputPin);
        void setPin(string inputPin);
        string getPin();

        // Saves the initial user session time
        int elapsedTime();

        // Shows the user's main menu
        void mainMenu();

        // Handles the user's balance details 
        void retrieveBalance();
        void setBalance(double balanceDouble);
        double getBalance();
        string getTime();
        void balanceMenu();


        void savingBalance();

        // Check for the user-input for strings
        bool stringCheck(string checkString);

        // Handles the deposit feature
        void depositMenu();
        void depositAgain();
        void savingDeposit(string saveDeposit);

        // Handles the withdraw feature
        void withdrawMenu();
        void savingWithdraw(string saveWithdraw);

        // Handles the change pin feature
        void changePinMenu();
        void changePinScreen();

        // Handles the printing of transaction history with interest rate
        string retrieveAccountNumber();
        string retrieveAccountType();
        void savingInterest(double interestRate);
        void transactionHistoryMenu();
        int calculateInterest();
        void showTransactionHistoryScreen();

        // Resets all the variables used in the current session
        void logOutMenu();

        // Used for hiding user-input password
        enum IN 
        {

        IN_BACK = 8,
        IN_RET = 13
 
        };
};

class admin: public mainMenu
{
    public:

        string accname;
        string pin;
        string acctype;
        string newaccname;
        string newacctype;
        string updatePin;
        string oldaccname;
        int depo;

        //for changing updated acctpye
        int typeflag;	
        string retrievedacctype;
        
        // for changing updated pin 
        int pinFlag, lineRead;
        string retrievedPin;

        //tools
        void loading();
        void buffer(string uu);

        //designs
        string introdesign();
        string banner();
        string top_banner();
        string bot_banner();

        //others
        void login();
        string hidePassWord();

        //admin menu
        void menu();
        void updtaccnt();
        void crtaccnt();
        void delaccnt();
        void showallusers();

        //getacctype and accname
        void get_acctype();

        //converter
        void convert_to_lowercase();
        void convert_to_uppercase();

        //checker
        string regex_check1();
        string regex_check2();
        string regex_check3();
        void check_duplicate();
        void check_duplicate2();
        void check_initial_depo();
        void check_accnt_in_db();
        bool stringCheck(string);
        void checkacctype();

        //SELECTOR IN UPDATE
        void choices_updt();

        //SELECTION FOR UPDATE
        void change_accname();
        void change_pin();
        string check_Pin();

        //ASK PROMPT FUNCTION
        int change_accname_ask();
        int delaccnt_ask();

        //database write
        void put_to_db_accname(ofstream&);
        void put_to_db_accno(ofstream&);
        void put_to_db_acctype_depo(ofstream&);
        void put_to_db_defpin(ofstream&);
        void date_created(ofstream&);
        void put_to_db_acctype(ofstream&);
        void input_to_db();

        //for changing acctpye
        void change_acctype();

        //SHOW ALL USERS AND DATE CREATED
        // UPPERCASE
        void save_accname_to_db(ofstream&);

        //exit program
        void exit_screen();

        enum IN 
        {

        IN_BACK = 8,
        IN_RET = 13

        };

};

#endif
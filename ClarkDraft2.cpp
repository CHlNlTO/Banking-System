#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>
#include <regex>

using namespace std;


// ALL FUNCTION DECLARATIONS

void clearScreen();

void menuScreen();

void registerScreen();

void registerPin();

void loginScreen();

int exitScreen();

// ALL DEFINITIONS

#define maxName 60
#define maxPin 4
#define maxAddress 200


// Main Function
int main(){

    // Clearing the screen first.
    clearScreen();

    // Displaying default menu screen.
    menuScreen();
    
    return 0;

}


// ALL FUNCTIONS DEFINITIONS

// Clear Screen Function.
void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

// Menu Screen Function.
void menuScreen()
{

    int num;

    clearScreen();

    registerPin();

    cout << "Welcome to The BennyShark Bank and Commerce!." << endl;
    cout << "1. Register an Account" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << "Enter number: ";
    cin >> num;

    switch(num)
    {
        case 1: 
            registerName();
            break;
        case 2:
            loginScreen();
            break;
        case 3:
            exitScreen();
            break;
    }

}


void registerScreen()
{

    // Name Registration

    char name[60];
    string nameString;

    cin.ignore();
    clearScreen();

    cout << "Enter Full Name (Ex. Juan Milagroso Dela Cruz): " << endl;
    cin.getline(name, 60);

    // Name Input Inspection ---
    if(!regex_match(name,regex("[A-Za-z.\x20]+")))
    {
        cout << "Input contains special characters. Try again." << endl;
        registerScreen();
        
    }

    if(regex_match(name,regex("[\x20]+")))
    {
        cout << "That is not a name. Try again." << endl;
        registerScreen();
    }
    // --- Name Input Inspection

    nameString = name;


    // Pin Registration

    string pin; 

    system("cls");

    cout << "Enter pin (Maximum length of 4): ";
    cin >> pin;

    if(pin.length() > 4)
    {
        cout << "Input exceeded. Try again." << endl;
        system("pause");
        registerPin();

    }

    if(pin.length() < 4)
    {
        cout << "Input incomplete. Try again." << endl;
        system("pause");
        registerScreen();

    }

    char pinChar[pin.length()];

    for (int i = 0; i < sizeof(pinChar); i++)
    {
        pinChar[i] = pin[i];
    }

    if(!regex_match(pinChar,regex("[0-9]+")))
    {

        cout << "This is not a number. Try again!" << endl;
        system("pause");
        registerScreen();

    }










    ofstream fileName(nameString + ".txt", ios::app);

    fileName << nameString << pinString<< endl;

    fileName.close();


}


// Login Screen Menu
void loginScreen()
{

    cout << "Page under maintenance. Sorry for the inconvinience.";

}

int exitScreen()
{

    exit(0);

}

/*
    time_t currentDate;
    tm* pointerDate;

    char accountNumber[10];
    time(&currentDate);
  
    pointerDate = localtime(&currentDate);

    strftime(accountNumber, 9, "%Y%m%d", pointerDate);

    cout << accountNumber << endl;
*/

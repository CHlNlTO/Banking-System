#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>
#include <regex>

using namespace std;


// ALL FUNCTION DECLARATIONS

void menuScreen();

void registerScreen();

void loginScreen();

int exitScreen();


// Main Function
int main(){

    // Clearing the screen first.
    system("cls");

    // Displaying default menu screen.
    menuScreen();
    
    return 0;

}

// ALL FUNCTIONS DEFINITIONS

// Menu Screen Function.
void menuScreen()
{

    int num;

    system("cls");

    cout << "Welcome to The BennyShark Bank and Commerce!." << endl;
    cout << "1. Register an Account" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << "Enter number: ";
    cin >> num;

    switch(num)
    {
        case 1: 
            registerScreen();
            break;
        case 2:
            loginScreen();
            break;
        case 3:
            exitScreen();
            break;
    }

}

// Registration Screen Function.
void registerScreen()
{

    // Name Registration

    char name[60];
    string nameString;

    cin.ignore();
    system("cls");

    cout << "Enter Full Name (Ex. Juan Milagroso Dela Cruz): " << endl;
    cin.getline(name, 60);

    // Name Input Inspection
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


    // Conversion of name char to name string
    nameString = name;



    // Pin Registration

    char pin[4];
    bool flag;
    flag = false;

    do
    {
        
        system("cls");

        cout << "Enter Pin: ";
        cin >> pin;

        string pinString = pin;

        // Pin Input Inspection ---
        if(regex_match(pin,regex("[0-9]+")) && pinString.length() == 4)
        {
            flag = true;

        } else 
            cout << endl << "Incorrect Pin. Try Again." << endl;
            system("pause");
        // --- Pin Input Inspection
        
    } while(flag == false);

    // Account Input to Text File
    ofstream file(nameString + ".txt", ios::app);

    file << nameString << endl << pin << endl;

    file.close();

    cout << endl << "Account Successfully Created.";

    system("pause");

    menuScreen();


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

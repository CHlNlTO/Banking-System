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

    cout << "This worked.";

}

void registerScreen()
{

    char name[60];
    char pin[5]; 

    cin.ignore();

    clearScreen();

    cout << "Enter Full Name (Ex. Juan Milagroso Dela Cruz): " << endl;
    cin.getline(name, 60);


    if(!std::regex_match(name,std::regex("[A-Za-z.\x20]+")))
    {
        cout << "Input contains special characters. Try again." << endl;
        registerScreen();
        
    }

    if(std::regex_match(name,std::regex("[\x20]+")))
    {
        cout << "That is not a name. Try again." << endl;
        registerScreen();
    }

    if(std::regex_match(name,std::regex("\x20[A-Za-z0-9]+")))
    {
        cout << "That is not a name. Try again." << endl;
        registerScreen();
    }





        /*
        for(int i = 0; i < 255; i++)
            {
                // Checking for incorrect inputs.
                if(int(name[i]) <= 45)
                {
                    cout << "It has special characters.";
                    break;
                }
                else if (int(name[i]) <= 64 && int(name[i]) >= 47)
                {
                    cout << "It has special characters.";
                    break;
                }


            }
        */
        

            

    cout << "Enter pin: ";
    cin.getline(pin, 5);

    ofstream file1("data.txt");

    file1 << name << endl;

    file1 << pin << endl;
    

    file1.close();

    /*
    time_t currentDate;
    tm* pointerDate;

    char accountNumber[10];
    time(&currentDate);
  
    pointerDate = localtime(&currentDate);

    strftime(accountNumber, 9, "%Y%m%d", pointerDate);

    cout << accountNumber << endl;
    */
    

}

void loginScreen()
{

    cout << "Page under maintenance. Sorry for the inconvinience.";

}

int exitScreen()
{

    exit(0);

}

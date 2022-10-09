#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;


bool login()
{
  string username,password,un,pw;

  cin.ignore();
  cout << "Enter Username: " << endl;  
  getline(cin,username);
  cout << "Enter password: "; 
  getline(cin,password);

  ifstream read(username + ".txt");
  
  getline(read,un);
  getline(read,pw);
  cout << un << endl;
  cout << pw << endl;


  if (un == username && pw == password)
  {
    

    return true;
  }
  
  else 
  {
    return false;
  }
}

int main()
{
  int choice;
  
  cout << "1. Register" << endl;
  cout << "2. Login " << endl;
  cout << "Your Choice: ";
  cin >> choice;

  if (choice == 1)
  {
    string username,password;

    cin.ignore();
    cout << "Enter Username: "; 
    getline(cin,username);
    cout << "Enter Password: "; 
    getline(cin, password);

    ofstream file; 
    file.open(username + ".txt");
    file << username << endl << password;

    

    file.close();
  }

  else if (choice == 2)
  {
    bool status = login();

    if (!status)
    {

      cout << "USER NOT FOUND ERROR 404" << endl;
      system("pause");
      return 0;

    }

    else 
    {
      cout << "Successfuly Logged In " << endl;
      system("pause");
      return 1;
    }
  }

}
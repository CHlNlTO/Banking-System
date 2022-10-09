#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;


bool login()
{
  string username,password,un,pw;

  cout << "Enter Username: "; cin >> username;
  cout << "Enter password: "; cin >> password;

  ifstream read("DATA\\" + username + ".txt");
  
  getline(read,un);
  getline(read,pw);

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

    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    ofstream file; 
    file.open("DATA\\" + username + ".txt");
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

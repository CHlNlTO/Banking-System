#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <ctime>
#include <regex>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <filesystem>

using namespace std;

class admin{

	string accname;
	string pin;
	string acctype;
	string newaccname;
	string newacctype;
	string updatePin;
    string oldaccname;
	int depo;

	// for changing updated pin 
	int pinFlag, lineRead;
	string retrievedPin;

	//for changing updated acctpye
	int typeflag;	
	string retrievedacctype;


	public:
		//tools
		void loading();
		void buffer(string uu);

		//designs
		string introdesign();
        string banner();
        string top_banner();
        string bot_banner();

		//others
		void welcome();
		void login();

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
		void checkPin(string);
		void checkacctype(string);

        //SELECTOR IN UPDATE
        void choices_updt();

        //SELECTION FOR UPDATE
        void change_accname();
        void change_pin();

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

};

int main()
{
	admin admObj;
	system("cls");
	admObj.welcome();
}

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

void admin::welcome(){

    system("cls");

	string choose;

    system ("Color 01");
    cout << introdesign();
    cout << "|                                                                  |"<<endl;
    cout << "|                         1.) User Login                           |" << endl;
    cout << "|                         2.) Admin Login                          |" << endl;
    cout << "|                         3.) Exit                                 |" << endl;
    cout << "|                                                                  |"<<endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Enter number (1-3): ";
    cin  >> choose;
    cin.ignore();
    if (choose == "1")
    {

        //loginName();

    }
    if (choose == "2")
    {

        login();

    }
    if (choose == "3")
    {

        exit_screen();

    }
    if (choose != "1" && choose != "2")
        cout << endl << "Choose from 1 to 3 only. Try again." << endl << endl;
        system("Color 04");
		system("pause");
		welcome();
	
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
//LOGIN AS USER OR ADMIN
void admin:: login()
{

    system("cls");

	const string name = "admin";
	const string pass = "1234"; 
	string uname;
	string upass;
	
	cout << introdesign();
    system ("Color 01");
	cout << "Username: ";
	getline(cin,uname);
	cout << "Password: ";
	getline(cin,upass);

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
    cout << "|\t\t\t  1. Create An Account\t\t\t   |" << endl;
    cout << "|\t\t\t  2. Update An Account\t\t\t   |" << endl;
    cout << "|\t\t\t  3. Delete An Account\t\t\t   |" << endl;
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

        welcome();

    }
    if (pck != "1" && pck != "2" && pck != "3" && pck != "4")
    {

        system("Color 04");
        cout << endl << "Input error. Try again." << endl << endl;
		system("pause");
		menu();

    }

}

//FUNCTIONS
void admin:: crtaccnt()
{
    system("cls");

    accname = "";

	system ("Color 01");
    cout << banner();
    cout << "|                                                                  |" << endl;
    cout << "|\t\t\t    Register Account\t\t\t   |"<<endl;
    cout << "|                                                                  |";
    cout << "\n--------------------------------------------------------------------\n";
	cout << "Enter Account Name (Press 0 to exit): ";
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
    cin >> pick;

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
    if (pick != "1" && pick != "2" && pick != "0")
    {
        system ("Color 04");
        cout << endl <<"Incorrect input. Try again.\n";
        
        system("pause");
        get_acctype();

    }


    check_initial_depo();

    
}

void admin::updtaccnt()
{

    system("cls");

    admin adobj;
    
    
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

        string deleteaccnt = "DATA\\" + accname + ".txt";

	    remove(deleteaccnt.c_str());

        cout << banner();
        cout << top_banner();
        cout << "|\t\t       Account successfully deleted.\t\t   |";
		cout << bot_banner();
        system ("Color 02");


        system("pause");

		menu();

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

    cout << introdesign();
    cout << top_banner();
    cout << "|\t\t     Account succesfully changed.   \t\t   |";
    cout << bot_banner();
    system("Color 02");

    system("pause");

    menu();

}

void admin::change_pin()
{

    system("cls");

    
    cout << banner();
	cout << "Enter New 4 - digit pin (Press 0 to exit): ";
    system ("Color 01");
	cin >> updatePin;

    
    if (updatePin == "0")
    {

        choices_updt();

    }

	if (updatePin.length() != 4 || updatePin == retrievedPin  || stringCheck(updatePin) == false)
            {	
                system("cls");
                system ("Color 04");
				cout << "Pin must be 4 - digit";
                system("pause");
				change_pin();
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
	cout << "Enter New Account Type (Press 0 to exit): ";
    system("Color 01");
	cin >> newacctype;

	regex_check3();

    if (newacctype == "0")
    {
        choices_updt();
    }
    
	if (newacctype == retrievedacctype)
    {	
        
        cout << "Account Type Must Not Be the Same";
        system ("Color 04");
        
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
	
    if (regex_match(newaccname,regex("[A-Za-z.\x20]++")))
    {
        return accname;
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
        cout << "|\t\t\tError File Does Not Exist.\t\t   |";
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

//for change pin
void admin::checkPin(string inputPin)
{


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

	}
}
//for change acctype
void admin::checkacctype(string newacctype)
{
    // Retrieving acctype from the file.
    if (typeflag == 0)
	{
		ifstream pinFile("DATA\\" + accname + ".txt");

		lineRead = 0;
		retrievedacctype = "";

		while (lineRead != 3 && getline(pinFile, retrievedacctype))
		{

			++lineRead;

		}

		if (lineRead == 3)
		{
			pinFile >> retrievedacctype;
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

    f << accountNumber ;
        srand(time(0));

        for (int  i = 1; i <= 4; i++) 
        {
                f << rand() % 10;
        }
	
	cout << endl;
}

void admin::put_to_db_acctype_depo(ofstream& f)
{

	f << depo;

}

void admin::date_created(ofstream& f)
{

   time_t timetoday;
   time (&timetoday);
   f << endl << asctime(localtime(&timetoday));
}

void admin::save_accname_to_db(ofstream& f)
{	
	time_t timetoday;
    time (&timetoday);

	transform(accname.begin(), accname.end(), accname.begin(), :: toupper);
	
	f << accname << "\t\t\t" << asctime(localtime(&timetoday)); ;
}

void admin::put_to_db_acctype(ofstream& f)
{

	f << endl << acctype;

}

//INPUT TO DB
void admin::input_to_db()
{

    system("cls");

    string choose;

    cout << introdesign();
    cout << top_banner();
    cout <<"|\t\t   Create " << oldaccname << " account?\t\t";
    cout << bot_banner();
    cout << "Enter Y or N: ";
    cin >> choose;

    if (choose != "Y" && choose != "y" && choose != "N" && choose != "n")
    {

        cout << endl << "Input error. Try Again.";
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

void admin::exit_screen()
{

    system("cls");
	cout << "--------------------------------------------------------------------" << endl;
    cout << "|                                                                  |"<< endl;
    cout << "|                      Thank you for using the                     |"<< endl;
    cout << "|                        Bank of BennyShark!                       |"<< endl;
    cout << "|                                                                  |"<< endl;
    cout << "--------------------------------------------------------------------" << endl;
    system("Color 01");
    system("pause");
	exit(0);

} 





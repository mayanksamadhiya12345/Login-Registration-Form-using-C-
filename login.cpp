#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    cout << "\t\t\t__________________________________________________\n\n\n";
    cout << "\t\t\t          welcome to the Mayank's login page      \n\n\n";
    cout << "\t\t\t_______________        MENU        _______________\n\n\n";
    cout << "                                                        \n\n\n";
    cout << "\t\t\t|  Press 1 to LOGIN                              |" << endl;
    cout << "\t\t\t|  Press 2 to REGISTER                           |" << endl;
    cout << "\t\t\t|  Press 3 if you forgot your PASSWORD           |" << endl;
    cout << "\t\t\t|  Press 4 to EXIT                               |" << endl;
    
    cout << "\n\nPlease enter your choice : ";
    int choice;
    cin>>choice;
	cout<<endl;

    switch(choice)
    {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
        	cout << "Existing\n";
            cout << "Thankyou for using! \n\n\n";
            break;

        default:
            system("cls");
            cout << "\t\t\t\t  Pleae select the correct option \n" << endl;
            main();
    }
}

void login()
{
    string UserName, UserPassword;
    
    cout << "Enter the username : ";
    cin >> UserName;
    cout << "Enter the password : ";
    cin >> UserPassword;


	string sUserName, sUserPassword;
	ifstream file("record.txt");
    bool account_found = false;
    while(file >> sUserName >> sUserPassword)
    {
        if(sUserName==UserName && sUserPassword==UserPassword)
        {
            account_found = true;
            break;
        }
    }
    file.close();

    if(account_found)
    {
        cout << endl << UserName << " Account LOGIN has been done successfully" ;
		cout<< "\nThanks for logging in \n\n";
		cout<<"===================================================================================="<<endl<<endl;
    }
    else
    {
        cout << "\nLOGIN ERROR ";
		cout<< " \nPlease check your username and password\n\n";
		cout<<"===================================================================================="<<endl<<endl;
        login();
    }
}

void registration()
{
    string rUserName, rUserPassword;

    cout << "Enter the username : ";
    cin >> rUserName;
    cout << "Enter the password : ";
    cin >> rUserPassword;
    
    string sUserName, sUserPassword;
    bool duplicate_Account = false;
    ifstream input("record.txt");
	while(input >> sUserName >> sUserPassword)
	{
		if(rUserName==sUserName)
		{
			duplicate_Account = true;
			break;
		}
	}
	input.close();
	
	if(duplicate_Account)
	{
		cout<<"\n\nSorry! Account already exist with the given Username! ";
		cout<<"\nTry with other username "<<endl<<endl;
		cout<<"===================================================================================="<<endl<<endl;
		registration();
		return;
	}

	ofstream output("record.txt");
    output << rUserName << " " << rUserPassword << endl;
    cout<<"\n\nRegistration has been done succesfully!\n\n";
	output.close();
	
	cout<<"===================================================================================="<<endl<<endl;

    cout<<"\n\nWant to go to the main menu (Y/N) : ";
    char ch;
    cin>>ch;
    cout<<endl<<endl;
    
    if(ch=='Y' || ch=='y') main();
    else if (ch=='N' || ch=='n') cout<<"\n\nThanks for Registration!"<<endl;
}

void forgot()
{
    cout << "You forgot the password? No Worries \n";
    cout << "Press 1 to search your password by username \n";
    cout << "press 2 to go to the main menu \n\n";

    int choice;
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
        	string UserName;
            cout << "\nEnter the username : ";
            cin>>UserName;

            string sUserName, sUserPassword;
            ifstream file("record.txt");
            bool account_found = false;
            while(file >> sUserName >> sUserPassword)
            {
                if(UserName == sUserName)
                {
                    account_found = true;
                    break;
                }
            }
            file.close();

            if(account_found)
            {
                cout << "\nYour account has been found ";
                cout << "\nYour password is :" << sUserPassword << endl << endl;
                cout<<"===================================================================================="<<endl<<endl;
                
				cout<<"\n\nWant to go to the main menu (Y/N) : ";
			    char ch;
			    cin>>ch;
			    cout<<endl<<endl;
			    
			    if(ch=='Y' || ch=='y') main();
			    else if (ch=='N' || ch=='n') cout<<"Thanks for Using!"<<endl;
            }
            else
            {
                cout << "\n\nSorry! Account does not exist with given Username! " << endl << endl;
                cout<<"===================================================================================="<<endl<<endl;
                
                cout<<"\n\nWant to go to the main menu (Y/N) : ";
			    char ch;
			    cin>>ch;
			    cout<<endl<<endl;
			    
			    if(ch=='Y' || ch=='y') main();
			    else if (ch=='N' || ch=='n') cout<<"Thanks for Using!"<<endl;
            }
            break;
		}
            
        case 2:
            main();
            break;

        default:
            cout << "Wrong choice ! Please try again \n\n";
            cout<<"===================================================================================="<<endl<<endl;
            forgot();
    }
}

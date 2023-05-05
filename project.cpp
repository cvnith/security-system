#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password0, password1, password2, pass, name, age, user, word1, word2,dob,gender;
    string creds[2], co[2];
    cout << "           SECURITY SYSTEM           " << endl;
    cout << "-------------------------------------" << endl;
    cout << "|            1. REGISTER              |" << endl;
    cout << "|           2. LOGIN                  |"<< endl;
    cout << "|            3. CHANGE PASSWORD       |" << endl;
    cout << "|            4. END PROGRAM           |" << endl<< endl;
    cout << "-------------------------------------" << endl;
    ;
    do
    {
        cout << endl<<endl;
        cout << "ENTER THE CHOICE:-";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "----------------------------" << endl
                 << endl;
            cout << "----------REGISTER----------" << endl;
            cout << "----------------------------" << endl
                 << endl;
            cout << "ENTER THE USERNAME:-";
            cin >> name;
            cout << "ENTER THE PASSWORD:-";
            cin >> password0;
            cout << "ENTER THE AGE:-";
            cin >> age;
            cout << "DATE OF BIRTH:-";
            cin >> dob;
            cout << "GENDER:-";
            cin >> gender;
            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0;
                of1.close();
                cout << "REGISTRATION SUCCESSFULL" << endl;
            }
            break;
        }
        case 2:
        {
            i = 0;
            cout << "-------------------------" << endl<<endl;
            cout << "----------LOGIN----------" << endl;
            cout << "-------------------------" << endl<< endl;
            ifstream of2;
            of2.open("file.txt");
            cout <<"     ENTER THE USERNAME:-  ";
            cin >> user;
            cout <<"     ENTER THE PASSWORD:-  ";
            cin >> pass;
            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text))
                        {
                        istringstream iss(text);
                         iss >> word1;
                         creds[i] = word1;
                         i++;
                        }
                        if (user == creds[0] && pass == creds[1])
                        {
                            cout << "LOGIN SUCCESSFULL....";
                            cout << endl<< endl;
                            cout << "    DETAILS:-" <<endl;
                            cout << "    USERNAME:-" + name << endl;
                            cout << "    PASSWORD:-" + pass << endl;
                            cout << "    AGE:-" + age << endl;
                            cout << "    DATE OF BIRTH:-" + dob << endl;
                            cout << "    GENDER:-" + gender << endl;
                            break;
                        }
                        else
                        {
                            cout << endl<< endl;
                            cout << "INCORRECT PASSWORD" << endl;
                            cout << "    1.Press 2 to login                " << endl;
                            cout << "    2.Press 3 to change password      " << endl;
                            break;
                        }
                    
                }
            }
            else
                {
                    cout << "ERROR: Could not open file" << endl;
                }
            break;
        }
        case 3:
        {
            i = 0;
            cout << ".............CHANGE PASSWORD........." << endl;
            ifstream of0;
            of0.open("file.txt");
            cout << "ENTER THE OLD PASSWORD:-" << endl;
            cin >> old;
            if (of0.is_open())
            {
                    while (getline(of0,text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        co[i] = word1;
                        i++;
                    }
                    if (old == co[1])
                    {
                        of0.close();
                        ofstream of1;
                        of1.open("file.txt");
                        if (of1.is_open())
                        {
                            cout << "ENTER THE NEW PASSWORD:-";
                            cin >> password1;
                            cout << "ENTER THE PASSWORD AGAIN:-";
                            cin >> password2;
                            if (password1 == password2)
                            {
                                of1 << co[0] << "\n";
                                of1 << password1;
                                cout << "PASSWORD CHANGED SUCCESSFULLY" << endl;
                            }
                            else
                            {
                                of1 << co[0] << "\n";
                                of1 << old;
                                cout << "PASSWORD DONOT MATCH:-";
                            }
                        }
                    }
                    else{
                        cout << "PLEASE ENTER THE VALID PASSWORD:-" << endl;
                        of0.close();
                        break;
                    }
                    
                
            }
            break;
        }
        case 4:
        {
            cout << "---------------THANK YOU!-----------------";
            break;
        }
        default:
            cout << "ENTER THE VALID CHOICE";
            break;
        }
    } while (a !=4);
    return 0;
}
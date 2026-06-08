#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool usernameExists(string username)
{
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            return true;
        }
    }
    return false;
}

void registerUser()
{
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if (usernameExists(username))
    {
        cout << "\nUsername already exists!\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "\nRegistration Successful!\n";
}

void loginUser()
{
    string username, password;
    string user, pass;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "\nLogin Successful!";
        cout << "\nWelcome " << username << endl;
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LOGIN & REGISTRATION SYSTEM =====";
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 3);

    return 0;
}

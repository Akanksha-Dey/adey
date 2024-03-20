#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUp();
    void forgot();
};

void temp::signUp() {
    cin.ignore(); // Clear input buffer
    cout << "\nEnter Your User Name: ";
    getline(cin, userName);
    cout << "Enter your Email Address: ";
    getline(cin, Email);
    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void temp::login() {
    cin.ignore(); // Clear input buffer
    cout << "\n...........LOGIN............\n";
    cout << "Enter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Password: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (userName == searchName && password == searchPass) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "\nAccount Login Successful\n";
        cout << "Username: " << userName << endl;
        cout << "Email: " << Email << endl;
    } else {
        cout << "Login failed. Username or password is incorrect.\n";
    }
}

void temp::forgot() {
    cin.ignore(); // Clear input buffer
    cout << "\nEnter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Email Address: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (userName == searchName && Email == searchEmail) {
            found = true;
            cout << "\nAccount Found\n";
            cout << "Your Password: " << password << endl;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Account not found. Please check your username and email.\n";
    }
}

int main() {
    temp obj;
    char choice;
    do {
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case '1':
            obj.login();
            break;
        case '2':
            obj.signUp();
            break;
        case '3':
            obj.forgot();
            break;
        case '4':
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid Selection! Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

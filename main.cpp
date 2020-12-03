#include "studyroom.cpp"
#include "studyroom.hpp"
#include <fstream>
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
void login();
void registr();
void start();
int main() {
    int ch;
    int choice;
    do {
        string line;
        ifstream myfile("Login.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                cout << line << '\n';
            }
            myfile.close();
        }

        else
            cout << "Unable to open file";
        cout << "\nEnter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            cout << "See you again in StudyRoom!";
            break;
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}
void login() {
    int count;
    string user, pass, u, p;

    system("clear");
    cout << "please enter the details" << endl;
    cout << "\nUSERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("database.txt"); // 파일열기
    while (input >> u >> p) {
        if (u == user && p == pass)

        {
            count = 1;
            system("clear");
        }
    }
    input.close();
    if (count == 1) {
        cout << "\nHELLO " << user << "\nLOGIN SUCESS\n";
        start();
        cin.get();
        cin.get();
        main();
    } else {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        main();
    }
}
void registr() {

    string reguser, regpass, ru, rp;
    system("clear"); // 화면 지워주기
    cout << "Enter the username :";
    cin >> reguser;
    cout << "\nEnter the password :";
    cin >> regpass;

    ofstream reg("database.txt", ios::app); // 파일 쓰기 없으면 생성
    reg << reguser << ' ' << regpass << endl;
    system("clear");
    cout << "\nRegistration Sucessful\n";
    main();
}
void start() {
    StudyRoom obj;
    int key;
    char ch;
    int floorcheck;
    int num = 1;
    obj.create();
    do {
        string line;
        ifstream myfile("menu.txt");
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                cout << line << '\n';
            }
            myfile.close();
        }

        else
            cout << "Unable to open file";

        cout << " Please choose the section in the menu : ";
        cin >> key;
        switch (key) {
        case 1: {
            obj.reserve(1);
            break;
        }
        case 2: {
            obj.reserve(2);
            break;
        }
        case 3: {
            obj.reserve(3);
            break;
        }
        case 4: {
            obj.display();
            break;
        }
        case 5: {
            cout << "Enter floor number : ";
            cin >> floorcheck;
            obj.cancel(floorcheck);
            break;
        }
        case 6: {
            cout << "Enter floor number : ";
            cin >> floorcheck;
            obj.changeName(floorcheck);
            break;
        }
        case 7: {
            cout << "Enter floor number : ";
            cin >> floorcheck;
            obj.cancel(floorcheck);
            obj.reserve(num);
            break;
        }
        case 8: {
            cout << "Thank you! See you again in StudyRoom!";
            break;
        }
        default:
            cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> ch;
        system("clear");
    } while (ch == 'Y' || ch == 'y');
}

#include "studyroom.cpp"
#include "studyroom.hpp"
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main() {

    StudyRoom obj;
    int key;
    char ch;

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
        }
        case 2: {
        }
        case 3: {
        }
        case 4: {
        }
        case 5: {
        }
        case 6: {
        }
        case 7: {
        }
        default:
            cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

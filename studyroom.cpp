#include "studyroom.hpp"
#include <iostream>
#include <string.h>
using namespace std;
StudyRoom::StudyRoom() {
    for (int i = 0; i < 3; i++)
        header[i] = NULL;
}
void StudyRoom::create() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            node *nn = new node;
            nn->next = NULL;
            nn->prev = NULL;
            if (header[i] == NULL) {
                header[i] = nn;
                nn->num = 1;
            } else {
                node *cn = header[i];
                while (cn->next != NULL) {
                    cn = cn->next;
                }
                if (j == 3 || j == 5 || j == 7 || j == 8) {
                    cn->num = 3;
                }
                if (j == 2 || j == 4 || j == 6) {
                    cn->num = 2;
                }
                cn->next = nn;
                nn->prev = cn;
            }
        }
    }
}
void StudyRoom::display() {
    int j = 0, k = 0, l = 0;
    for (int i = 0; i < 58; i++) {
        cout << "--";
    }
    cout << "\n ";
    for (int i = 1; i < 4; i++) {
        cout << "| Zone number : " << i << " \t\t\t";
    }
    cout << "|\n";
    for (int i = 0; i < 58; i++) {
        cout << "--";
    }
    cn = header[j];
    node *sn = header[j + 1];
    node *tn = header[j + 2];
    cout << "\n ";
    while (cn != NULL) {
        if (cn->fill != cn->num && cn->num != 0) {
            j++;
            cout << "| room no : " << j;
            cout << "-> " << cn->num << " available seat(s)";
        } else {
            j++;
            cout << "| room no : " << j;
            cout << "->Reserved "
                 << "\t";
        }
        if (sn->fill != sn->num && sn->num != 0) {
            k++;
            cout << "\t | room no : " << j;
            cout << "-> " << cn->num << " available seat(s)";
        } else {
            k++;
            cout << " \t | room no : " << j;
            cout << "->Reserved "
                 << "\t";
        }
        if (tn->fill != tn->num && tn->num != 0) {
            l++;
            cout << "\t | room no : " << j;
            cout << "-> " << cn->num << " available seat(s)";
        } else {
            l++;
            cout << "\t | room no : " << j;
            cout << "->Reserved "
                 << " | ";
        }
        cout << " \n ";
        for (int i = 0; i < 58; i++) {
            cout << "--";
        }
        cout << "\n ";
        cn = cn->next;
        sn = sn->next;
        tn = tn->next;
    }
}

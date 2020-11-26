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
    int j = 0;
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
            cout << "->Full \t"
                 << "\t";
        }
        if (sn->fill != sn->num && sn->num != 0) {

            cout << "\t | room no : " << j;
            cout << "-> " << sn->num << " available seat(s)";
        } else {

            cout << " \t | room no : " << j;
            cout << "->Full \t"
                 << "\t";
        }
        if (tn->fill != tn->num && tn->num != 0) {

            cout << "\t | room no : " << j;
            cout << "-> " << tn->num << " available seat(s)";
        } else {

            cout << "\t | room no : " << j;
            cout << "->Full \t"
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
void StudyRoom::reserve(int people) {
    int zone, room;
    cout << "\nEnter the zone number : ";
    cin >> zone;
    try {
        if (zone < 1 || zone > 3)

        {
            throw(zone);
        }
        cn = header[zone - 1];

        cout << "\nEnter the room number : ";
        cin >> room;
        try {

            if (room < 1 || room > 9) {
                throw(room);
            } else {
                int i = 1;
                while (i < room) {
                    cn = cn->next;
                    i++;
                }
                if (cn->num >= people) {
                    cout << "\nroom is available & you can reserve the room";

                    int count = 0;
                    while (cn->fill - 1 <= cn->num) {

                        cout << "\nEnter the name " << cn->fill + 1 << " : ";

                        cin >> cn->name[cn->fill];
                        count++;
                        cn->fill++;
                        if (count >= people) {
                            break;
                        }
                    }
                    cn->num = cn->num - people;
                }

                else {
                    cout << "\nroom is unavailable... SORRY !!!!!";
                }
            }
        } catch (int r) {
            cout << "\ninvalid room number : " << r;
        }
    } catch (int r) {
        cout << " \ninvalid zone number : " << r;
    }
}
void StudyRoom::cancel(int check) {
    char namecheck[10];
    int flag = 0;
    int room, i = 1;
    try {
        if (check < 1 || check > 3)

        {
            throw(check);
        } else {
            cout << " Enter the room no : ";
            cin >> room;
            try {
                if (room < 1 || room > 9) {
                    throw(room);
                } else {
                    cout << " Enter the name to be deleted "
                            ":";

                    cin >> namecheck;
                    cn = header[check - 1];
                    while (i < room) {
                        cn = cn->next;
                        i++;
                    }
                    i = 0;
                    while (i < 3) {

                        if (!strcmp(namecheck, cn->name[i]))

                        {
                            flag = 1;
                            break;
                            i = 0;
                        } else
                            i++;
                    }
                    if (flag == 1 && cn->fill != 0) {
                        cout << "\nrecord deleted : " << cn->name[i];

                        cn->name[i][0] = 'A';
                        cn->name[i][1] = '\0';
                        cn->fill--;
                        cn->num++;
                    } else

                        cout << "\nrecord not Reserved ";
                }
            } catch (int r) {
                cout << "\ninvalid room number : " << r;
            }
        }
    }

    catch (int r)

    {
        cout << " \n zone doesn't exist : " << r;
    }
}

void StudyRoom::changeName(int check) {
    char namecheck[10];
    int room, i = 1;
    try {
        if (check < 0 || check > 4)

        {
            throw(check);
        } else {
            cout << " Enter the room no : ";
            cin >> room;
            try {
                if (room < 0 || room > 10)

                {
                    throw(room);
                } else {
                    cout << "Enter the name to be edited :";

                    cin >> namecheck;
                    cn = header[check - 1];
                    while (i < room) {
                        cn = cn->next;
                        i++;
                    }
                    i = 0;
                    while (i < 3) {
                        if (!strcmp(namecheck, cn->name[i]))

                        {
                            cout << "\nenter new name : ";

                            cin >> cn->name[i];
                            break;
                        } else
                            i++;
                    }
                    if (i >= 3)
                        cout << "record not found ";
                    else {
                        cout << "\nrecord edited\nprevious name : " << namecheck
                             << "\nedited name : " << cn->name[i];
                    }
                }
            } catch (int r) {
                cout << "\ninvalid room number : " << r;
            }
        }
    }

    catch (int r)

    {
        cout << "\n floor dosn't exist : " << r;
    }
}

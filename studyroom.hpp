#ifndef __STUDYROOM_H__
#define __STUDYROOM_H__
#include <string.h>

struct node {
    int num = 1;
    int fill = 0;
    char name[3][10];
    node *next;
    node *prev;
};
class StudyRoom {
    node *header[3];
    node *cn;

  public:
    StudyRoom();
    void create();
    void display();
    void reserve(int people);
};

#endif

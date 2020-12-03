#ifndef __STUDYROOM_H__
#define __STUDYROOM_H__
#include <string.h>

struct node {
    int num = 1;  // study room 몇인용인지 할당하기 위한 변수
    int fill = 0; // study room 꽉차있는지
    char name[3][10];
    node *next;
};
class StudyRoom {
    node *header[3];
    node *cn;

  public:
    StudyRoom();
    void create();
    void display();
    void reserve(int people);
    void cancel(int check);
    void changeName(int check);
};

#endif

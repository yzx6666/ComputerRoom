#ifndef TEACHER_H__
#define TEACHER_H__
#include <iostream>
#include <vector>
#include "Identity.h"

using namespace std;

class teacher: public Identity
{
public:
    teacher(int empId, string name, string pwd);
    teacher();
    virtual ~teacher() {}


    void operMenu();

    int empId;
    string name;
    string pwd;

    void validOrder();
    void showAllOrder();
};
#endif
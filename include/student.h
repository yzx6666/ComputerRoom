#ifndef STUDENT_H__
#define STUDENT_H__
#include <iostream>
#include "Identity.h"
#include <vector>
#include "computer.h"
#include "fstream"

using namespace std;

class student: public Identity
{
public:
    student(int id, string name, string pwd);
    student();
    virtual ~student() {}

    void operMenu();

    int m_id;
    string name;
    string pwd;

    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();

    vector<computer> vCom;
};

#endif
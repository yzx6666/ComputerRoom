#include <iostream>
#include <fstream>
#include <vector>
#include "computer.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"

using namespace std;

class manager: public Identity
{
public:
    manager(string name, string pwd);
    virtual ~manager() {}

    void operMenu();

    string name;
    string pwd;

    void addPerson();
    void showPerson();
    void showComputer();
    void clearFile();

    void initVector();
    vector<student> vStu;
    vector<teacher> vTea;
    bool check(int id, int type);

    void prStu(const student &s);
    void prTea(const teacher &t);

    vector<computer> vCom;
    void initComputer();
};
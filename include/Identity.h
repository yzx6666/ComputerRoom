#ifndef IDENTITY_H__
#define IDENTITY_H__
#include <iostream>
#include <string>
#include "global.h"
using namespace std;

class Identity
{
public:

    virtual void operMenu() = 0;

    string name;
    string pwd;
};

#endif

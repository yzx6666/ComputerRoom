#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "global.h"
using namespace std;

class order
{
public:
    order();

    void updateOrder();

    map<int, map<string,string>> m_orderDate; 
    // key ���� value ��Ϣ

    int m_size;
};
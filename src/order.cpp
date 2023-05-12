#include <iostream>
#include "../include/order.h"

order::order()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios :: in);

    string date, interval, stuId, roomId, status, stuName;

    this->m_size = 0;

    while (ifs >> date && ifs >> interval && ifs >> stuId  && ifs >>stuName && ifs >>roomId && ifs >> status)
    {
        string key, val;
        map<string,string> m;
        
        int pos = date.find(":");
        if(pos != -1)
        {
            key = date.substr(0, pos);
            val = date.substr(pos + 1);
            m.insert(make_pair(key, val));
        }

        pos = interval.find(":");
        if(pos != -1)
        {
            key = interval.substr(0, pos);
            val = interval.substr(pos + 1);
            m.insert(make_pair(key, val));
        }

        pos = stuId.find(":");
        if(pos != -1)
        {
            key = stuId.substr(0, pos);
            val = stuId.substr(pos + 1);
            m.insert(make_pair(key, val));
        }
        pos = stuName.find(":");
        if(pos != -1)
        {
            key = stuName.substr(0, pos);
            val = stuName.substr(pos + 1);
            m.insert(make_pair(key, val));
        }
        pos = roomId.find(":");
        if(pos != -1)
        {
            key = roomId.substr(0, pos);
            val = roomId.substr(pos + 1);
            m.insert(make_pair(key, val));
        }
        pos = status.find(":");
        if(pos != -1)
        {
            key = status.substr(0, pos);
            val = status.substr(pos + 1);
            m.insert(make_pair(key, val));
        }

        this->m_orderDate.insert(make_pair(this->m_size, m));
        this->m_size ++;
        
    }
    ifs.close();
}

void order::updateOrder()
{
    if(this->m_size == 0)
    {
        return ;
    }
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::out| ios::trunc);
    for(int i = 0; i < this->m_size; i ++ )
    {
        ofs << "date:" << this->m_orderDate[i]["date"] << " "; 
        ofs << "interval:" << this->m_orderDate[i]["interval"] << " "; 
        ofs << "StuId:" << this->m_orderDate[i]["StuId"] << " "; 
        ofs << "StuName:" << this->m_orderDate[i]["StuName"] << " "; 
        ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " "; 
        ofs << "status:" << this->m_orderDate[i]["status"] << " "; 
        ofs << endl;
    }
    ofs.close();
}
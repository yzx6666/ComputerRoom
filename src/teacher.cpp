#include "../include/teacher.h"
#include "../include/order.h"
#include <iostream>
#include <string>
using namespace std;

teacher::teacher() {}

teacher::teacher(int id, string name, string pwd)
{
	this->empId = id;
	this->name = name;
	this->pwd = pwd;
}

void teacher::operMenu()
{
    cout << "��ӭ��ʦ��" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void teacher::showAllOrder()
{
	order od;
	if(od.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for(int i = 0; i < od.m_size; i ++) 
	{
		cout << i + 1 << "�� ";
		cout << "ԤԼ���ڣ� ��" << od.m_orderDate[i]["date"];
		cout << " ʱ��Σ� " << (od.m_orderDate[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ� " << od.m_orderDate[i]["StuId"];
		cout << " ������ " << od.m_orderDate[i]["StuName"];
		cout << " ������ţ� " << od.m_orderDate[i]["roomId"];

		string status = " ״̬: ";
		if(od.m_orderDate[i]["status"] == "1")
		{
			status += "�����";
		}
		else if(od.m_orderDate[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if(od.m_orderDate[i]["status"] == "3")
		{
			status += "ԤԼʧ��";
		}
		else if(od.m_orderDate[i]["status"] == "4")
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void teacher::validOrder()
{
    order od;
	if(od.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> v;
	v.clear();
	int idx = 0;
	for(int i = 0; i < od.m_size; i ++) 
	{
		if(od.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++idx << "�� ";
			cout << "ԤԼ���ڣ� ��" << od.m_orderDate[i]["date"];
			cout << " ʱ��Σ� " << (od.m_orderDate[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ�ţ� " << od.m_orderDate[i]["StuId"];
			cout << " ������ " << od.m_orderDate[i]["StuName"];
			cout << " ������ţ� " << od.m_orderDate[i]["roomId"];
			string status = " ״̬: �����";
			cout << status << endl;
		}
	}

	cout << "��������˵�ԤԼ��¼�� 0��ʾ����" << endl;
	int s = 0;
	int ret = 0;

	while (true)
	{
		cin >> s;
		if(s >= 0 && s <= (int)v.size())
		{
			if(s == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;

				cin >> ret ;
				if(ret == 1)
				{
					od.m_orderDate[v[s - 1]]["status"] = "2";
				}
				else
				{
					od.m_orderDate[v[s - 1]]["status"] = "3";
				}
				od.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}
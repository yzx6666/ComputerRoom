#include "../include/student.h"
#include "../include/order.h"
#include <iostream>
#include <string>
using namespace std;

student::student(){}

student::student(int id, string name, string pwd)
{
    this->m_id = id;
    this->name = name;
    this->pwd = pwd;

    ifstream ifs;
    ifs.open(CPMPUTER_FILE, ios :: in);

	computer c;
	while (ifs >> c.m_cId && ifs >> c.m_ma)
	{
		vCom.push_back(c);
	}
	
	ifs.close();
}

void student::operMenu()
{
    cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void student::applyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date, interval, room;
	while (true)
	{
		cin >> date;
		if(date >= 1 && date <= 5) break;
		cout << "������������������" << endl;
	}

	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if(interval >= 1 && interval <= 2) break;
		cout << "������������������" << endl;
	}

	cout << "��ѡ������� " << endl;
	for(int i = 0; i < 3; i ++)
	{
		cout << vCom[i].m_cId << "�Ż����������� " << vCom[i].m_ma << endl;
	}
	
	while (true)
	{
		cin >> room;
		if(room >= 1 && room <= 3) break;
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);

	ofs << "date:" << date << " "; 
	ofs << "interval:" << interval << " "; 
	ofs << "StuId:" << this->m_id << " "; 
	ofs << "StuName:" << this->name << " "; 
	ofs << "roomId:" << room << " "; 
	ofs << "status:" << 1 << " "; 
	ofs << endl;
	
	ofs.close();
	system("pause");
	system("cls");
}

void student::showMyOrder()
{
	order od;
	if(od.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	bool f = false;
	for(int i = 0; i < od.m_size; i ++) 
	{
		if(atoi(od.m_orderDate[i]["StuId"].c_str()) == this->m_id) 
		{
			f = true;
			cout << "ԤԼ���ڣ� ��" << od.m_orderDate[i]["date"];
			cout << " ʱ��Σ� " << (od.m_orderDate[i]["interval"] == "1" ? "����" : "����");
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
	}
	if(!f) cout << "��ԤԼ��¼" << endl;
	system("pause");
	system("cls");

}

void student::showAllOrder()
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

void student::cancelOrder()
{
    order od;
	if (od.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v; //�������������е��±���
	int index = 1;
	for (int i = 0; i < od.m_size; i++)
	{
		//���ж�������ѧ��
		if (this->m_id == atoi(od.m_orderDate[i]["StuId"].c_str()))
		{
			//��ɸѡ״̬  ����л�ԤԼ�ɹ�
			if (od.m_orderDate[i]["status"] == "1" || od.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << od.m_orderDate[i]["date"];
				cout << " ʱ��Σ� " << (od.m_orderDate[i]["interval"] == "1" ? "����" : "����");
				cout << " ������ţ� " << od.m_orderDate[i]["roomId"];
				string status = " ״̬�� ";
				if (od.m_orderDate[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (od.m_orderDate[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}


	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;

	while (true)
	{
		cin >> select;

		if (select >= 0 && select <= (int)v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				od.m_orderDate[v[select - 1]]["status"] = "4";

				od.updateOrder();

				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}

		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}
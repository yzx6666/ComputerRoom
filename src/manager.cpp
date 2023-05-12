#include "../include/manager.h"
#include <iostream>
#include <string>
using namespace std;

manager::manager(string name, string pwd)
{
    this->name = name;
    this->pwd = pwd;

	this->initVector();

	this->initComputer();
}

void manager::operMenu()
{
    cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void manager::addPerson()
{
    cout << "��ѡ������˺ŵ�����" << endl;
    cout << "1�����ѧ��" << endl;
    cout << "2�������ʦ" << endl;

	string fileName;
	string tip, errstr;
	ofstream ofs;

	int s = 0;
	cin >> s;

	if(s == 1)
	{
		tip = "������ѧ��";
		errstr = "ѧ���ظ�������������";
		fileName = STUDENT_FILE;
	}
	else 
	{
		tip = "������ְ�����";
		errstr = "ְ�����ظ�������������";
		fileName = TEACHER_FILE;
	}

	ofs.open(fileName, ios::out | ios::app);

	int sid = 0;
	string sname;
	string spwd;

	cout << tip << endl;

	while (true)
	{
		cin >> sid;
		bool ret = this->check(sid, s);
		if(ret)
		{
			cout << errstr << endl;
		}
		else break;
	}	

	cout << "����������" << endl;
	cin >> sname;

	cout << "����������" << endl;
	cin >> spwd;

	ofs << sid << " " << sname << " " << spwd << " " << endl;
	ofs.close();
	this->initVector();
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
}

void manager::showPerson()
{
    cout << "��ѡ��鿴������" << endl;
    cout << "1���鿴����ѧ��" << endl;
    cout << "2���鿴������ʦ" << endl;

	int s = 0;
	cin >> s;

	if(s == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for(const auto &x : vStu) prStu(x);
	}
	else 
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for(const auto &x : vTea) prTea(x);
	}

	system("pause");
	system("cls");
}

void manager::showComputer()
{
    cout << "������Ϣ����: " << endl;
	for(const auto &x : vCom)
	{
		cout << "������� " << x.m_cId << " ������������� " << x.m_ma << endl;
	}
	system("pause");
	system("cls");
}

void manager::clearFile()
{
    ofstream ofs;
	ofs.open(ORDER_FILE, ios :: trunc);

	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

bool manager::check(int id, int type)
{
	if(type == 1)
	{
		for(const auto &x : this->vStu)
		{
			if(id == x.m_id) return true;
		}
	}
	else 
	{
		for(const auto &x : this->vTea)
		{
			if(id == x.empId) return true;
		}
	}
	return false;
}

void manager::initVector()
{
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios :: in);

	if(!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return ;
	}

	student s;
	while (ifs >> s.m_id && ifs >> s.name && ifs >> s.pwd)
	{
		vStu.push_back(s);
	}

	ifs.close();

	// cout << vStu.size() << endl;

	ifs.open(TEACHER_FILE, ios :: in);

	if(!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return ;
	}

	teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs >> t.pwd)
	{
		vTea.push_back(t);
	}

	// cout << vStu.size() << endl;
	ifs.close();
}

void manager::initComputer()
{
	ifstream ifs;
	ifs.open(CPMPUTER_FILE, ios :: in);

	computer c;
	while (ifs >> c.m_cId && ifs >> c.m_ma)
	{
		vCom.push_back(c);
	}
	
	ifs.close();
}

void manager::prStu(const student &s)
{
	cout << "ѧ��: " << s.m_id << " ����: " << s.name << " ����: " << s.pwd << endl; 
}
void manager::prTea(const teacher &t)
{
	cout << "ְ����: " << t.empId << " ����: " << t.name << " ����: " << t.pwd << endl; 
}
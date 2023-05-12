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
    cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void manager::addPerson()
{
    cout << "请选择添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

	string fileName;
	string tip, errstr;
	ofstream ofs;

	int s = 0;
	cin >> s;

	if(s == 1)
	{
		tip = "请输入学号";
		errstr = "学号重复，请重新输入";
		fileName = STUDENT_FILE;
	}
	else 
	{
		tip = "请输入职工编号";
		errstr = "职工号重复，请重新输入";
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

	cout << "请输入姓名" << endl;
	cin >> sname;

	cout << "请输入密码" << endl;
	cin >> spwd;

	ofs << sid << " " << sname << " " << spwd << " " << endl;
	ofs.close();
	this->initVector();
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
}

void manager::showPerson()
{
    cout << "请选择查看的类型" << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

	int s = 0;
	cin >> s;

	if(s == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for(const auto &x : vStu) prStu(x);
	}
	else 
	{
		cout << "所有老师信息如下： " << endl;
		for(const auto &x : vTea) prTea(x);
	}

	system("pause");
	system("cls");
}

void manager::showComputer()
{
    cout << "机房信息如下: " << endl;
	for(const auto &x : vCom)
	{
		cout << "机房编号 " << x.m_cId << " 机房最大容量： " << x.m_ma << endl;
	}
	system("pause");
	system("cls");
}

void manager::clearFile()
{
    ofstream ofs;
	ofs.open(ORDER_FILE, ios :: trunc);

	ofs.close();

	cout << "清空成功" << endl;
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
		cout << "文件读取失败" << endl;
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
		cout << "文件读取失败" << endl;
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
	cout << "学号: " << s.m_id << " 姓名: " << s.name << " 密码: " << s.pwd << endl; 
}
void manager::prTea(const teacher &t)
{
	cout << "职工号: " << t.empId << " 姓名: " << t.name << " 密码: " << t.pwd << endl; 
}
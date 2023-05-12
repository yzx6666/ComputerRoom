#include <iostream>
#include <fstream>
#include "../include/global.h"
#include "../include/Identity.h"
#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/manager.h"
#include "../include/order.h"
using namespace std;

void teacherMenu(Identity *&te)
{
	while (true)
	{
		te->operMenu();

		teacher *tea = (teacher *)te;
		int s = 0;
		cin >> s;
		switch (s)
        {
        case 1:
            tea->showAllOrder();
            break;
        case 2:
            tea->validOrder();
            break;
        default:
            delete tea;
            cout << "注销成功" << endl;
            system("pause");
			system("cls");
			return ;
            break;
        }
	}
}

void managerMenu(Identity *&ma)
{
    while (true)
    {
        ma->operMenu();

        manager *man = (manager*)ma;

        int s = 0;
        cin>> s;
        switch (s)
        {
        case 1:
            man->addPerson();
            break;
        case 2:
            man->showPerson();
            break;
        case 3:
            man->showComputer();
            break;
        case 4:
            man->clearFile();
            break;
        default:
            delete man;
            cout << "注销成功" << endl;
            system("pause");
			system("cls");
			return ;
            break;
        }
    }
}

void studentMenu(Identity *&st)
{
	while (true)
	{
		st->operMenu();

		student *stu = (student *)st;
		int s = 0;
		cin >> s;
		switch (s)
        {
        case 1:
            stu->applyOrder();
            break;
        case 2:
            stu->showMyOrder();
            break;
        case 3:
            stu->showAllOrder();
            break;
        case 4:
            stu->cancelOrder();
            break;
        default:
            delete stu;
            cout << "注销成功" << endl;
            system("pause");
			system("cls");
			return ;
            break;
        }
	}
}

void Login(string filename, int type)
{
	Identity *person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);


	if(!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name, pwd;

	if(type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if(type == 1)
	{
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{

			if(fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");

				person = new student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
		
	}
	else if(type == 2)
	{
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{

			if(fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师验证登录成功" << endl;
				system("pause");
				system("cls");

				person = new teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if(type == 3)
	{
		string fName, fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{

			if(fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");

				person = new manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败" << endl;

	system("pause");
	system("cls");


}

int main()
{
	while (1)
	{
		cout << "======================  欢迎来到机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1://学生
			Login(STUDENT_FILE, 1);
			break;
		case 2://老师
			Login(TEACHER_FILE, 2);
			break;
		case 3://管理员
			Login(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
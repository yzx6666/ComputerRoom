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
            cout << "ע���ɹ�" << endl;
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
            cout << "ע���ɹ�" << endl;
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
            cout << "ע���ɹ�" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name, pwd;

	if(type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if(type == 1)
	{
		int fId;
		string fName, fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{

			if(fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
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
				cout << "��ʦ��֤��¼�ɹ�" << endl;
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
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��" << endl;

	system("pause");
	system("cls");


}

int main()
{
	while (1)
	{
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1://ѧ��
			Login(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			Login(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			Login(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
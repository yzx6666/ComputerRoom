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
    cout << "欢迎教师：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void teacher::showAllOrder()
{
	order od;
	if(od.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for(int i = 0; i < od.m_size; i ++) 
	{
		cout << i + 1 << "、 ";
		cout << "预约日期： 周" << od.m_orderDate[i]["date"];
		cout << " 时间段： " << (od.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号： " << od.m_orderDate[i]["StuId"];
		cout << " 姓名： " << od.m_orderDate[i]["StuName"];
		cout << " 机房编号： " << od.m_orderDate[i]["roomId"];

		string status = " 状态: ";
		if(od.m_orderDate[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if(od.m_orderDate[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if(od.m_orderDate[i]["status"] == "3")
		{
			status += "预约失败";
		}
		else if(od.m_orderDate[i]["status"] == "4")
		{
			status += "预约已取消";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下：" << endl;

	vector<int> v;
	v.clear();
	int idx = 0;
	for(int i = 0; i < od.m_size; i ++) 
	{
		if(od.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++idx << "、 ";
			cout << "预约日期： 周" << od.m_orderDate[i]["date"];
			cout << " 时间段： " << (od.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学号： " << od.m_orderDate[i]["StuId"];
			cout << " 姓名： " << od.m_orderDate[i]["StuName"];
			cout << " 机房编号： " << od.m_orderDate[i]["roomId"];
			string status = " 状态: 审核中";
			cout << status << endl;
		}
	}

	cout << "请输入审核的预约记录， 0表示返回" << endl;
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
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;

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
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}
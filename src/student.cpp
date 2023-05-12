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
    cout << "欢迎学生代表：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void student::applyOrder()
{
	cout << "机房开放的时间为周一到周五" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date, interval, room;
	while (true)
	{
		cin >> date;
		if(date >= 1 && date <= 5) break;
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if(interval >= 1 && interval <= 2) break;
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房： " << endl;
	for(int i = 0; i < 3; i ++)
	{
		cout << vCom[i].m_cId << "号机房的容量： " << vCom[i].m_ma << endl;
	}
	
	while (true)
	{
		cin >> room;
		if(room >= 1 && room <= 3) break;
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

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
		cout << "无预约记录" << endl;
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
			cout << "预约日期： 周" << od.m_orderDate[i]["date"];
			cout << " 时间段： " << (od.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
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
	}
	if(!f) cout << "无预约记录" << endl;
	system("pause");
	system("cls");

}

void student::showAllOrder()
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

void student::cancelOrder()
{
    order od;
	if (od.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v; //存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < od.m_size; i++)
	{
		//先判断是自身学号
		if (this->m_id == atoi(od.m_orderDate[i]["StuId"].c_str()))
		{
			//再筛选状态  审核中或预约成功
			if (od.m_orderDate[i]["status"] == "1" || od.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期： 周" << od.m_orderDate[i]["date"];
				cout << " 时间段： " << (od.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房编号： " << od.m_orderDate[i]["roomId"];
				string status = " 状态： ";
				if (od.m_orderDate[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (od.m_orderDate[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}


	cout << "请输入取消的记录，0代表返回" << endl;
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

				cout << "已取消预约" << endl;
				break;
			}
		}

		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}
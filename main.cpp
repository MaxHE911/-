#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"Identity.h"
#include<algorithm>
using namespace std;

//登录函数封装
void LogIn(std::string fileName, int type);
//管理员模块
void managerMenu(Identity* &manager);
//学生模块
void studentMenu(Identity*& student);
//老师模块
void teacherMenu(Identity*& teacher);

int main() {
	using namespace std;
	//进行菜单的创建
	while (true)
	{
		int select = 0;//用户选项
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
		cin >> select;
		switch (select)
		{
		case 1://学生
			LogIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LogIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LogIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下一次使用" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入有误，重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}

void LogIn(std::string fileName, int type)
{
	Identity* person = NULL;//创建抽象父类指针
	std::ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "文件未打开" << endl;
		return;
	}

	//读入信息，并验证身份


	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	//读取文件时请一定保证txt文件的编码方式为ansi
	int fid;
	string fname, fpwd;
	switch (type)
	{
	case 1://学生身份验证
		while (!ifs.eof())//这里进行循环验证，效率较低，实际上可以通过stl中的map或hash算法查找
		{
			ifs >> fid >> fname >> fpwd;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
		break;
	case 2://老师验证登录
		while (!ifs.eof())//这里进行循环验证，效率较低，实际上可以通过stl中的map或hash算法查找
		{
			ifs >>fid>> fname >> fpwd;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "老师登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(fid, fname, fpwd);
				teacherMenu(person);
				return;
			}
		}
		break;
	case 3://管理员登录验证
		while (!ifs.eof())//这里进行循环验证，效率较低，实际上可以通过stl中的map或hash算法查找
		{
			ifs >> fname >> fpwd;
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(fname, fpwd);
				//这里管理员模块的实现可以写在opeMenu中，再通过person->opeMenu实现；但是为了增加行数，写成一个全局函数的形式（笑
				managerMenu(person);
				return;
			}
		}
		break;
	default:
		break;
	}
	ifs.close();
	cout << "登录失败" << endl;
	system("pause");
	system("cls");
	return;
}

void managerMenu(Identity* &manager)
{
	Manager* man = (Manager*)manager;
	while (true)
	{
		//管理员菜单
		man->opeMenu();
		int select = 0;
		cin >> select;
		if (select == 1)  //添加账号
		{
			cout << "----添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "----查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "----查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "----清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity*& student)
{
	Student* stu = (Student*)student;
	while (true)
	{
		//学生菜单
		student->opeMenu();

		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(Identity*& teacher) 
{
	while (true)
	{
		//教师菜单
		teacher->opeMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
#include"manager.h"


	//构造函数、
Manager::Manager(std::string name, std::string paw)
{
	this->m_name = name;
	this->m_pwd = paw;
	this->initData();//同理，这里可以用map容器初始化，效率更高，这里为了简便，用vector存储
}

	//菜单界面、
void Manager::opeMenu()
{
	using namespace std;
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
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
	//添加账号
void Manager::addPerson()
{
	std::cout << "输入添加对象" << std::endl;
	std::cout << "1.添加学生" << std::endl << "2.添加老师" << std::endl;
	std::string filename,tip;
	std::ofstream ofs;
	int select;
	std::cin >> select;
	if (select == 1)
	{
		tip = "请输入学号";
		filename = STUDENT_FILE;
	}
	else if (select == 2)
	{
		tip = "请输入职工号";
		filename = TEACHER_FILE;
	}
	else
	{
		std::cout << "操作错误，退出添加操作" << std::endl;
		return;
	}

	ofs.open(filename, std::ios::out | std::ios::app);
	int id;
	std::string name,pwd;

	while (true)
	{
		std::cout << tip << std::endl;
		std::cin >> id;

		std::cout << "请输入姓名： " << std::endl;
		std::cin >> name;

		std::cout << "请输入密码： " << std::endl;
		std::cin >> pwd;
		if (this->check(id, select))
			cout << "信息重复，请重新输入" << endl;
		else break;
	}


	ofs <<id << " " << name << " " << pwd << " " << std::endl;
	std::cout << "添加成功" << std::endl;

	system("pause");
	system("cls");

	ofs.close();
	//更新数据
	this->initData();
}

	//查看账号、
void printStudent(Student& s)
{
	cout << "学号： " << s.m_id << " 姓名： " << s.m_name << " 密码：" << s.m_pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号： " << t.m_wid << " 姓名： " << t.m_name << " 密码：" << t.m_pwd << endl;
}
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);//也可用迭代器遍历，这里用stl中自带的遍历算法主要是起练习作用
	}
	else
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

	//查看机房信息、
void printComputer(ComputerRoom& c)
{
	cout << "机房编号： " << c.m_ComId << " 机房最大容量： " << c.m_MaxNum << endl;
}
void Manager::showComputer()
{
	cout << "机房信息如下： " << endl;
	for_each(vCom.begin(), vCom.end(), printComputer);
	system("pause");
	system("cls");
}

	//清空预约信息、
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "已清空预约信息" << endl;
	system("pause");
	system("cls");
	return;
}

   //初始化数据、
void Manager::initData()
{
	vStu.clear();
	vTea.clear();
	vCom.clear();
	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close(); 

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_wid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为： " << vTea.size() << endl;
	ifs.close();

	//读取机房信息
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为： " << vCom.size() << endl;
	ifs.close();
}

   //检测重复、
bool Manager::check(int id,int type)
{
	if (type == 1)
	{
		for (auto it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (auto it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_wid)
			{
				return true;
			}
		}
	}
	return false;
}



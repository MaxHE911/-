#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include"Identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:
	//构造函数
	Manager(std::string name, std::string paw);

	//菜单界面
	virtual void opeMenu();
	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约信息
	void cleanFile();

	//初始化数据
	void initData();

	//判断重复
	bool check(int id,int type);

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom> vCom;//因为我们假设了机房数量不变，所以直接在manager中初始化，但若可以修改机房数量，建议还是封装起来为好
};
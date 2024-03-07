#pragma once
#include<iostream>
#include<algorithm>
#include"Identity.h"
#include<vector>
#include<fstream>
#include"computerRoom.h"
#include"orderFile.h"
using namespace std;


class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, std::string name, std::string pwd);
	
	//菜单界面
	virtual void opeMenu();
	//申请预约
	void applyOrder();
	//查看自身预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
	
	//学生学号
	int m_id;
	std::vector<ComputerRoom> vCom;

};
#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include"Identity.h"
#include"orderFile.h"
#include<vector>

class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//构造函数
	Teacher(int wid,std::string name,std::string paw);
	
	//菜单界面
	virtual void opeMenu();
	//查看预约
	void showAllOrder();

	//审核预约
	void validOrder();
	//职工编号
	int m_wid;
};
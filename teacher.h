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
	//Ĭ�Ϲ���
	Teacher();
	//���캯��
	Teacher(int wid,std::string name,std::string paw);
	
	//�˵�����
	virtual void opeMenu();
	//�鿴ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();
	//ְ�����
	int m_wid;
};
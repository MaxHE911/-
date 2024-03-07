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
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, std::string name, std::string pwd);
	
	//�˵�����
	virtual void opeMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	
	//ѧ��ѧ��
	int m_id;
	std::vector<ComputerRoom> vCom;

};
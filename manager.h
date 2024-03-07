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
	//���캯��
	Manager(std::string name, std::string paw);

	//�˵�����
	virtual void opeMenu();
	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��Ϣ
	void cleanFile();

	//��ʼ������
	void initData();

	//�ж��ظ�
	bool check(int id,int type);

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom> vCom;//��Ϊ���Ǽ����˻����������䣬����ֱ����manager�г�ʼ�������������޸Ļ������������黹�Ƿ�װ����Ϊ��
};
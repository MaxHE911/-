/*
ѧ������ʦ������Ա��ͨ�õĹ��ԣ����и��ԵĶ����ԡ�
������c++�еĶ�̬����ʵ�֡��ʴ˴�����һ������Ļ���--Identity
IdentityΪ����Ļ��ֻ࣬�ð���.h�ļ��������������е��麯��������д
*/

#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"globalFile.h"
 
class Identity
{
public:/*�˴�дΪprotected��Ϊ���ʣ���Ȼ���ǲ�ϣ���ⲿ����ı����ݣ�
	��дΪprotected����Ҫд�϶�ӿڣ��˴�Ϊ�˼򵥣�ֱ��дΪpublic */
	virtual void opeMenu() = 0;//�˴������Գ��������Ĺ��ԣ���Ϊ�˷��㣬����һ��Ϊ��
	std::string m_name;
	std::string m_pwd;
};


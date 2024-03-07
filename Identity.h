/*
学生，老师，管理员有通用的共性，又有各自的独特性。
可以用c++中的多态技术实现。故此处创建一个抽象的基类--Identity
Identity为抽象的基类，只用包含.h文件，子类必须对其中的虚函数进行重写
*/

#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"globalFile.h"
 
class Identity
{
public:/*此处写为protected更为合适，显然我们不希望外部随意改变数据，
	但写为protected后需要写较多接口，此处为了简单，直接写为public */
	virtual void opeMenu() = 0;//此处还可以抽象出更多的共性，但为了方便，仅以一个为例
	std::string m_name;
	std::string m_pwd;
};


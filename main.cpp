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

//��¼������װ
void LogIn(std::string fileName, int type);
//����Աģ��
void managerMenu(Identity* &manager);
//ѧ��ģ��
void studentMenu(Identity*& student);
//��ʦģ��
void teacherMenu(Identity*& teacher);

int main() {
	using namespace std;
	//���в˵��Ĵ���
	while (true)
	{
		int select = 0;//�û�ѡ��
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;
		switch (select)
		{
		case 1://ѧ��
			LogIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LogIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LogIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}

void LogIn(std::string fileName, int type)
{
	Identity* person = NULL;//����������ָ��
	std::ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�δ��" << endl;
		return;
	}

	//������Ϣ������֤���


	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) //��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	//��ȡ�ļ�ʱ��һ����֤txt�ļ��ı��뷽ʽΪansi
	int fid;
	string fname, fpwd;
	switch (type)
	{
	case 1://ѧ�������֤
		while (!ifs.eof())//�������ѭ����֤��Ч�ʽϵͣ�ʵ���Ͽ���ͨ��stl�е�map��hash�㷨����
		{
			ifs >> fid >> fname >> fpwd;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
		break;
	case 2://��ʦ��֤��¼
		while (!ifs.eof())//�������ѭ����֤��Ч�ʽϵͣ�ʵ���Ͽ���ͨ��stl�е�map��hash�㷨����
		{
			ifs >>fid>> fname >> fpwd;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(fid, fname, fpwd);
				teacherMenu(person);
				return;
			}
		}
		break;
	case 3://����Ա��¼��֤
		while (!ifs.eof())//�������ѭ����֤��Ч�ʽϵͣ�ʵ���Ͽ���ͨ��stl�е�map��hash�㷨����
		{
			ifs >> fname >> fpwd;
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(fname, fpwd);
				//�������Աģ���ʵ�ֿ���д��opeMenu�У���ͨ��person->opeMenuʵ�֣�����Ϊ������������д��һ��ȫ�ֺ�������ʽ��Ц
				managerMenu(person);
				return;
			}
		}
		break;
	default:
		break;
	}
	ifs.close();
	cout << "��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}

void managerMenu(Identity* &manager)
{
	Manager* man = (Manager*)manager;
	while (true)
	{
		//����Ա�˵�
		man->opeMenu();
		int select = 0;
		cin >> select;
		if (select == 1)  //����˺�
		{
			cout << "----����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "----�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "----�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "----���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
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
		//ѧ���˵�
		student->opeMenu();

		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
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
		//��ʦ�˵�
		teacher->opeMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
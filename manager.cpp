#include"manager.h"


	//���캯����
Manager::Manager(std::string name, std::string paw)
{
	this->m_name = name;
	this->m_pwd = paw;
	this->initData();//ͬ�����������map������ʼ����Ч�ʸ��ߣ�����Ϊ�˼�㣬��vector�洢
}

	//�˵����桢
void Manager::opeMenu()
{
	using namespace std;
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
	//����˺�
void Manager::addPerson()
{
	std::cout << "������Ӷ���" << std::endl;
	std::cout << "1.���ѧ��" << std::endl << "2.�����ʦ" << std::endl;
	std::string filename,tip;
	std::ofstream ofs;
	int select;
	std::cin >> select;
	if (select == 1)
	{
		tip = "������ѧ��";
		filename = STUDENT_FILE;
	}
	else if (select == 2)
	{
		tip = "������ְ����";
		filename = TEACHER_FILE;
	}
	else
	{
		std::cout << "���������˳���Ӳ���" << std::endl;
		return;
	}

	ofs.open(filename, std::ios::out | std::ios::app);
	int id;
	std::string name,pwd;

	while (true)
	{
		std::cout << tip << std::endl;
		std::cin >> id;

		std::cout << "������������ " << std::endl;
		std::cin >> name;

		std::cout << "���������룺 " << std::endl;
		std::cin >> pwd;
		if (this->check(id, select))
			cout << "��Ϣ�ظ�������������" << endl;
		else break;
	}


	ofs <<id << " " << name << " " << pwd << " " << std::endl;
	std::cout << "��ӳɹ�" << std::endl;

	system("pause");
	system("cls");

	ofs.close();
	//��������
	this->initData();
}

	//�鿴�˺š�
void printStudent(Student& s)
{
	cout << "ѧ�ţ� " << s.m_id << " ������ " << s.m_name << " ���룺" << s.m_pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ� " << t.m_wid << " ������ " << t.m_name << " ���룺" << t.m_pwd << endl;
}
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);//Ҳ���õ�����������������stl���Դ��ı����㷨��Ҫ������ϰ����
	}
	else
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

	//�鿴������Ϣ��
void printComputer(ComputerRoom& c)
{
	cout << "������ţ� " << c.m_ComId << " ������������� " << c.m_MaxNum << endl;
}
void Manager::showComputer()
{
	cout << "������Ϣ���£� " << endl;
	for_each(vCom.begin(), vCom.end(), printComputer);
	system("pause");
	system("cls");
}

	//���ԤԼ��Ϣ��
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "�����ԤԼ��Ϣ" << endl;
	system("pause");
	system("cls");
	return;
}

   //��ʼ�����ݡ�
void Manager::initData()
{
	vStu.clear();
	vTea.clear();
	vCom.clear();
	//��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close(); 

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_wid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;
	ifs.close();

	//��ȡ������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ�� " << vCom.size() << endl;
	ifs.close();
}

   //����ظ���
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



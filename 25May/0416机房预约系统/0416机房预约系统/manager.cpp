#include <iostream>
using namespace std;
#include "manager.h"

// Ĭ�Ϲ���
Manager::Manager()
{

}

// �вι��� ��ʼ������Ա��Ϣ
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ������ ��ȡ��ǰѧ������ʦ����
	this->initVector();

	// ��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������" << vCom.size() << endl;
}

// �˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա:" << this->m_Name << "��¼" << endl;
	cout << "\t\t -------------------------------\n" << endl;
	cout << "\t\t|          1.����˺�           |\n" << endl;
	cout << "\t\t|          2.�鿴�˺�           |\n" << endl;
	cout << "\t\t|          3.�鿴����           |\n" << endl;
	cout << "\t\t|          4.���ԤԼ           |\n" << endl;
	cout << "\t\t|          0.ע����¼           |\n" << endl;
	cout << "\t\t  -------------------------------\n" << endl;
	cout << "���������ѡ��:" << endl;


}

// ����˺�
void Manager::addPerson()
{
	cout << "����������˺�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string fileName;// �������ļ���
	string tip;// ��ʾ��id��

	string errorTip; // �ظ�������ʾ

	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�������������";
	}
	else if (select == 2)
	{
		// ��ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������";
	}
	// ����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	
	//  ����Ƿ��ظ�����
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			// �����ظ�����
			cout << errorTip << endl;

		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	// ���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();

	// ���³�ʼ������ ȷ��ÿ������µĳ�Ա���ܼ�ʱ���ļ��л�ȡ��
	this->initVector();
}
// ��ӡ�������
void printStudent(Student& s)
{
	cout << "ѧ��" << s.m_Id << " ������" << s.m_Name << " ���룺"
		<< s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ����" << t.m_EmpId << " ������" << t.m_Name << " ���룺"
		<< t.m_Pwd << endl;
}


// �鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// �鿴����ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		// �鿴������ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

// �鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������Ϊ��" << it->m_ComId << " �����������Ϊ��" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

// ���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}


// ��ʼ������
void Manager::initVector()
{
	// �������
	vStu.clear();
	vTea.clear();
	// ��ȡѧ������ʦ��Ϣ
	// ��ȡѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	// ��ȡ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();

}

// ȥ�غ�����װ id��ʾѧ��/ְ���� type��ʾ�������
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		// ���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}

	}
	else
	{
		// �����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
# include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
/*
����ԤԼϵͳҪ��
1 ��ݣ�
ѧ��:����ʹ�û���
��ʦ�����ѧ��ԤԼ����
����Ա������ʦ��ѧ�������˻�

2 ������
1�Ż������������20��
2�Ż������������50��
3�Ż������������100��

3����
���붩��û���ɹ���Ա�������
ѧ��ԤԼδ��һ���ڵĻ���ʹ�ã�ԤԼ����Ϊ��һ�����壬ԤԼʱ����ѡ�����绹������
��ʦ���ԤԼ������ʵ��������ԤԼͨ����ͨ��

ϵͳ��������
1 ���Ƚ����¼���棬��ѡ��¼���
ѧ��������ʦ������Ա���˳�

2 ÿ����ݶ���Ҫ��֤������Ӳ˵�
ѧ����Ҫ���룺ѧ�� ���� ��¼����
��ʦ          ְ���� ���� ��¼����
����Ա��Ҫ���� ����Ա���� ��¼����

3 ѧ�����幦��
3.1 ����ԤԼ����
3.2 �鿴����ԤԼ״̬
3.3 �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
3.4 ȡ������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
3.5 ע����¼ �˳���¼

4 ��ʦ���幦��
4.1 �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
4.2 ��ѧ��ԤԼ�������
4.3 ע����¼

5 ����Ա���幦��
5.1 ���ѧ�����ʦ�˺ţ���Ҫע��ѧ���ͽ�ʦ�˺Ų����ظ�
5.2 �鿴ѧ�����ʦȫ����Ϣ
5.3 �鿴���л�����Ϣ
5.4 �������ԤԼ��¼
5.5 ע����¼
*/

// ������ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		// ������ʦ�Ӳ˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// �鿴������ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			// ���ԤԼ
			tea->validOrder();
		}
		else
		{
			// ע����¼
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// ����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		// ����ѧ���Ӳ˵�
		student->operMenu();

		Student* stu = (Student*)student;

		int select;
		cin >> select;
		if (select == 1)
		{
			// ����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2)
		{
			// �鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			// �鿴������ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			// ȡ��ԤԼ
			stu->cancelOrder();
		}
		else
		{
			// ע����¼
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}


// �������Ա���Ӳ˵�
// ���뺯������һ��ָ��Identity���͵�ָ�룬��ָ����manager������
void managerMenu(Identity * &manager)
{
	while (true)
	{
		// ���ù���Ա���Ӳ˵�
		manager->operMenu();

		// ������ָ�� ת��Ϊi����ָ�� ���������е������ӿ�
		Manager* man = (Manager*)manager;// ǿ������ת�� ������Identityָ��ǿ��ת��Ϊ����ָ��Manager
		int select;
		cin >> select;
		if (select == 1)
		{
			// ����˺�
			//cout << "����˺�" << endl;
			man->addPerson();

		}
		else if (select == 2)
		{
			// �鿴�˺�
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			// �鿴����
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			// ���ԤԼ
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			cout << "ע����¼" << endl;
			delete manager;// ���ٵ���������
			cout << "ע����¼�ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
// ��¼����
// ����1-�����ļ��� ����2-�����������
void LogIn(string fileName, int type)
{
	Identity* person = NULL;// ����ָ�� ����ָ���������
	// ���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// �ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
	}
	// ׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		// ѧ�����
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		// ��ʦ���
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type == 1)
	{
		// ѧ�������֤
		int fId;// ���ļ��ж�ȡ��id��
		string fName;// ���ļ��ж�ȡ������
		string fPwd;// ���ļ��ж�ȡ������
		while (ifs>>fId && ifs >> fName && ifs >> fPwd)
		{
			 //�û�������Ϣ�������ļ��е���Ϣһ��
			// Ŀǰֱ����student.txt�ĵ���д���������ݣ�����ȡ��ʱ������������
			//ԭ���ǣ��ļ���UTF-8���뱣�棬C++ʹ�ñ��ر���(������GBK) ���¶�ȡʱ�޷���ȷ
			// �ȶ�ѧ������ʹ��Ӣ��
			// ���������ַ�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				// ����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		// ��ʦ�����֤
		int fId;// ���ļ��ж�ȡ��id��
		string fName;// ���ļ��ж�ȡ������
		string fPwd;// ���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//�û�������Ϣ�������ļ��е���Ϣһ��
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ�����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				// ������ʦ����Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if(type == 3)
	{
		// ����Ա�����֤
		string fName;// ���ļ��ж�ȡ������
		string fPwd;// ���ļ��ж�ȡ������
		while (ifs >> fName && ifs >> fPwd)
		{
			//�û�������Ϣ�������ļ��е���Ϣһ��
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա�����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// �������Ա����Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select;
	while (true)
	{
		cout << "======================= ��ӭ�������ԤԼϵͳ  =====================" << endl;
		cout << endl << "��������ݣ�" << endl;
		cout << "\t\t -------------------------------\n" << endl;
		cout << "\t\t|          1.ѧ������            |\n" << endl;
		cout << "\t\t|          2.��ʦ                |\n" << endl;
		cout << "\t\t|          3.����Ա              |\n" << endl;
		cout << "\t\t|          0.�˳�                |\n" << endl;
		cout << "\t\t  -------------------------------\n" << endl;
		cout << "���������ѡ��:";
		cin >> select;
		// �����û�ѡ�� ʵ�ֲ�ͬ����
		switch (select)
		{
		case 1:// ѧ�����
			LogIn(STUDENT_FILE, 1);
			break;
		case 2:// ��ʦ���
			LogIn(TEACHER_FILE, 2);
			break;
		case 3:// ����Ա���
			LogIn(ADMIN_FILE, 3);
			break;
		case 0:// �˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;

		}
	}

	system("pause");

	return 0;
}

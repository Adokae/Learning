# include <iostream>
using namespace std;
# include "ͨѶ¼����ϵͳ.h"
# include <string>
# define Max 1000
/*
ʵ��ͨѶ¼����ϵͳ��Ҫʵ�ֵĹ������£�
1 �����ϵ�ˣ���ͨѶ¼��������ˣ�
��Ϣ�������������Ա����䡢��ϵ�绰����ͥ��ַ����������1000��
2 ��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ�˵���Ϣ
3 ɾ����ϵ�ˣ���������ɾ��ָ����ϵ��
4 ������ϵ�ˣ�������������ָ����ϵ��
5 �޸���ϵ�ˣ��������������޸�ָ����ϵ��
6 �����ϵ�ˣ����ͨѶ¼��������Ϣ
7 �˳�ͨѶ¼���Ƴ���ǰʹ�õ�ͨѶ¼
*/

/*
ʵ�ֲ��裺
1 �˵���ʾ չʾ�û�ѡ���ܵĽ��� ʹ��showMenu()����
2 �û���ͬѡ�񣬽��벻ͬ���ܣ�ʹ��switch��֧�ṹ
3 �����ϵ�ˣ������ϵ�˽ṹ�� ���ͨѶ¼�ṹ�� main�����д���ͨѶ¼
4 ��ʾ��ϵ��:ͨѶ¼��û���ˣ���ʾ��¼Ϊ�գ�������ʾͨѶ¼����Ϣ
5 ɾ����ϵ�ˣ��ȼ����ϵ���Ƿ���ڣ���ɾ��
6 ������ϵ�ˣ����ж���Ҫ���ҵ����Ƿ���ڣ�������������ָ����ϵ����Ϣ
7 �޸���ϵ�ˣ����ж���Ҫ���ҵ����Ƿ���ڣ���������������Ӧ�޸�
8 �����ϵ�ˣ�ֱ�ӽ���¼������Ϊ0���߼����
*/

// ��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex; // 1 �� 2 Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};

// ͨѶ¼�ṹ��
struct AddressBooks
{
	// ͨѶ¼�б������ϵ������
	struct Person personArray[Max];
	// ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
	int m_Size;
};

void addPerson(AddressBooks* abs)
{
	// �ж�ͨѶ¼�����г�Ա����
	if (abs->m_Size == Max)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����Ա���������������" << endl;
		}
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (0 <= age <= 120)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "����������������������" << endl;
		}
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		// ���һ���˵���Ϣ��ͨѶ¼������1
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");// ��������
	}
}

// 2 ��ʾ������ϵ��
void showPerson(AddressBooks* abs)
{
	// �ж�ͨѶ¼������
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ��޷���ʾ" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//3 �����ϵ���Ƿ���� ������ ������ϵ���������еľ���δ֪
// �������ڷ���-1 ����ͨѶ¼��Ҫ�ҵ�������
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1; // δ�ҵ�
}

// 4 ɾ����ϵ��
void deletePerson(AddressBooks* abs)
{
	cout << "����Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		// ����ɾ��������ʵ��ʹ�ú�����˸���Ҫɾ������
		// ���յ���������1
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// 4 ������ϵ��
void findPerson(AddressBooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��":"Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}


// 5 �޸�ָ����ϵ����Ϣ
void modifyPerson(AddressBooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "�������޸ĺ����ϵ��������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		int sex = 0;
		cout << "�������޸ĺ����ϵ�˵��Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����Ա���������������" << endl;
		}
		int age;
		cout << "�������޸ĺ����ϵ�����䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		string phone;
		cout << "�������޸ĺ����ϵ�˵绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		string address;
		cout << "�������޸ĺ����ϵ�˵�ַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// 6 �����ϵ��
void cleanPerson(AddressBooks * abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// ����ͨѶ¼�ṹ�����
	AddressBooks abs;
	// ��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0; // �û�ѡ��ı���

	while (true)
	{
		showMenu();
		cout << "�����û���Ҫѡ��ı�����" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			// �����ϵ��
			addPerson(&abs); // ���õ�ַ�����޸�ʵ��ֵ
			break;
		case 2:
			// ��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:
			// ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:
			// ������ϵ��
			findPerson(&abs);
			break;
		case 5:
			// �޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:
			// �����ϵ��
			cleanPerson(&abs);
			break;
		case 0:
			// �˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	/*system("pause");
	return 0;*/
}

# include <iostream>
using namespace std;
# include <fstream>
/*
�Զ����Ʒ�ʽ���ļ����ж�д������
�򿪷�ʽָ��Ϊ��ios::binary

д�ļ���Ҫ������������ó�Ա����write
����ԭ�ͣ�ostream& write(const char * buffer, int len)

���ļ�������
����ԭ�ͣ�istream& read(char * buffer, int len)
*/

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

// �������ļ����ļ�����
void test2()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	// ���ļ�
	Person p;
	ifs.read((char *)&p, sizeof(Person));
	cout << p.m_Age << endl;
	cout << p.m_Name << endl;
	ifs.close();
}

// �������ļ�д�ļ�����
void test1()
{
	ofstream ofs;

	ofs.open("person.txt", ios::out | ios::binary);

	Person p = { "����", 20 };

	ofs.write((const char*)&p, sizeof(Person));

	ofs.close();
}

int main()
{
	test2();
	//test1();
	system("pause");

	return 0;
}

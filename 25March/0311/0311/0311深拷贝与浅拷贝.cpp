# include <iostream>
using namespace std;

/*
ǳ�������򵥵ĸ�ֵ��������
������ڶ�����������ռ䣬���п�������

����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯��
���ǳ��������������
*/
class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age, int height)
	{
		cout << "Person���вι��캯������" << endl;
		m_age = age;
		Height = new int(height);
	}

	// ���
	Person(const Person& p)
	{
		cout << "Person�������캯���ĵ���" << endl;
		m_age = p.m_age;
		//Height = p.Height; ��һ�д����Ǳ�����Ĭ��ִ�еĴ���

		// ���
		Height = new int(*p.Height);
	}
	~Person()
	{
		// �������� �����������������ͷŲ���
		if (Height != NULL)
		{
			delete Height;
			Height = NULL;
		}
		cout << "Person��������������" << endl;
	}
	int m_age;
	int* Height;
};
void test1()
{
	Person p1(18, 160);
	cout << "p1�����䣺 " << p1.m_age << "���Ϊ��" << *p1.Height<< endl;
	// ǳ���� p2���ͷŶ����ڴ� p1�ͷ�ʱ����ֱ��� ��Ϊ���Ǵ洢����ͬһ����
	// ǳ����������������Ƕ����ڴ���ظ��ͷ�
	Person p2(p1);
	cout << "p2�����䣺 " << p2.m_age << "���Ϊ��" << *p1.Height<< endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}

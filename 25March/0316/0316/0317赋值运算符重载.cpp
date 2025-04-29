# include <iostream>
using namespace std;

/*
C++��������һ��������ĸ�������
1 Ĭ�Ϲ��캯��
2 Ĭ����������
3 Ĭ�Ͽ������캯��
4 ��ֵ�����operator=�������Խ���ֵ����
*/
// ��ֵ���������
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}

	// ǳ���� ������� ��Ϊp2�ͷ��ڴ� ��ԭ����p1�ڴ��ַҲ���ͷ���
	// ʹ��������
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	// ���ظ�ֵ�����
	Person& operator=(Person &p)
	{
		// �������ṩǳ����
		//m_Age = p.m_Age;
		// Ӧ�����ж��Ƿ��������ڶ��� �������ͷŸɾ� Ȼ�������
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		// ���
		m_Age = new int(*p.m_Age);

		return *this;
	}
	int *m_Age;
};
void test1()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1;
	cout << "p1������Ϊ" << *p1.m_Age << endl;
	cout << "p2������Ϊ" << *p2.m_Age << endl;
	cout << "p3������Ϊ" << *p3.m_Age << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

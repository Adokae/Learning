# include <iostream>
using namespace std;

/*
�������캯������ʱ����
1 ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
2 ֵ���ݵķ�ʽ������������ֵ
3 ��ֵ��ʽ���ؾֲ�����
*/
class Person
{
public:
	Person()
	{
		cout << "PersonĬ�Ϲ��캯������" << endl;
	}
	Person(int age)
	{
		cout << "Person�вι��캯������" << endl;
		m_Age = age;
	}
	Person(const Person & p)
	{
		cout << "Person�������캯������" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person������������" << endl;
	}
	int m_Age;
};

//1 ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test1()
{
	Person p1(20);
	Person p2(p1);
	cout << "P2������" << p2.m_Age << endl;
}

//2 ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p)
{

}
void test2()
{
	Person p; // Ĭ�Ϲ��캯��
	doWork(p);// ʵ�δ����βε�ʱ�� ����ÿ������캯��
}

//3 ��ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;
	return p1;// ���ص��ǰ�p1���������µĶ���
}

void test3()
{
	Person p = doWork2();// ���յ�p�ͺ����ж����p1����ͬһ������
}

int main()
{
	//test1();
	test3();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;
/*
��ģ���г�Ա��������ͨ���г�Ա��������ʵ������ȥ��ģ�
1 ��ͨ���г�Ա����һ��ʼ�Ϳ��Դ���
2 ��ģ���г�Ա�����ڵ���ʱ�Ŵ���
*/
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;// T�������κ�����
	// ��ģ���еĳ�Ա���� һ��ʼ���ᴴ��
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

void test1()
{
	MyClass<Person1>m;
	m.func1();// ֻ���ڵ���ʱ����ȷ���������� ����ȥ����
	//m.func2();
}

int main()
{
	test1();
	system("pause");

	return 0;
}

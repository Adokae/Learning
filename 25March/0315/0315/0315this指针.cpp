# include <iostream>
using namespace std;
/*
�Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ�������ͬ���͵Ķ���Ṳ��һ�����
C++��ͨ��thisָ�������Ǹ�������÷Ǿ�̬��Ա����

thisָ��ָ�򱻵��õĳ�Ա���������Ķ���

thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
thisָ�벻��Ҫ���� ֱ��ʹ�ü���

thisָ�����;��
1 ���β����Ա����ͬ��ʱ������thisָ��������
2 ����ķǾ�̬��Ա�����з��ض����� ��ʹ��return * this

*/

class Person
{
public:

	Person(int age)
	{
		// thisָ�����Person��Ա������p1����
		this->age = age;
	}

	// ����ֵ�Ǵ���һ���µĶ���
	// ���������Ƿ����䱾��
	Person& PersonAddAge(Person& p)
	{
		this->age += p.age;
		// thisָ��p2��ָ�� ��*thisָ���p2����
		return *this;
	}

	int age;
};
//1 ������Ƴ�ͻ
void test1()
{
	Person p1(18);
	cout << "the age of p1 is " << p1.age << endl;
}

// 2 ���ض�����*this
void test2()
{
	Person p1(10);
	Person p2(10);
	// ����û�з���ֵ ֻ�ܵ���1��
	//p2.PersonAddAge(p1);

	// ���������ر���
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "the age of p2 is " << p2.age << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;

/*
������������أ�
���ã���������Զ�����������
*/

class Person
{
	friend ostream& operator<< (ostream& cout, Person& p);

public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:

	// �������ó�Ա��������<<����� �޷�ʵ��cout�����
	// ��Ա�������ֵĽ��Ϊp<< cout
	/*void operator<<(cout)
	{
	}*/
	int m_A;
	int m_B;
};

// ȫ�ֺ����������������
// ��������operator << (cout, p) ��cout<<p
ostream & operator<< (ostream &cout,Person &p)
{
	cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
	return cout;
}
void test1()
{
	Person p(10, 10);
	//p.m_A = 10;
	//p.m_B = 10;
	/*cout << p.m_A << endl;
	cout << p.m_B << endl;*/
	//cout << p;// ȫ�ֺ��������޷���ֵ
	cout << p << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

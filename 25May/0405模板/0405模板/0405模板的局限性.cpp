# include <iostream>
using namespace std;

/*
ģ��ľ����ԣ�
ģ�岻�����ܵģ���Щ�ض����������ͣ���Ҫʹ�þ��廯�ķ�ʽ������ʵ��
ѧϰģ����Ϊ����STL���ܹ�ʹ��ϵͳ�ṩ��ģ��
*/
class Person
{
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	// ����
	string m_Name;
	// ����
	int m_Age;
};

// ʹ��ģ��ʵ���ж����������Ƿ����
template<typename T>
bool myCompare(T& a, T& b)
{
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
// ���þ��廯��Person�汾ʵ�ִ��룬���廯���ȵ���
// template<>��ʾ���߱������ⲻ��һ��ͨ�õ�ģ�壬�����ض����͵�ģ��
template<> bool myCompare(Person& p1, Person& p2) 
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
		return true;
	}
	else {
		return false;
	}
}

void test1()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret) {
		cout << "a == b" << endl;
	}
	else {
		cout << "a != b" << endl;
	}
}

void test2()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);// ʵ��ִ�е�ʱ�򱨴� ���޷��Ƚ�Person���͵���ֵ
	if (ret) {
		cout << "p1 == p2" << endl;
	}
	else {
		cout << "p2 != p2" << endl;
	}
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

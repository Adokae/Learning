# include <iostream>
using namespace std;

/*
����ģ��ע�����
1 �Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
2 ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
*/
template<typename T> // typename���Ի���class

void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test1()
{
	int a = 10;
	int b = 20;
	char c = 'a';
	cout << "a = " << endl;
	cout << "b = " << endl;
	//mySwap(a, b);
	//ע������1
	//mySwap(a, c); // ���� �Ƶ�����һ�µ���������
	cout << "a = " << endl;
	cout << "b = " << endl;
}
//ע������2
template<typename T>
void func()
{
	cout << "func ����" << endl;
}
void test2()
{
	//func(); // ����
	func<int>();
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

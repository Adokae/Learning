# include <iostream>
using namespace std;

/*
�������أ�
���ã�������������ͬ����߸�����

������������������
1 ͬһ����������
2 ����������ͬ
3 �������� ���Ͳ�ͬ�������ͬ��˳��ͬ

ע�⣺�����ķ���ֵ��������Ϊ�������ص�����
*/

// ����1
void func()
{
	cout << "this is a fuction" << endl;
}

void func(int a)
{
	cout << "this is int a fuction!" << endl;
}
void func(double a)
{
	cout << "this is double a fuction!!" << endl;
}
void func(double a, int b)
{
	cout << "this is double a int b fuction!!" << endl;
}
void func(int a, double b)
{
	cout << "this is int a double b fuction!!" << endl;
}
// ����ʾ�� ��������ֵ��Ϊ�������ص�����
//int func(int a, double b)
//{
//	cout << "this is int a double b fuction!!" << endl;
//}
int main()
{
	func(2, 10.1);
	system("pause");

	return 0;
}

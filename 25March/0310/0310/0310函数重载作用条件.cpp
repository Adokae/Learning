# include <iostream>
using namespace std;

/*
��������ע���¼���
1 ������Ϊ��������
2 ����������������Ĭ�ϲ���
*/

//1 ������Ϊ��������
void func(int &a) // int &a = 10; �Ƿ�
{
	cout << "func(&a) ����" << endl;
}
void func(const int& a)// const int &a = 10; �Ϸ�
{
	cout << "func const (&a) ����" << endl;
}
// 2 ����������������Ĭ�ϲ���
void func2(int a, int b=10)
{
	cout << "func2 int a int b" << endl;
}
void func2(int a)
{
	cout << "func2 int a" << endl;
}
int main()
{
	int a = 10;
	func(a);

	func(10); // ����const���͵�func

	//func2(10); ������������Ĭ�ϲ��������ֶ����ԣ�����Ӧ��������
	system("pause");

	return 0;
}

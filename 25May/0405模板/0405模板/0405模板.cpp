# include <iostream>
using namespace std;
/*
��Ҫ��Է��ͱ����STL�������н���

ģ�����ͨ��ģ��

C++�ṩ����ģ����ƣ�����ģ�����ģ��

����ģ�����ã�����һ��ͨ�ú������亯������ֵ���ͺ��β����Ͳ�����ָ����
������һ���������������ʾ

�﷨��
template<typename T>
template--��������ģ��
typename--���������ķ�����һ���������ͣ�������class����
T--ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ

����ģ��ע�����
1 �Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
2 ģ�����Ҫȷ��T���������ͣ��ſ���ʹ��
*/

//����ģ��

//�������ͽ�������
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//�������������ͺ���
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��
template<typename T> // ����һ��ģ�� 
//���߱�������������н����ŵ�T��Ҫ���� T��һ��ͨ����������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


void test1()
{
	int a = 10;
	int b = 5;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//swapInt(a, b);
	// ���ú���ģ��ʵ�ֺ���
	// ���ַ�ʽʹ�ú���ģ��
	// 1 �Զ������Ƶ�
	//mySwap(a, b);
	// 2 ��ʾָ������
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 1.1;
	double d = 5.5;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	swapDouble(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}

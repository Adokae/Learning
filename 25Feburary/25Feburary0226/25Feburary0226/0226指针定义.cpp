# include <iostream>
using namespace std;

/*
ָ�����ã�����ͨ��ָ���ӷ����ڴ�
�ڴ��Ŵ�0��ʼ��һ����ʮ���������ֱ�ʾ
������ָ����������ַ���ڴ��ַ��

ָ����������﷨�� �������� * ������;
*/

/*
ָ��Ҳ�����������ͣ�
��32λ����ϵͳ�£�ָ��ռ��4���ֽڿռ�
��64λ����ϵͳ�£�ָ��ռ��8���ֽڿռ�
*/
int main()
{
	// ����ָ��
	int a = 10;
	int * p;
	// ��ָ���¼����a�ĵ�ַ
	p = &a;

	// int * p = &a;

	cout << "a�ĵ�ַ" << &a << endl;
	cout << "ָ��pΪ" << p << endl;
	*p = 1000;
	cout << "a=" << a << endl;
	cout << "*pΪ" << *p << endl;
	// ʹ��ָ��
	// ����ͨ����Ӧ�õķ�ʽ�ҵ�ָ��ָ����ڴ��ַ
	// ָ��ǰ�� * ��ʾ������ �ҵ�ָ��ָ���ڴ��е�����

	// ָ����ռ�ڴ�ռ��С
	cout << "sizeof (int *)=" << sizeof(p) << endl;

	cout << "sizeof (int *)=" << sizeof(int *) << endl;
	cout << "sizeof (double *)=" << sizeof(double *) << endl;
	cout << "sizeof (char *)=" << sizeof(char *) << endl;

	system("pause");

	return 0;
}
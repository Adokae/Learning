# include <iostream>
using namespace std;

/*
���õı�����C++�ڲ���һ��ָ�볣��
����һ����ʼ���������Է����ı�-��ָ��ָ�򲻿��Ըı�
*/
void func(int& ref)
{
	ref = 100;
}

int main()
{
	int a = 10;
	// ������int * const ref = &a;
	// ָ�볣����ָ��ָ�򲻿��Ը���
	// ָ��ָ���ֵ���Ը���
	int& ref = a;

	// ʵ����*ref = 20; �޸�ָ��ָ���ֵ
	ref = 20;
	cout << "a=" << a << endl;
	cout << "ref=" << ref << endl;
	system("pause");

	return 0;
}

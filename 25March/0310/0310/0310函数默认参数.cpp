# include <iostream>
using namespace std;
/*
����Ĭ�ϲ����������β��б��е��β��ǿ�����Ĭ��ֵ��
�﷨:����ֵ���� ������ ������=Ĭ��ֵ��{}

�����������ݣ�ʹ���������ݣ�δ�������ݣ�ʹ��Ĭ��ֵ

ע�����
1 ��ĳ��λ���Ѿ�����Ĭ��ֵ����Ӹ�λ�����󣬴����Ҷ�������Ĭ��ֵ
2 ������������Ĭ�ϲ��� ����ʵ�־Ͳ�����Ĭ�ϲ���
������ʵ��ֻ����һ��Ĭ�ϲ���
*/
int func(int a, int b = 20, int c = 20)
{
	return a + b + c;
}

int func2(int a = 10, int b=20);

int func2(int a , int b)
{
	return a + b;
}

int main()
{
	cout << func(10) << endl;
	cout << func2(10, 20) << endl;
	system("pause");

	return 0;
}

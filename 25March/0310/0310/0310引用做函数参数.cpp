# include <iostream>
using namespace std;
/*
����������������
��������ʱ�������������ü������β�����ʵ��
�ŵ㣺���Լ�ָ���޸�ʵ��
*/
// ��������
void Swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
// ��ַ����
void Swap2(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ���ô��� ���ñ�ľ���ʵ�ε�ֵ
void Swap3(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap1(a, b); // ֵ���ݣ��ββ�������ʵ��
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	Swap2(&a, &b); // ��ַ���ݣ��βλ�����ʵ��
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	// �˴������a bֵΪ20 10
	Swap3(a, b); // ���ô��ݣ��βλ�����ʵ��
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	system("pause");

	return 0;
}

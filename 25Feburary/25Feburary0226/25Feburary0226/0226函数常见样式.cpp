# include <iostream>
using namespace std;
/*
4�ֳ����ĺ�����ʽ��
1 �޲��޷�
2 �в��޷�
3 �޲��з�
4 �в��з�
*/

// ��ʽ1
void type1()
{
	cout << "�����޲��޷�����" << endl;
}

// ��ʽ2
void type2(int a)
{
	cout << "�����в��޷�����" << endl;
	cout << "���" << a << endl;
}

// ��ʽ3
int type3()
{
	cout << "�����޲��з�����" << endl;
	return 100;
}

// ��ʽ4
int type4(int b)
{
	cout << "�����в��з�����" << endl;
	return b;
}
int main()
{

	//type1();

	int a = 10;
	type2(a);

	int num1 = type3();
	cout <<"����3�����еķ���ֵΪ" << num1 << endl;

	int num2 = type4(1000);
	cout << "����4�����еķ���ֵΪ" << num2 << endl;
	system("pause");

	return 0;
}
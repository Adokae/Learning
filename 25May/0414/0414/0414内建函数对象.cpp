# include <iostream>
using namespace std;
#include <functional>
/*
STL�ڽ�һЩ��������

���ࣺ
1 �����º���
2 ��ϵ�º���
3 �߼��º���

�º����������Ķ����÷���һ�㺯����ȫ��ͬ
ʹ���ڽ��������������ͷ�ļ�#include<fuctional>

�����º������ܣ�ʵ���������㣬ֻ��negateΪһԪ���㣬�������Ƕ�Ԫ����
�º���ԭ�ͣ�
1 template<class T> T plus <T> �ӷ��º���
1 template<class T> T minplus <T> �����º���
1 template<class T> T multiplies <T> �˷��º���
1 template<class T> T divides <T> �����º���
1 template<class T> T modulus <T> ȡģ�º���
1 template<class T> T negate <T> ȡ���º���

*/

// negate һԪ�º��� ȡ��
void test1()
{
	negate<int>n;
	cout << n(50) << endl;
}

// plus ��Ԫ�º��� �ӷ�
void test2()
{
	plus<int>p;
	cout << p(10, 20) << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

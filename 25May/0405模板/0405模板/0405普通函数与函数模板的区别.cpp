# include <iostream>
using namespace std;
/*
��ͨ�����뺯��ģ�������
1 ��ͨ��������ʱ���Է����Զ�����ת��(��ʽ����ת��)
2 ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
3 ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
*/

// ��ͨ����
int myAdd(int a, int b)
{
	return a + b;
}
// ����ģ��
template<typename T>
T myAdd1(T a, T b)
{
	return a + b;
}

void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//cout << myAdd(a, b) << endl;
	cout << myAdd(a, c) << endl;// ������ʽ����ת�� ת����'c'��ASCII��

	// ʹ�ú���ģ��
	cout << myAdd1(a, b) << endl; // �Զ������Ƶ�
	//cout << myAdd1(a, c) << endl; // �Զ������Ƶ� ����

	cout << myAdd1<int>(a, c) << endl; // �Զ������Ƶ�
}
int main()
{
	test1();
	system("pause");

	return 0;
}

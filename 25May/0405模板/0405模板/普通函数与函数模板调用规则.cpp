# include <iostream>
using namespace std;
/*
��ͨ�����ͺ���ģ��ĵ��ù���
1 �������ģ�����ͨ����������ʵ�� ���ȵ�����ͨ����
2 ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
3 ����ģ��Ҳ���Է�������
4 �������ģ����Բ������õ�ƥ�� ���ȵ��ú���ģ��

��Ȼ�ṩ�˺���ģ�� ��þͲ�Ҫ�ṩ��ͨ������ ���׳��ֶ�����
*/
void myPrint(int a, int b)
{
	cout << "������ͨ����" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "���ú���ģ��" << endl;
}

// ����ģ�������д
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "�������صĺ���ģ��" << endl;
}

void test1()
{
	int a = 10;
	int b = 20;
	//myPrint(a, b); // ������ͨ���� ���ȵ�����ͨ����
	// �����ͨ����ֻ������ û��ʵ�� ֱ�ӱ���

	// ͨ����ģ������б� ǿ�Ƶ��ú���ģ��
	/*myPrint<>(a, b);

	myPrint<>(a, b, 100);*/

	// �������ģ��������õ�ƥ�� ���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);// ����ģ�� ��Ϊ����ģ�����ֱ����ΪTΪchar����
	// �����ú�����ζ�Ż�Ҫ������ʽ����ת��
}

int main()
{
	test1();
	system("pause");

	return 0;
}

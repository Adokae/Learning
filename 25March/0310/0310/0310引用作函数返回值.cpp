# include <iostream>
using namespace std;

/*
��������������ֵ��
ע�⣺��Ҫ���ؾֲ���������
�÷�:����������Ϊ��ֵ
*/
// ����ʾ��
int& test1()
{
	int a = 10;
	return a;
}

// ����������Ϊ��ֵ
int& test2()
{
	static int a = 10; // ��̬�����������ȫ������
	//�����������ϵͳ�ͷ�
	return a;
}
int main()
{
	//int& ref = test1();
	//cout << "ref=" << ref << endl; // ����

	int& ref2 = test2();
	cout << "ref2=" << ref2 << endl; 

	// �����ķ���ֵ�����ã������ĵ��ÿ�����Ϊ��ֵ
	// test2()���ص���a�����ã���1000���Ƹ�a�����ã�
	// ref2��a�ı��� ��a�����þ͸�����ԭ����ref2ֵ
	test2() = 1000;
	cout << "ref2=" << ref2 << endl; // ����
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;

/*
���ڵĳ�Ա�������Ա�����ֿ��洢
ֻ�зǾ�̬��Ա������������Ķ�����
*/

class Person
{
	int m_A;// �Ǿ�̬��Ա���� ������Ķ�����

	static int m_B;// ��̬��Ա���� �������������

	void func() {} // �Ǿ�̬��Ա���� �������������

	static void func() {} // ��̬��Ա���� �������������
};
int Person::m_B = 0;

void test1()
{
	Person p;
	// �ն���ռ���ڴ�ռ�Ϊ��1���ֽ�
	// ��������ÿ���ն������һ���ֽڿռ� Ϊ�����ֶ���ռ�ڴ��λ��
	// ÿ���ն���ҲӦ�þ��ж�һ�޶����ڴ��ַ
	cout << "size of p is " << sizeof(p) << endl;
}

void test2()
{
	Person p;
	cout << "size of p is " << sizeof(p) << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

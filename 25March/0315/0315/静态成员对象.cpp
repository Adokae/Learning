# include <iostream>
using namespace std;

/*
��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ����ؼ���static����Ϊ��̬��Ա
��̬��Ա��Ϊ��
1 ��̬��Ա����
 ���ж�����ͬһ������
 �ڱ���׶η����ڴ�
 ���������������ʼ��
2 ��̬��Ա����
  ���ж�����ͬһ������
  ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
*/
class Person
{
public:
	// ��̬��Ա����
	static int m_A;// ��������

	// ��̬��Ա����Ҳ�Ǿ��з���Ȩ�޵�
private:
	static int m_B;
};

int Person::m_A = 100; // �����ʼ��
int Person::m_B = 200;

void test1()
{
	Person p;
	cout << p.m_A << endl;
	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl; // ���200 ����ͬһ������
}

void test2()
{
	// ��̬��Ա���� ������ĳ������ ���ж��󶼹���ͬһ������
	// ��̬��Ա���������ַ��ʷ�ʽ
	
	// 1 ͨ��������з���
	Person p;
	cout << p.m_A << endl;

	// 2 ͨ���������з���
	cout << Person::m_A << endl;

	// �ô������ ˽�б��� �����޷�����
	//cout << Person::m_B << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;
/*
const���γ�Ա������
��������
1 ��Ա������const���֮Ϊ������
2 �������ڲ������޸ĳ�Ա����
3 ��Ա��������ʱ����ؼ���mutable�� �ڳ���������Ȼ�����޸�

������
1 ��������ǰ��const�Ƹö���Ϊ������
2 ������ֻ�ܵ��ó�����
*/
class Person
{
public:

	// thisָ��ı�����ָ�볣�� ָ��ָ�򲻿��޸�
	// thisָ�벻�����޸�ָ���ָ��
	// ��const��ʵ������const Person * const this;
	// ��Ա�������const ���ε���thisָ�� ��ָ��ָ���ֵҲ�������޸�
	void showPerson() const
	{
		// ��������this->m_A = 10;
		//m_A = 100;
		m_B = 20;
	}
	void func()
	{
		m_A = 100;
	}

	int m_A;
	mutable int m_B;// ������� ʹ�伴ʹ�ڳ������� Ҳ���޸����ֵ
};

// ������
void test1()
{
	const Person p;// �ڶ���ǰ��const
	//p.m_A = 100; // �޷��޸�
	p.m_B = 200; // ��mutable������޸�

	p.showPerson(); //������ֻ�ܵ��ó�����
	//p.func();
	// �������ܵ�����ͨ��Ա���� ��Ϊ��ͨ��Ա���������޸�����
}
int main()
{
	test1();
	system("pause");

	return 0;
}

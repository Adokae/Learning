# include <iostream>
using namespace std;
/*
�̳е������޷����ʸ����˽������
�̳з�ʽ��
1 �����̳�
2 �����̳� �����еĹ������Ժͱ������Ա�Ϊ�����еı�������
3 ˽�м̳� �����еĹ������Ժͱ������Ա�Ϊ�����е�˽������
*/

// �����̳�
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;// �����еĹ���Ȩ�޳�Ա����������Ȼ�ǹ���Ȩ��
		m_B = 20;// �����еı���Ȩ�޳�Ա����������Ȼ�Ǳ���Ȩ��
		//m_C = 10;// �����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};

void test1()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100; // ����Ȩ�������޷�����
}

// �����̳�
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 10;// �����еĹ���Ȩ�޳�Ա�������б�Ϊ����Ȩ��
		m_B = 20;// �����еı���Ȩ�޳�Ա����������Ȼ�Ǳ���Ȩ��
		//m_C = 10;// �����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};

// ˽�м̳�
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 10;// �����еĹ���Ȩ�޳�Ա�������б�Ϊ˽��Ȩ��
		m_B = 20;// �����еı���Ȩ�޳�Ա�������б�Ϊ˽��Ȩ��
		//m_C = 10;// �����е�˽��Ȩ�޳�Ա ������ʲ���
	}
};
void test3()
{
	Son2 s3;
	//s1.m_A = 100;
	//s1.m_B = 100; // ����Ȩ�������޷�����
}


int main()
{
	test1();
	system("pause");

	return 0;
}

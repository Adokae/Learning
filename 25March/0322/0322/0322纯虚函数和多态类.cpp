# include <iostream>
using namespace std;
/*
��̬�У������麯��ʵ�������壬�ɽ��麯����Ϊ���麯��
���麯���﷨�� virtual ����ֵ���� ������ �������б�= 0;
�������˴��麯������Ҳ��Ϊ������

�������ص㣺
1 �޷�ʵ��������
Base = b; new Base; ���Ǵ����
2 ���������д�������еĴ��麯�� ����Ҳ���ڳ�����
����д Son s;����
*/

class Base
{
public:
	// ���麯��
	virtual void func() = 0;
	// ����Ϊ������
};
class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func��������" << endl;
	}
};

void test1()
{
	Base* base = new Son;
	base->func();
}

int main()
{
	test1();
	system("pause");

	return 0;
}

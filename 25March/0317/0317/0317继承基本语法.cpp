# include <iostream>
using namespace std;
/*
�̳У�����������������֮һ
�����ظ�����
�﷨�� class ���ࣺ�̳з�ʽ ����
����Ҳ��Ϊ������
����Ҳ��Ϊ����
*/

// ��ͨʵ��ҳ��
// Javaҳ��
//class Java
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��....������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������....�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Jave��Python��....�����������б�" << endl;
//	}
//	void content()
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//};
//
//// Javaҳ��
//class Python
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��....������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������....�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Jave��Python��....�����������б�" << endl;
//	}
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//};

// �̳�ʵ��
class BasePage
{
public:
	public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��....������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������....�������ײ���" << endl;
	}
	void left()
	{
		cout << "Jave��Python��....�����������б�" << endl;
	}
};

// Javaҳ��
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}
};

// Pythonҳ��
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

void test1()
{
	cout << "Java������Ƶҳ��" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "--------------" << endl;
	cout << "Python������Ƶҳ��" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
}

int main()
{
	test1();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;

/*
�������������()����
���غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
�º����ǳ���û�й̶�д��
*/

// ��ӡ�����
class MyPrint
{
public:
	// ���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void MyPrint2(string test)
{
	cout << test << endl;
}

void test1()
{
	MyPrint myPrint;
	myPrint("hello world");// �º���
	MyPrint2("hello ");
}

// �ӷ���
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test2()
{
	MyAdd myadd;
	int ret = myadd(100, 200);
	cout << "ret = " << ret << endl;

	// ������������
	cout << MyAdd()(100, 100) << endl;
}
int main()
{
	test1();
	test2();
	system("pause");

	return 0;
}

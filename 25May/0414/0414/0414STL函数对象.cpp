# include <iostream>
using namespace std;

/*
��������
������غ������ò��������࣬����󳣳�Ϊ��������
��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���

���ʣ���������(�º���)��һ���࣬����һ������

ʹ�ã�
1 ����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
2 �������󳬳���ͨ�����ĸ����������������Լ���״̬
3 �������������Ϊ��������

*/
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

// �÷�1 ����ͨ������������
void test1()
{
	MyAdd myAdd;// ͨ���ഴ������
	cout << myAdd(10, 10) << endl;

}

// �÷�2 ��������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}
	int count; // �ڲ��Լ���״̬
};

void test2()
{

	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint���ô�����" << myPrint.count << endl;
}

// �÷�3 �������������Ϊ��������
void doPrint(MyPrint& m, string test)
{
	m(test);
}

void test3()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello World");
}


int main()
{
	//test1();
	//test2();
	test3();
	system("pause");

	return 0;
}

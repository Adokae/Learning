# include <iostream>
using namespace std;
/*
��ģ����̳У�
1 ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
2 ����ָ�����������޷�����������ڴ�
3 �������ָ����������T������ ����Ҳ��Ҫ�����ģ��
*/

template<class T>
class Base
{
	T m;
};

//class son :public Base// ���� ����֪��������T����������
class Son:public Base<int>
{

};

void test1()
{
	Son s1;// �ܹ�����ʵ��������
}

//�����ָ�������е�T���ͣ�����Ҳ��Ҫ����ģ��
template<class T1, class T2>
class Son2 :public Base<T2>// ָ�������е���������ΪT2
{
public:
	Son2()
	{
		cout << "T1����������" << typeid(T1).name() << endl;
		cout << "T2����������" << typeid(T2).name() << endl;
	}
	T1 obj;// �������������ΪT1
};

void test2()
{
	Son2<int, char>S2;// int����T1 char����T2
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

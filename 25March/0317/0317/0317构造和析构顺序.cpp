# include <iostream>
using namespace std;
/*
����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
�̳��еĹ��������˳�����£�
�ȹ��츸�࣬�ڹ������࣬
����˳���빹��˳���෴
*/
class Base
{
public:
	Base()
	{
		cout << "Base�Ĺ��캯��" << endl;
	}
	~Base()
	{
		cout << "Base����������" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son�Ĺ��캯��" << endl;
	}
	~Son()
	{
		cout << "Son����������" << endl;
	}
};
void test1()
{
	//Base b;
	Son s;
}

int main()
{
	test1();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;
#include <string>
/*
pair���鴴�����ɶԵ����ݣ����ö�����Է�����������

������ʽ��
1 pair<type, type> p (value1, value2);
2 pair<type, type> p = make_pair(value1, value2);

*/


void test1()
{
	// ��һ�ַ�ʽ����
	pair<string, int>p("A", 20);
	cout << "name = " << p.first << " age = " << p.second << endl;

	// �ڶ��ַ�ʽ����
	pair<string, int>p2 = make_pair("Bob", 40);
	cout << "name = " << p2.first << " age = " << p2.second << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}

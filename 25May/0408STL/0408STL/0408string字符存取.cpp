# include <iostream>
using namespace std;
#include <string>
/*
string�е����ַ���ȡ��ʽ�����֣�
1 char & operator[](int n);// ͨ��[]��ʽȡ�ַ�
2 char & at(int n);// ͨ��at����ȡ�ַ�
*/

void test1()
{
	string str = "hello ";
	cout << "str = " << str << endl;

	// ͨ��[]���ʵ����ַ�
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;


	// ͨ��at����ȡ�ַ�
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;


	// �޸��ַ����еĵ����ַ�
	str[0] = 'x';
	cout << "str = " << str << endl;

	str.at(1) = 'x';
	cout << "str = " << str << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

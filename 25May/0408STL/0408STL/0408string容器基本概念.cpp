# include <iostream>
using namespace std;
/*
string��C++�����ַ��� ��������һ����

string ��char *������
char *��һ��ָ��
string��һ���� ���ڲ���װ��char* ������ַ��� ��һ��char*�͵�����

�ص㣺
string���ڲ���װ�˺ܶ��Ա����
���磺����find ����copy ɾ��delete �滻replace ����insert

string����char*��������ڴ� ���õ��ĸ���Խ���ȡֵԽ��� �����ڲ����и���

string���캯����
1 string(); ����һ���յ��ַ���
2 string(const char* s); ʹ���ַ���s��ʼ��
3 string(const string& str)�� ʹ��һ��string�����ʼ����һ��string����
4 string(int n, char c); ʹ��n���ַ�c��ʼ��

*/

void test1() {
	string s1;// ��һ�ֹ��췽��

	const char* str = "hello world";// �ڶ��ֹ��췽��
	string s2(str);
	cout << "s2 = " << s2 << endl;

	// �����ֹ��췽��
	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "s4 = " << s4 << endl;
}


int main()
{
	test1();
	system("pause");

	return 0;
}

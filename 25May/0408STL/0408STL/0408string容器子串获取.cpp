# include <iostream>
using namespace std;
/*
�ַ���ȡ��
���ַ����л�ȡ��Ҫ���Ӵ�

������
string substr(int pos = 0,int n = npos) const; // ������pos��ʼ��n���ַ���ɵ��ַ���
*/

void test1() {
	string str1 = "abcdef";
	string subStr1 = str1.substr(1, 3);
	cout << "subStr1 = " << subStr1 << endl;
}


void test2() {
	string email = "Alice@sina.com";
	// ��email�л�ȡ�û���
	int pos = email.find("@");
	string userName = email.substr(0, pos);
	cout << "userName = " << userName << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

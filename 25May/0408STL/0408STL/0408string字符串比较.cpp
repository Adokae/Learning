# include <iostream>
using namespace std;
/*
�ַ����Ƚϣ�
 ���ַ���ASCII����бȽ�
 = 0
 > 1
 < -1

 ����:
 1 int compare(const string &s) const;//���ַ���s�Ƚ�
 2 int compare(const char *s);//���ַ���s�Ƚ�
*/

void test1()
{
	string str1 = "xello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "str1 = str2" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "str1 > str2" << endl;
	}
	else if (str1.compare(str2) < 0) {
		cout << "str1 < str2" << endl;
	}

}

int main()
{
	test1();
	system("pause");

	return 0;
}

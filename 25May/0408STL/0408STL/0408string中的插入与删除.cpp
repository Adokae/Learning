# include <iostream>
using namespace std;
/*
string�еĲ�����ɾ��:
��string�ַ������в����ɾ���ַ��Ĳ���

������
1 string& insert(int pos, const char * s);//�����ַ���
2 string& insert(int pos, const string& str);//�����ַ���
3 string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
4 string& erase(int pos, int n = pos);//ɾ����pos��ʼ��n���ַ�
*/

void test1() {
	string str1 = "hello";
	// ����
	str1.insert(1, "111");
	cout << "str1 = " << str1 << endl;

	// ɾ��
	str1.erase(1, 3);
	cout << "str1 = " << str1 << endl;
}


int main()
{
	test1();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;

/*
���ң�����ָ���ַ����Ƿ����
�滻����ָ��λ���滻�ַ���

������
1 int find(const string& str, int pos = 0) const;//����str��һ�γ���λ�� ��pos��ʼ����
2 int find(const char* s, int pos = 0) const;// ����s��һ�γ���λ�� ��pos��ʼ����
3 int find(const char* s, int pos = 0, int n) const;// ��posλ�ò���s��ǰn���ַ���һ�γ��ֵ�λ��
4 int find(const char c, int pos = 0) const;// ����c��һ�γ���λ��
5 int rfind(const string& str, int pos = npos) const;// ����str������λ�� ��pos��ʼ����
6 int rfind(const char *s, int pos = npos) const;// ����s������λ�� ��pos��ʼ����
7 int rfind(const char *s, int pos , int n) const;// ��posλ�ò���s��ǰn���ַ����һ�γ��ֵ�λ��
8 int rfind(const char c, int pos = 0) const;// �����ַ�c���һ�γ��ֵ�λ��
9 string&  replace(int pos, int n , const string& str);// �滻��pos��ʼn���ַ�Ϊ�ַ���str
10string&  replace(int pos, int n , const char* s);// �滻��pos��ʼn���ַ�Ϊ�ַ���s
*/

// ����
void test1() {
	string str1 = "abcdefghde";
	int pos = str1.find("de");// ���� ����λ�� ������ ����-1
	if (pos == -1) {
		cout << "δ�ҵ����ַ���" << endl;
	}
	else {
		cout << "pos = " << pos << endl;
	}
	
	// rfind���ұ�����ʼ��  find��������ҿ�ʼ�� 
	int rpos = str1.rfind("de");
	cout << "rpos = " << rpos << endl;
}


// �滻
void test2() {
	string str1 = "abcdefg";
	str1.replace(1, 2, "1111");
	// �ӵ�һ������λ�ÿ�ʼ��2���ַ� �滻Ϊ"1111"
	cout << "str1 = " << str1 << endl;
}


int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

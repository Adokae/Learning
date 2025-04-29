# include <iostream>
using namespace std;
#include <string>
#include <vector>
/*
1 ˼·1�����ж��ַ���������Ԫ��ֵ���ڶ������ַ������бȽ�
ʹ��ջ��Ԫ�ؽ��в����������ַ�����Ԫ��ֵ����Ϊ#��ջ��Ϊ�գ�ɾ��ջ��Ԫ�أ�
����Ϊ#���ѵ�ǰԪ�ز���ջ��

2 ��һ��Ԫ���Ƿ���Ҫɾ��������Ԫ�غ����Ƿ�����˸������˿��ǴӺ���ǰ����Ԫ�أ�
��skip��ʾҪɾ��Ԫ�صĸ������Ӻ���ǰ����Ԫ��ʱ���������˸����˵����Ҫɾ��Ԫ�أ�
skip+1����������ͨԪ�أ��ж�skip�Ƿ�Ϊ0��skipΪ0��˵����Ԫ�ز���Ҫɾ��,skip��Ϊ0��˵��
��Ԫ����Ҫɾ��;

*/
string backSpace(string s);

bool backspaceCompare(string s, string t)
{
	s = backSpace(s);
	t = backSpace(t);
	return (s == t);
}

string backSpace(string s)
{
	string ret;
	for (char ch : s) {
		if (ch != '#') {
			ret.push_back(ch);
		}
		else if (!ret.empty()) {
			ret.pop_back();
		}
	}
	return ret;
}

bool backspaceCompare2(string s, string t) {
	int i = s.length() - 1;
	int j = t.length() - 1;// ָ���ַ������һ��Ԫ��
	int skipS = 0;
	int skipT = 0;
	while (i >= 0 || j >= 0) {
		while (i >= 0) {
			if (s[i] == '#') {
				// �ַ�����Ԫ��Ϊ�˸�� Ҫɾ����Ԫ�ظ�����1 Ԫ������ֵ��1
				skipS++, i--;
			}
			else if (skipS > 0) {
				//Ԫ��Ϊ��ͨ���� ��Ҫɾ����Ԫ�ظ�����Ϊ0 ˵����Ԫ����Ҫɾ��
				// ɾ����Ԫ�أ�Ԫ������ֵ��1
				skipS--, i--;
			}
			else {
				// Ԫ��Ϊ��ͨ���� ��Ҫɾ����Ԫ�ظ���Ϊ0 ˵����Ԫ�ز���Ҫɾ��
				// ����ѭ�� ��ǰ����iָ����Ҫɾ����Ԫ��
				break;
			}
		}
		while (j >= 0) {
			if (t[j] == '#') {
				// �ַ�����Ԫ��Ϊ�˸�� Ҫɾ����Ԫ�ظ�����1 Ԫ������ֵ��1
				skipT++, j--;
			}
			else if (skipT > 0) {
				//Ԫ��Ϊ��ͨ���� ��Ҫɾ����Ԫ�ظ�����Ϊ0 ˵����Ԫ����Ҫɾ��
				// ɾ����Ԫ�أ�Ԫ������ֵ��1
				skipT--, j--;
			}
			else {
				// Ԫ��Ϊ��ͨ���� ��Ҫɾ����Ԫ�ظ���Ϊ0 ˵����Ԫ�ز���Ҫɾ��
				// ����ѭ�� ��ǰ����jָ����Ҫɾ����Ԫ��
				break;
			}
		}
		if (i >= 0 && j >= 0) {
			// ij����ָ��Ԫ��ֵ
			if (s[i] != t[j]) {
				// �Ƚ������ַ����е�ǰ����Ҫɾ����Ԫ��ֵ
				return false;
			}
		}
		else {
			if (i >= 0 || j >= 0) {
				// һ���ַ����Ѿ�������� һ���ַ�����δ�������
				// ��������������ַ����϶������
				return false;
			}
		}
		// �������ַ�����δ������� �ҵ�ǰδɾ����Ԫ����� 
		// �򽫵�ǰԪ��ָ�������ֵ��1 ���¿�ʼѰ��
		i--, j--;
	}
	// ���Ϊɾ����Ԫ��ȫ������� ����true
	return true;
}


int main()
{
	string s = "a##c";
	string t = "#a#c";
	bool flag = backspaceCompare(s, t);
	cout << "���յĽ��Ϊ��" << flag << endl;

	system("pause");

	return 0;
}

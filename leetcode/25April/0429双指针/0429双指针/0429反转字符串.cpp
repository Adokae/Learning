#include <iostream>
using namespace std;
#include <vector>
/*
˼·(�Լ���˼·)������ָ�룬һ��ָ��ͷ��һ��ָ��β����������ָ��ָ���Ԫ�أ�
����ָ�������ָ��ʱ������ѭ��


*/

void reverseString(vector<char>& s) {
	int left = 0, right = s.size() - 1;
	char temp;

	while (left <= right) {
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
	
	/*for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;*/
}

int main() {
	vector<char> s = { 'h'};//,'e' ,'l','l','o','a'
	reverseString(s);

	system("pause");

	return 0;
}

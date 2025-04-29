#include <iostream>
using namespace std;
#include <vector>
/*
思路(自己的思路)：两个指针，一个指向头，一个指向尾，交换两个指针指向的元素，
但左指针大于右指针时，跳出循环


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

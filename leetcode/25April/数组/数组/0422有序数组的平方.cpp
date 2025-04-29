# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print(int s)
{
	cout << s << " ";
}

vector<int> sortedSquares(vector<int>& nums)
{
	int n = nums.size();
	vector<int> new_nums;// �����յ�ֵ
	// ���������д���0��С��0Ԫ�ص�����ֵ
	int lesszeroIndex = -1;
	for (int i = 0; i < n; i++) {
		if (nums[i] < 0) {
			lesszeroIndex = i;
		}
	}
	// lesszeronIndex = -1 ˵��������Ԫ��ȫ����0 ��ʱ����Ҫ���� ��ԭ����Ԫ��
	// ƽ���γ������鼴��
	if (lesszeroIndex == -1) {
		for (int j = 0; j < n; j++) {
			new_nums.push_back(nums[j] * nums[j]);
		}
		return new_nums;
	}
	// lesszeronIndex = n-1 ˵��������Ԫ��ȫС��0 ��ʱ������������
	else if (lesszeroIndex == n - 1) {
		for (int j = n - 1; j >= 0; j--) {
			new_nums.push_back(nums[j] * nums[j]);
		}
	}
	// ����������������� ˵��������Ԫ���д���0��С��0��Ԫ�� ��ʱ���й鲢����
	else {
		vector<int>new_num1;// ��С��0��Ԫ�ص�ƽ��ֵ
		vector<int>new_num2;// �����0��Ԫ�ص�ƽ��ֵ
		for (int k1 = lesszeroIndex; k1 >= 0; k1--) {
			new_num1.push_back(nums[k1] * nums[k1]);
		}
		for (int k = lesszeroIndex+1; k < n; k++) {
				new_num2.push_back(nums[k] * nums[k]);
		}
		int left_i = 0, right_i = 0;
		while (left_i < new_num1.size() && right_i < new_num2.size()) {
			if (new_num1[left_i] <= new_num2[right_i]) {
				new_nums.push_back(new_num1[left_i]);
				left_i++;
			}
			else {
				new_nums.push_back(new_num2[right_i]);
				right_i++;
			}
		}
		while (left_i < new_num1.size()) {
			new_nums.push_back(new_num1[left_i]);
			left_i++;
		}
		while (right_i < new_num2.size()) {
			new_nums.push_back(new_num2[right_i]);
			right_i++;
		}
	}
	return new_nums;
}


int main()
{
	vector<int> nums = {-10,-5,-3,-2,0};
	vector<int>new_nums = sortedSquares(nums);
	for_each(new_nums.begin(), new_nums.end(), print);
	cout << endl;
	system("pause");

	return 0;
}

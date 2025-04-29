#include <iostream>
using namespace std;
#include <climits>// ͷ�ļ��еĳ���
#include <vector>
/*
209-������С��������
˼·��1 ���� ������������������������������ ����Ѱ�ҳ�����С��������
1 ˫ָ�� �������� �ȹ̶�������ֹλ�� �ƶ���ʼλ�ô���Ѱ����̾���
�������������Ԫ�غ�С����̾��� �ƶ�������ֹλ��

*/

int minSubArrayLen(int target, vector<int>& nums) {
	// 1 �����ⷨ
	/*int result = INT_MAX;
	int sum;
	int len = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum = 0;
		for (int j = i; j < nums.size(); j++) {
			sum += nums[j];
			if (sum >= target) {
				len = j - i + 1;
				result = result < len ? result : len;
				break;
			}
		}
	}
	return result == -1 ? 0 : result;*/

	// 2 ��������
	int i = 0;// ��ʼλ��
	int sum = 0;
	int len = 0;
	int result = INT_MAX; // ���ս��
	// j��ʾ��ֹλ��
	for (int j = 0; j < nums.size(); j++) {
		sum += nums[j];
		while (sum >= target) {
			len = j - i + 1;
			result = result < len ? result : len;
			sum -= nums[i];
			i++;
		}
	}
	return result == INT_MAX?0:result;
}



int main() {
	vector<int> nums = { 2,3,1,2,4,3 };
	int target = 7;
	/*cout << "����������target:" << endl;
	cin >> target;*/
	int result = minSubArrayLen(target, nums);
	cout << "result = " << result << endl;

	system("pause");
	return 0;
}
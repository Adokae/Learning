# include <iostream>
using namespace std;
#include <vector>

int removeDuplicates(vector<int>& nums)
{
	
	// �����ⷨ �Ƚϵ�ǰԪ������һ��Ԫ��ֵ ����� ���ǵ�ǰԪ��
	// int len = nums.size();
	//for (int i = 0; i < len - 1; i++) {
	//	if (nums[i] == nums[i + 1]) {
	//		for (int j = i; j < len - 1; j++) {
	//			nums[j] = nums[j + 1];
	//		}
	//		len--;
	//		i--;// ���Ǻ���Ҫ���±Ƚϵ�ǰԪ������һ��Ԫ�ص�ֵ
	//	}
	//}
	//return len;

	// ˫ָ�� �ж�Ҫ�ҵ�Ԫ�صĲ�ͬλ�� ���nums[i]=nums[j]��˵��i��j������Ԫ�ض����
	// ����Ҫ�ҵ��ǲ�ͬ��Ԫ�� ͨ���������� ������ͬ��Ԫ��ȥ������ָ������Ӧ��Ԫ��
	int slowIndex = 1;
	for (int fastIndex = 1; fastIndex < nums.size(); fastIndex++) {
		if (nums[slowIndex-1] != nums[fastIndex]) {
			nums[slowIndex] = nums[fastIndex];
			slowIndex++;
		}
	}
	return slowIndex;
}


int main()
{
	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4};
	int elem = removeDuplicates(nums);
	cout << "���յĽ��Ϊ��" << elem << endl;

	system("pause");

	return 0;
}

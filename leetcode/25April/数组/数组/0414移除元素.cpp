# include <iostream>
using namespace std;
#include <vector>

int removeElement(vector<int>& nums, int val)
{
	// �����ⷨ;�������ҵ�����val��ֵ�����ú��������Ը�ֵ���и���
	//int elem = nums.size();
	//for (int i = 0; i < elem; i++)
	//{
	//	if (nums[i] == val)
	//	{
	//		// ע�� ����j=i+1ʱ �˴�Ϊj < elem ���һ�α���ʱ����jΪ7 
	//		// �����Ҫnum[j-1]=nums[j],���ᳬ����������
	//		// ������j=i ��Ҫnums[j]=nums[j+1]��������ѭ��������Ϊj < elem-1
	//		for (int j = i; j < elem - 1; j++)
	//		{
	//			nums[j] = nums[j + 1];
	//		}
	//		i--;// ��Ҫ���¸��Ǻ�λ��Ϊi��ֵ ����Ҫ�ȼ�1
	//		elem--;// ���� �����СҲС��1
	//	}
	//}

	//for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	//return elem;


	// ����ָ����  ��ָ��������������Ѱ������Ҫ���Ԫ�� ��������Ŀ��Ԫ�صĵ�����
	// ��ָ�룺ָ���������е��±��λ��(��������Ҫ�������)
	int slowIndex = 0;
	for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
	{
		if (nums[fastIndex] != val)
		{
			nums[slowIndex] = nums[fastIndex]; // ��ָ��ָ���Ԫ�ز�����Ŀ��Ԫ��ʱ
			slowIndex++;
		}
	}
	return slowIndex;

}


int main()
{
	vector<int> nums = {0,1,2,2,3,0,4,2};
	int val;
	cout << "����Ŀ��ֵ" << endl;
	cin >> val;
	int elem = removeElement(nums, val);
	cout << "���յĽ��Ϊ��" << elem << endl;

	system("pause");

	return 0;
}

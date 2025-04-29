# include <iostream>
using namespace std;
#include <algorithm>
#include <functional>
#include <vector>

/*
��ϵ�º�����ʵ�ֹ�ϵ�Ա�

�º���ԭ�ͣ�
1 template<class T> bool equal_to<T> ����
2 template<class T> bool not_equal_to<T> ������
3 template<class T> bool greater<T> ����
4 template<class T> bool greater_equal<T> ���ڵ���
5 template<class T> bool less<T> С��
6 template<class T> bool less_equal<T> С�ڵ���
*/
class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// ����
	// ��1
	sort(v.begin(), v.end(), myCompare());

	// ��2
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

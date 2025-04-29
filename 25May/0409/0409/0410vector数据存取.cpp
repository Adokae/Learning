# include <iostream>
using namespace std;
#include <vector>
/*
对vector数据进行存取操作

函数：
1 at(int idx); // 返回索引idx所指的数据
2 operator[];返回索引idx所指的数据
3 front();返回容器中的第一个数据元素
4 back();返回容器中最后一个数据元素
*/


void test1() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	// 通过[]方式访问
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	// 通过at方式访问
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;

	// 返回首元素
	cout << "第一个元素为：" << v1.front() << endl;
	// 返回最后一个元素
	cout << "最后一个元素为：" << v1.back() << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}

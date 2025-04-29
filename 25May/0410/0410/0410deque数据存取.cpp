# include <iostream>
using namespace std;
#include <deque>
/*
deque数据存取

函数：
1 at(int idx);返回索引idx所指向的数据
2 operator[];返回idx所指向的数据
3 front();返回容器中的第一个数据元素
4 back();返回容器中最后一个数据元素

*/

void test1() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	// 通过[]方式访问元素
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << " ";
	}
	cout << endl;

	// 通过at方式访问
	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << " ";
	}
	cout << endl;

	// 访问首尾元素
	cout << "首元素为：" << d1.front() << endl;
	cout << "尾元素为:" << d1.back() << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}

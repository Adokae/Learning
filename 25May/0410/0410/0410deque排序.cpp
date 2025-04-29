# include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

/*
deque进行排序：

函数：
1 sort(iterator beg, iterator end); 对beg和end区间内的元素进行排序
*/
void printDeque(deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void test1() {
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(25);
	d.push_back(15);
	printDeque(d);

	// 排序 默认从小到大升序排列
	// 对于支持随机访问的迭代器的容器 都可以使用sort算法直接对其进行排序 如vector
	sort(d.begin(), d.end());
	cout << "排序后:" << endl;
	printDeque(d);
}

int main()
{
	test1();
	system("pause");

	return 0;
}

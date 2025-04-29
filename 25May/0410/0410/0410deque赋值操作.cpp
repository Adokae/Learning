# include <iostream>
using namespace std;
#include <deque>
/*
deque赋值操作：

函数：
1 deque& operator=(const deque &deq); 重载=操作符
2 assign(beg, end);将[beg,end)区间中的数据拷贝赋值给本身
3 assign(n, elem);将n个elem拷贝赋值给本身
*/
void printDeque(deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void test1() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	// =赋值
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	// assign赋值
	deque<int>d3;
	d3.assign(d2.begin(), d2.end());
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}

int main()
{
	test1();
	system("pause");

	return 0;
}

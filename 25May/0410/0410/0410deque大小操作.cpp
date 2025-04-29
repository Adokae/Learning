# include <iostream>
using namespace std;
#include <deque>
/*
deque大小操作

函数：
1 deque.empty();判断容器是否为空
2 deque.size();返回容器中元素个数
3 deque.resize(num);重新指定容器的长度为num 若容器变长，则以填充值填充新位置
若容器变短，则末尾超出容器长度的元素被删除

4 deque.resize(num, len);重新指定容器的长度为num 若容器变长，则以elem填充新位置
若容器变短，则末尾超出容器长度的元素被删除

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
	if (d1.empty()) {
		cout << "d1为空" << endl;
	}
	else {
		cout << "d1不为空" << endl;
		cout << "d1大小为：" << d1.size() << endl; // 没有容量的的概念
	}

	// 重新指定大小
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

int main()
{
	test1();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;
#include <deque>
/*
deque的插入和删除数据

函数原型：
两端插入操作
1 push_back(elem) ; 在容器尾部添加一个数据
2 push_front(elem); 在容器头部插入一个数据
3 pop_back();删除容器最后一个数据
4 pop_front();删除容器第一个数据

指定位置操作：
1 insert(pos, elem);在pos位置插入一个elem元素的拷贝 返回新数据的位置
2 insert(pos, n, elem);在pos位置插入n个elem元素,无返回值
3 inset(pos, beg, end);在pos位置插入[beg, end)区间的元素,无返回值
4 clear();清空容器的所有数据
5 erase(beg,end); 删除[beg,end)区间的数据，返回下一个数据的位置
6 erase(pos);删除pos位置的数据，返回下一个数据的位置
*/

void printDeque(deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// 两端操作
void test1() {
	deque<int>d1;
	// 尾插
	d1.push_back(10);
	d1.push_back(20);

	// 头部插入
	d1.push_front(5);
	d1.push_front(1);

	printDeque(d1);

	// 尾删
	d1.pop_back();
	printDeque(d1);

	// 头删
	d1.pop_front();
	printDeque(d1);
}


void test2() {
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);
	d2.push_back(40);
	printDeque(d2);

	// insert插入
	d2.insert(d2.begin(), 1000);
	printDeque(d2);

	d2.insert(d2.begin(), 2, 100);
	printDeque(d2);

	// 按区间进行插入
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d3.push_back(5);

	d2.insert(d2.begin(), d3.begin(), d3.end());
	printDeque(d2);
}


void test3() {
	deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);
	d3.push_back(4);
	d3.push_back(5);

	// 删除
	//d3.erase(d3.begin());// 删除首元素
	deque<int>::iterator it = d3.begin();
	it++;
	d3.erase(it);
	printDeque(d3);

	// 按区间进行删除
	d3.erase(d3.begin(), d3.end());
	//d3.clear();
	printDeque(d3);
}

int main()
{
	//test1();
	//test2();
	test3();
	system("pause");

	return 0;
}

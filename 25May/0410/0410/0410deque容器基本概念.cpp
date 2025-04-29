# include <iostream>
using namespace std;
#include <deque>
/*
deque容器：
双端数组，可以对头端进行插入、删除操作

deque与vector区别：
1 vector对于头部插入删除效率低 数据量越大 效率越低
2 deque相对而言 对头部的插入删除速度比vector快
3 vector访问元素时的速度会比deque快 这和两者内部实现有关

deque内部工作原理：
	deque内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
	中控器中维护的是每个缓冲区的地址，使使用deque时像一片连续的内存空间

deque容器的迭代器支持随机访问的

deque构造函数：deque容器构造
函数：
1 deque<T>deqT; 默认构造形式
2 deque(beg, end);构造函数将[beg,end)区间中的元素拷贝给本身
3 deque(n,elem);拷贝函数将n个elem拷贝给本身
4 deque(const deque &deq); 拷贝构造函数
*/

// 加const防止对容器中的值进行修改
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		//*it = 100;
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

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	//deque<int>d4(d3);
	deque<int>d4 = d3;
	printDeque(d4);
}
int main()
{
	test1();
	system("pause");

	return 0;
}

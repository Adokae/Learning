# include <iostream>
using namespace std;
#include <vector>
/*
vector互换容器

函数：
1 swap(vec); 将vec与本身的元素互换
*/
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// 基本使用
void test1() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	cout << "交换前：" << endl;
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	printVector(v2);

	cout << "交换后：" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}


// 实际用途-巧用swap可以收缩内存空间
void test2() {
	vector<int>v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;// 容量没变化 大小变小了

	// 使用swap
	// vector<int>(v)表示创建一个匿名对象，按v的大小来初始匿名对象的大小
	// swap(v)表示容器交换 将v指向匿名对象 匿名对象执行完后的内存被系统回收
	vector<int>(v).swap(v);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;// 容量和大小都变为3
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

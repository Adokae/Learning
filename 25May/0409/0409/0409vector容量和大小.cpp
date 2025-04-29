# include <iostream>
using namespace std;
#include <vector>
/*
vector容量和大小

函数：
1 empty(); 判断容器是否为空
2 capacity(); 容器的容量
3 size(); 返回容器中元素个数
4 resize(int num); 重新制定容器的长度为num 若容器变长 则以默认值填充新位置
若容器变短 则末尾超出容器长度的元素被删除
5 resize(int num, elem);重新制定容器的长度为num 若容器变长 则以elem值填充新位置
若容器变短 则末尾超出容器长度的元素被删除
*/

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);
	// 为空
	if (v1.empty()) {
		cout << "v1为空" << endl;
	}
	else {
		cout << "v1不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为:" << v1.size() << endl;
	}

	// 重新指定大小
	v1.resize(15, 100);// 利用重载版本，指定默认填充值，
	printVector(v1);// 重新指定的大小比原来大 默认用0填充

	v1.resize(5);
	printVector(v1);// 重新指定的大小比原来小 超过部分删除
}

int main()
{
	test1();
	system("pause");

	return 0;
}

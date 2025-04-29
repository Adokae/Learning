# include <iostream>
using namespace std;
#include <vector>
/*
vector插入和删除

函数：
1 push_back(ele); 尾部插入元素ele
2 pop_back();删除最后一个元素
3 insert(const_iterator, pos, ele);迭代器指向位置pos插入元素ele
4 insert(const_iterator pos, int count , ele);迭代器指向位置pos插入count个元素ele
5 erase(const_iterator pos);删除迭代器指向的元素
6 erase(const_iterator start, const_iterator end);删除迭代器从start到end之间的元素
7 clear()；清空容器中的所有元素
*/
void printVector(vector<int> & v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	vector<int>v1;
	// 尾插法插值
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	// 尾部删除
	v1.pop_back();
	printVector(v1);

	// 插入 第一个参数是迭代器
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 100);
	printVector(v1);

	// 删除
	v1.erase(v1.begin());
	printVector(v1);

	//v1.erase(v1.begin(), v1.end());// 从起始到结束全部清空
	v1.clear();
	printVector(v1);
}
int main()
{
	test1();
	system("pause");

	return 0;
}

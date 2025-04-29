# include <iostream>
using namespace std;
#include<vector>
/*
vector容器基本概念：
功能：vector容器和数组非常相似，也称为单端数组
与普通数组的区别：
	数组是静态空间，vectro可以动态扩展

动态扩展：不是在原空间之后接续新空间，而是寻找更大的内存空间，将原数据拷贝到新空间，释放原空间

vector容器的迭代器是支持随机访问的迭代器

vector构造函数：
创建vector容器
函数：
1 vector<T> v; // 采用模板实现类实现 默认构造函数
2 vector<v.begin(), v.end()> ;// 将v[begin(), end())(前闭后开)区间中的元素拷贝给本身
3 vector(n, elem); // 构造函数将n个elem拷贝给本身
4 vector(const vector &vec)； // 拷贝构造函数

*/
void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " " ;
	}
	cout << endl;
}

void test1() {
	// 默认构造 无参构造
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	// 通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	// n个elem的方式进行构造
	vector<int>v3(10, 100);
	printVector(v3);

	// 拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}

int main()
{
	test1();
	system("pause");

	return 0;
}

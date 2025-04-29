# include <iostream>
using namespace std;
#include <set>

/*
对set容器进行查找和统计数据

函数：
1 find(key); 查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end()
2 count(key); 统计key的元素个数


*/

void test1()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	// 查找
	set<int>::iterator pos = s1.find(300);
	if (pos != s1.end())
	{
		cout << "找到元素:" << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

}
// 统计
void test2()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	// 统计30的个数
	// 对于set而言 统计结果要么是1 要么为0
	int num = s1.count(30);
	cout << "30的个数为：" << num << endl;
}



int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

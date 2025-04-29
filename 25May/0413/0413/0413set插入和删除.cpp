# include <iostream>
using namespace std;
#include <set>
/*
set插入和删除：

函数：
1 inset(elem); 在容器中插入元素
2 clear(); 清楚所有元素
3 erase(pos) 删除pos迭代器所指的元素，返回下一个元素的迭代器
4 erase(beg,end) 删除区间[beg,end)的所有元素 返回下一个元素的迭代器
5 erase(elem) 删除容器中值为elem的元素

*/
void printSet(const set<int>& S)
{
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



void test1()
{
	set<int> s1;

	// 插入
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);

	// 删除
	s1.erase(s1.begin());
	printSet(s1);

	//删除重载版本
	s1.erase(20);
	printSet(s1);

	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);

}

int main()
{
	test1();
	system("pause");

	return 0;
}

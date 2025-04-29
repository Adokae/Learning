# include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
常用查找算法简介：
1 find 查找元素
2 find_if 按条件查找元素
3 adjacent_find 查找相邻重复元素
4 bingary_search 二分查找法
5 count 统计元素个数
6 count_if 按条件统计元素个数

find：查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器
函数：find(iterator beg, iterator end, value);
beg: 开始迭代器
end 结束迭代器
value 查找的元素

*/


// 查找内置数据类型
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// 查找
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}

}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	// 重载== 让底层find知道如何对比
	bool operator==(const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};
// 查找自定义数据类型
void test2()
{
	vector<Person> v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	// 放到容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("b", 20);

	vector<Person>::iterator it = find(v.begin(), v.end(), pp);

	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到 name = "<< it->m_Name << " age = " << it->m_Age << endl;
	}
}


int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

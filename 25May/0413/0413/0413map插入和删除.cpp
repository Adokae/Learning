# include <iostream>
using namespace std;
#include <map>
/*
map插入和删除

函数：
1 insert(elem); 在容器中插入元素
2 clear()清楚所有元素
3 erase(pos) 删除pos迭代器所指的元素 返回下一个元素的迭代器
4 erase(beg,end) 删除区间[beg,end)的所有元素 返回下一个元素的迭代器
5 erase(key) 删除容器中值为key的元素


*/
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key值" << (*it).first << " value值" << (*it).second << endl;
	}
	cout << endl;
}



void test1()
{
	map<int, int>m1;
	// 插入
	m1.insert(pair<int, int>(1, 10));

	m1.insert(make_pair(2, 20));

	m1.insert(map<int, int>::value_type(3, 20));

	// 建议使用[]通过key访问value
	m1[4] = 40;
	// 不建议使用该种方式进行插值 若不存在该键值对 它会创建该键值对 默认值为0

	//cout << m1[5] << endl;
	cout << m1[4] << endl;
	printMap(m1);

	// 删除
	m1.erase(m1.begin());
	printMap(m1);

	m1.erase(3);//按key删除
	printMap(m1);

	//m1.erase(m1.begin(), m1.end());
	m1.clear();
	printMap(m1);


}
int main()
{
	test1();
	system("pause");

	return 0;
}

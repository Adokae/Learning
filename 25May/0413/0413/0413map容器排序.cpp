# include <iostream>
using namespace std;
#include <map>

/*
map容器默认排序规则：按key值 从小到大排序
利用仿函数 改变排序规则 改成从大到小排列

*/

class myCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		// 降序
		return v1 > v2;
	}
};

void test1()
{
	map<int, int, myCompare> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	for (map<int, int, myCompare>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key值：" << (*it).first << " value值：" << (*it).second << endl;
	}

}

int main()
{
	test1();
	system("pause");

	return 0;
}

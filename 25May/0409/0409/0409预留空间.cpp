# include <iostream>
using namespace std;
#include <vector>
/*
vector预留空间：
减少vector在动态扩展容量时的扩展次数

函数：
1 reserve(int len); 容器预留len个元素长度 预留位置不初始化 元素不可访问
*/

void test1() {
	vector<int>v;
	//利用reserve预留空间
	v.reserve(100000);

	int num = 0; // 统计开辟次数
	int* p= NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;// 可能会不断分配新的内存空间
		}
	}

	cout << "num = " << num << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

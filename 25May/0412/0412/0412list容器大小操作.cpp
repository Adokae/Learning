# include <iostream>
using namespace std;
#include <list>
/*
list大小操作

函数：
1 size() 返回容器中元素个数
2 empty() 判断容器是否为空
3 resize(num) 重新指定容器长度为num 若容器变长 则以默认值填充新位置
若容器变短，则末尾超出容器长度的元素被删除
4 resize(num, elem)重新指定容器长度为num 若容器变长 则以elem填充新位置
若容器变短，则末尾超出容器长度的元素被删除

*/
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test1()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else {
		cout << "L1不为空" << endl;
		cout << "L1的元素个数：" << L1.size() << endl;
	}

	// 重新指定大小
	L1.resize(10,1000);
	printList(L1);
	L1.resize(2);
	printList(L1);
}

int main()
{
	test1();
	system("pause");

	return 0;
}

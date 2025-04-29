# include <iostream>
using namespace std;
#include <queue>
/*
queue容器：
一种先进先出的数据结构，有两个出口
队列容器允许从一端新增元素 从另一端移除元素
只有队头和队尾才能被外界使用 不允许有遍历行为

入队：push()
出队：pop()

常用接口：
构造函数：
1 queue<T> que; queue采用模板类实现 queue对象的默认构造形式
2  queue(const queue &que); 拷贝构造函数

赋值操作：
1 queue& operator=(const queue &que); 重载=操作符

数据存取：
1 push(elem);往队尾添加元素
2 pop();从队头移除第一个元素
3 back();返回最后一个元素
4 front();返回第一个元素

大小操作：
1 empty();判断堆栈是否为空
2 size();返回栈的大小

*/

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test1() {
	queue<Person>q;
	Person p1("a", 10);
	Person p2("b", 10);
	Person p3("c", 10);
	Person p4("d", 10);
	// 入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "移除元素之前队列大小为：" << q.size() << endl;

	while (!q.empty())
	{
		cout << "队头元素为：姓名为：" << q.front().m_Name << "年龄为：" << q.front().m_Age << endl;

		cout << "队尾元素为：姓名为：" << q.back().m_Name << "年龄为：" << q.back().m_Age << endl;

		q.pop();
	}

	cout << "移除元素之后队列大小为：" << q.size() << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

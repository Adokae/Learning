# include <iostream>
using namespace std;
#include <stack>
/*
stack容器：
stack容器是一种先进后出的数据结构，只有一个出口
不允许遍历行为

栈可以判断容器是否为空
栈可以判断元素个数

栈中进入数据称为入栈-push
栈中弹出数据称为出栈-pop

栈中常用接口：
构造函数：
1 stack<T> stk;stack采用模板类实现 stack对象的默认构造形式
2 stack(const stack &stk); 拷贝构造函数

赋值操作
1 stack& operator=(const stack &stk)； 重载等号操作符

数据存取：
1 push(elem)；向栈顶添加元素
2 pop();从栈顶移除第一个元素
3 top();返回栈顶元素

大小操作：
1 empty();判断栈顶是否为空
2 size()；返回栈的大小
*/

void test1() {
	stack<int> s;
	// 入栈操作
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	// 只要栈不为空 查看栈顶 并且执行出栈操作
	while (!s.empty()) {
		// 查看栈顶元素
		cout << "栈顶元素：" << s.top() << endl;

		// 出栈操作
		s.pop();
	}
	cout << "栈的大小：" << s.size() << endl;
}

int main()
{
	test1();
	system("pause");

	return 0;
}

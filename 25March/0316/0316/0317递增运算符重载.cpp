# include <iostream>
using namespace std;

/*
通过重载递增运算符，实现自己的整型数据
*/

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	// 重载++运算符
	// 重载前置++运算符
	// 前置递增返回引用是为了一直对一个数据进行操作
	// 返回值就不是一直在对一个数据进行操作
	MyInteger& operator++()
	{
		// 先进行++操作
		// 再对自身进行返回
		m_Num++;
		return *this;
	}
	// 重载后置++运算符
	// 此处的int表示占位参数，可以用来区分前置和后置递增
	// 后置递增返回的是一个值 若返回引用 
	// 在函数结束后该引用已经被释放
	MyInteger operator++(int)
	{
		//先记录当时结果
		MyInteger temp = *this;
		// 后递增
		m_Num++;
		// 最后将记录结果返回
		return temp;
	}

private:
	int m_Num;
};

// 重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}
void test1()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test2()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	test1();
	test2();
	system("pause");

	return 0;
}

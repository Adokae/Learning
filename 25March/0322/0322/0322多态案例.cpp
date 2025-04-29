# include <iostream>
using namespace std;
# include <string>
/*
分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
实际开发中，遵循开闭原则：
对扩展进行开发，对修改进行关闭

多态优点：
1 组织结构清晰
2 可读性强
3 可维护性强
*/
// 普通写法
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if(oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		else if (oper == "/")
		{
			return m_Num1 / m_Num2;
		}
	}

	int m_Num1;
	int m_Num2;
};

void test1()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 5;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;

}

// 利用多态实现计算器
// 首先实现计算器的基类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

// 加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
// 减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
// 乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test2()
{
	// 此处通过父类指针指向子类对象实现多态
	// 加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 5;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	// 减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 5;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	// 乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 5;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
}

int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;
# include <string>
/*
�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������
ʵ�ʿ����У���ѭ����ԭ��
����չ���п��������޸Ľ��йر�

��̬�ŵ㣺
1 ��֯�ṹ����
2 �ɶ���ǿ
3 ��ά����ǿ
*/
// ��ͨд��
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

// ���ö�̬ʵ�ּ�����
// ����ʵ�ּ������Ļ���
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

// �ӷ���������
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
// ������������
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
// �˷���������
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
	// �˴�ͨ������ָ��ָ���������ʵ�ֶ�̬
	// �ӷ�����
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 5;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	// ��������
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 5;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	// �˷�����
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

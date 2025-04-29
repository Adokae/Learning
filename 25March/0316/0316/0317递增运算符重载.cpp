# include <iostream>
using namespace std;

/*
ͨ�����ص����������ʵ���Լ�����������
*/

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	// ����++�����
	// ����ǰ��++�����
	// ǰ�õ�������������Ϊ��һֱ��һ�����ݽ��в���
	// ����ֵ�Ͳ���һֱ�ڶ�һ�����ݽ��в���
	MyInteger& operator++()
	{
		// �Ƚ���++����
		// �ٶ�������з���
		m_Num++;
		return *this;
	}
	// ���غ���++�����
	// �˴���int��ʾռλ������������������ǰ�úͺ��õ���
	// ���õ������ص���һ��ֵ ���������� 
	// �ں���������������Ѿ����ͷ�
	MyInteger operator++(int)
	{
		//�ȼ�¼��ʱ���
		MyInteger temp = *this;
		// �����
		m_Num++;
		// ��󽫼�¼�������
		return temp;
	}

private:
	int m_Num;
};

// �������������
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

# include <iostream>
using namespace std;
/*
��ָ����ʳ�Ա����
*/
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}
		// ʵ����this->age
		cout << "age = " << m_Age << endl;
	}
	int m_Age;
};

void test1()
{
	Person* p = NULL;
	//p->showClassName(); // ��ָ����Է���

	// ������α���
	// p����Ϊ�գ��޷��������е����� ʹ�õ�thisָ�� 
	// ����Ҫ����Ӵ��뱣֤����Ľ�׳��
	p->showPersonAge();
}
int main()
{
	test1();
	system("pause");

	return 0;
}

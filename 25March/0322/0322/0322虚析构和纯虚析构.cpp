# include <iostream>
using namespace std;
#include <string>
/*
�������ʹ���������ʹ�ã���̬ʹ��ʱ����������������Կ��ٵ�������
��ô����ָ�����ͷ�ʱ�޷����õ������е��������룬����Ҫʹ���������ʹ�������

�����ʽ���������е�����������Ϊ��������������

�������ʹ����������ԣ�
1 �ɽ������ָ���ͷ��������
2 ����Ҫ�о���ĺ�������

�������ʹ�����������
����Ǵ����������������ڳ����࣬�޷�ʵ��������

�������﷨�� vitrual ~����(){}
���������﷨��virtual ~����() = 0;

������û�ж������� ���Բ�д��������������
*/

class Animal
{
public:
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}
	virtual void speak() = 0;
	// �������������ָ���ͷ�������󲻸ɾ�������
	/*virtual ~Animal()
	{
		cout << "Animal������������" << endl;
	}*/

	// �������� ����ֻ������һ�д��� ���� ��Ϊ��Ҫ����ʵ��
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal����������������" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat���캯������" << endl;
		m_Name = new string(name);
	}

	virtual void speak()
	{
		cout << *m_Name << "è��" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat������������" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string *m_Name;
};

void test1()
{
	Animal* animal = new Cat("Tom"); // ʹ�û���ָ�봴�����������
	// ���ö�̬�󶨣�����������ʱ���������Ǹ���ķ���
	animal->speak();
	// ����ָ��������ʱ ���������������������
	// ������������ж������� ����ڴ�й¶
	delete animal;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

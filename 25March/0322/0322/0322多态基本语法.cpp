# include <iostream>
using namespace std;

/*
��̬���ࣺ
1 ��̬��̬���������غ�������������ھ�̬��̬ ���ú�����
2 ��̬��̬����������麯��ʵ������ʱ��̬

��������
��̬��̬�ĺ�����ַ���-����׶�ȷ��������ַ
��̬��̬�ĺ�����ַ���-���н׶�ȷ��������ַ

��̬��̬����������
1 �м̳й�ϵ
2 ����Ҫ��д�����е��麯��
����д ��������ֵ���� ������ �����б� ��ȫ��ͬ��

��̬��̬ʹ�ã�
�����ָ��������� ָ���������

vfptr-�麯��(��)ָ��
vftable-�麯����,���ڲ���¼�麯����ַ

��������д�����е��麯���������е��麯�����ڲ����滻��������麯����ַ
���� �����еĵ�ַΪ &Animal::speak,�����еĵ�ַΪ&Cat::speak
����ʱ��Animal & animal = cat��
*/

class Animal
{
public:
	// ��virtual�ؼ��� ʹ������Ϊ�麯�� �������ڱ����ʱ����ȷ����������
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void speak()
	{
		cout << "Сè�ڽ�" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "���ڽ�" << endl;
	}
};
// ִ��˵���ĺ���
// ��ַ��� �ڱ���׶�ȷ��������ַ ����Animal���з���
// ������è˵�� �ú�����ַ������ǰ�� ��Ҫ�����н׶ν��а�
// ��ַ���
void doSpeak(Animal& animal)
{
	animal.speak();
}

void test1()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}

void test2()
{
	// ʵ������СΪ1���ֽ� ��virtual���麯�����Ϊ4���ֽ�
	cout << "sizeof of Animal is " << sizeof(Animal) << endl;
}
int main()
{
	test1();
	//test2();
	system("pause");

	return 0;
}

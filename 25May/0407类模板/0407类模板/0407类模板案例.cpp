# include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>
/*
��ģ�尸����
ʵ��һ��ͨ�������࣬ʵ������Ҫ��
1 ���Զ��������������Լ��Զ����������͵����ݽ��д洢
2 �������е����ݴ洢������
3 ���캯���п��Դ������������
4 �ṩ��Ӧ�Ŀ������캯���Լ�operator-��ֹǳ��������
5 �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
6 ����ͨ���±�ķ�ʽ���������е�Ԫ��
7 ���Ի�ȡ�����е�ǰԪ�صĸ��������������
*/

void printIntArray(MyArray<int> & arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test1()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr1);
	cout << "arr1������Ϊ:" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ:" << arr1.getSize() << endl;

	MyArray<int> arr2(arr1);
	arr2.Pop_Back();
	cout << "arr2��βɾ��Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr2);
	
	/*MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;*/
}
// �����Զ�����������
class Person
{
public:
	Person()
	{

	};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "name = " << arr[i].m_Name << endl;
		cout << "age = " << arr[i].m_Age << endl;
	}
}
void test2()
{
	MyArray<Person> arr(10);
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonArray(arr);

	cout << "��������Ϊ" << arr.getCapacity() << endl;
	cout << "�����СΪ" << arr.getSize() << endl;
}
int main()
{
	//test1();
	test2();
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;
/*
���캯���ķ��༰���ã�
���ַ��෽ʽ��
�������֣��вι������޲ι���
�����ͷ֣���ͨ����Ϳ�������

���ֵ��÷�ʽ��
���ŷ�
��ʾ��
��ʽת����
*/
class Person
{
public:
	// �вι�����޲ι���
	// ��ͨ����
	Person()
	{
		cout << "�����޲ι��캯��" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "�����вι��캯��" << endl;
	}
	// �������캯��
	Person(const Person &p)
	{
		// ������������������ԣ���������һ��������
		cout << "���ÿ������캯��" << endl;
		age = p.age;
	}

	~Person()
	{
		cout << "������������" << endl;
	}
	int age;
};

// ����
void test1()
{
	// ���ŷ�
	//Person p1;// Ĭ�Ϲ��캯������
	//Person p2(10); // �вι��캯������
	//Person p3(p2); // �������캯������
	// ע������
	// ����Ĭ�Ϲ��캯����ʱ��,��Ҫ��С����()
	// �������д��룬����������Ϊ��һ��������������������Ϊ�ڴ�������
	//Person p1();
	/*cout << "the age of p2 is " << p2.age << endl;
	cout << "the age of p3 is " << p3.age << endl;*/


	// ��ʾ��
	//Person p1;// Ĭ�Ϲ��캯������
	//Person p2 = Person(10); // �вι��캯������
	//Person p3 = Person(p2); // �������캯������
	// ����һ�д���Ϊ�������� 
	// �ص��ǣ���ǰ��ִ�н�����ϵͳ���������յ���������
	// Person(10)
	// ע������2 ��Ҫ���ÿ������캯�� ��ʼ����������
	// ����������Ϊ Person(p3) === Person p3;
	// Person(p3);
	
	// ��ʽת����
	Person p4 = 10; // �൱��Person p4 = Person(10);
	Person p5 = p4; // ��������

}

int main()
{
	test1();
	system("pause");

	return 0;
}

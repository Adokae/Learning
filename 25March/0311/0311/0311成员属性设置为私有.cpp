# include <iostream>
using namespace std;
#include <string>
/*
��Ա��������Ϊ˽�У�
�ŵ�
1�������г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
2 ����дȨ�ޣ����Լ�����ݵ���Ч��
*/

class Person
{
public:
	void setName(string name)
	{
		Name = name;
	}
	string getName()
	{
		return Name;
	}
	int getAge()
	{
		return Age;
	}
	void setIdol(string idol)
	{
		Idol = idol;
	}
	void setAge(int age)
	{
		if (age < 0 || age >150)
		{
			cout << "���丳ֵʧ��" << endl;
			return;
		}
		Age = age;
	}
private:
	string Name; // �ɶ���д
	int Age = 18; // ֻ�� ��������������0��150֮��
	string Idol; //ֻд
};
int main()
{
	Person p;
	p.setName("Jack");
	cout << p.getName() << endl;
	//p.Name = "Jack";
	// ��ȡ����
	// ֻ��
	cout << p.getAge() << endl;

	// ֻд
	p.setIdol("lisi");

	p.setAge(160);
	cout << p.getAge() << endl;
	system("pause");

	return 0;
}

# include <iostream>
using namespace std;
# include <string>
/*
�ṹ��ָ�룺
ͨ��ָ����ʽṹ���еĳ�Ա

���ò�����->����ͨ���ṹ��ָ����ʽṹ������
*/

struct Student
{

	string name;
	int age;
	int score;
};
int main()
{
	Student stu = { "����", 18, 100 };
	struct Student* p = &stu;
	// ͨ��ָ����ʽṹ�������ݱ���
	// ͨ���ṹ��ָ�� ���ʽṹ�������� ��Ҫ����"->"

	cout << "������ " << p->name << endl;

	system("pause");

	return 0;
}

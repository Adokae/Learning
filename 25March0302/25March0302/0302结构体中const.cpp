# include <iostream>
using namespace std;
#include <string>

// �ṹ����constʹ�ó���

struct Student
{
	string name;
	int age;
	int score;
};


// ��������Ϊָ�봫�ݣ������βα�Ϊָ�룬�ɽ�Լ�ڴ�ռ�
// �Ҳ��Ḵ���µĸ���
void printStruct(const struct Student * s)
{
	// ��������const��һ�����޸Ĳ����ͻᱨ����ֹ�����
	cout << s->name << endl;
	cout << s->age << endl;
	cout << s->score << endl;

}

int main()
{
	Student s = { "����" , 17, 78};
	// ����ѧ���кܶ࣬����������Ĵ�����ҲԽ��
	printStruct(&s);

	system("pause");

	return 0;
}

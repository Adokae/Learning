# include <iostream>
using namespace std;

/*
�ṹ�����飺
���Զ���Ľṹ����뵽�����з���ά��
�﷨�� struct �ṹ���� ������[Ԫ�ظ���] = {{}, {},...}��
*/

// �ṹ�嶨��
struct Student
{
	string name;
	int age;
	int score;
};

int main()
{
	// �����ṹ������
	struct Student stuArray[3] =
	{
		{"����",18,100},
		{"����",28,99},
		{"����",38,66}
	};
	// ���ṹ��������Ԫ�ظ�ֵ
	stuArray[2].name = "����";

	//�����ṹ������
	for (int i = 0; i < 3; i++)
	{
		cout << "������"<< stuArray[i].name
			<<" ���䣺"<< stuArray[i].age
			<< " ������"<< stuArray[i].score <<endl;
	}
	system("pause");

	return 0;
}

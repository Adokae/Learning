# include <iostream>
using namespace std;

/*
�ṹ�尸��2
���һ��Ӣ�۵Ľṹ�壬���������� ���� �Ա𣬴����ṹ�����飬
�����ṹ�����飬�����д��5��Ӣ��

���ͨ��ð�����򷽷����������е�Ӣ�۰����������������
��ӡ������ս��
*/

struct hero
{
	string name;
	int age;
	string sex;
};

void bubblesort(struct hero heros[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (heros[j].age > heros[j + 1].age)
			{
				struct hero temp;
				temp = heros[j];
				heros[j] = heros[j + 1];
				heros[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int len = 5;
	struct hero heros[5] =
	{
		{"����", 23, "��"},
		{"����", 22, "��"},
		{"�ŷ�", 20, "��"},
		{"����", 21, "��"},
		{"����", 19, "Ů"},
	};
	bubblesort(heros, len);
	for (int k = 0; k < 5; k++)
	{
		cout << "������" << heros[k].name <<
			" ���䣺" << heros[k].age << " �Ա�:"
			<< heros[k].sex
			<< endl;
	}

	system("pause");

	return 0;
}

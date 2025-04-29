# include <iostream>
using namespace std;

/*
结构体案例2
设计一个英雄的结构体，包括其姓名 年龄 性别，创建结构体数组，
创建结构体数组，数组中存放5名英雄

最后通过冒泡排序方法，将数组中的英雄按年龄进行升序排列
打印输出最终结果
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
		{"刘备", 23, "男"},
		{"关羽", 22, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"},
	};
	bubblesort(heros, len);
	for (int k = 0; k < 5; k++)
	{
		cout << "姓名：" << heros[k].name <<
			" 年龄：" << heros[k].age << " 性别:"
			<< heros[k].sex
			<< endl;
	}

	system("pause");

	return 0;
}

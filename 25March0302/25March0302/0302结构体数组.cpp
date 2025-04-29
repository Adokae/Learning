# include <iostream>
using namespace std;

/*
结构体数组：
将自定义的结构体放入到数组中方便维护
语法： struct 结构体名 数组名[元素个数] = {{}, {},...}；
*/

// 结构体定义
struct Student
{
	string name;
	int age;
	int score;
};

int main()
{
	// 创建结构体数组
	struct Student stuArray[3] =
	{
		{"张三",18,100},
		{"李四",28,99},
		{"王五",38,66}
	};
	// 给结构体数组中元素赋值
	stuArray[2].name = "赵六";

	//遍历结构体数组
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名："<< stuArray[i].name
			<<" 年龄："<< stuArray[i].age
			<< " 分数："<< stuArray[i].score <<endl;
	}
	system("pause");

	return 0;
}

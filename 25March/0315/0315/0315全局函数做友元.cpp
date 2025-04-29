# include <iostream>
using namespace std;
# include <string>
/*
程序中，有些私有属性也想让类外特殊的函数或类进行访问
友元目的：让另一个函数或类访问另一个类中的私有成员
友元关键字：friend
友元三种实现：
1 全局函数做友元
2 类做友元
3 成员函数做友元
*/
class Building
{
	// 该全局函数是类的好朋友 可以访问类中的私有成员
	friend void goodGay(Building* building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

// 全局函数
void goodGay(Building *building)
{
	cout << "全局函数访问： " << building->m_SittingRoom << endl;
	cout << "全局函数访问： " << building->m_BedRoom << endl;
}

void test1()
{
	Building building;
	goodGay(&building);
}
int main()
{
	test1();
	system("pause");

	return 0;
}

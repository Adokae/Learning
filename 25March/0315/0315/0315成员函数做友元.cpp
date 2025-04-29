# include <iostream>
using namespace std;

class Building;

class GoodGay
{
public:
	GoodGay();
	void visit(); // 使其可以访问成员中的私有成员
	void visit2();// 使其不可以访问成员中的私有成员

	Building* building;
};

class Building
{
	friend void GoodGay::visit();
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit访问： " << building->m_SittingRoom << endl;
	cout << "visit访问： " << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2访问： " << building->m_SittingRoom << endl;
}

void test1()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}
int main()
{
	test1();
	system("pause");

	return 0;
}

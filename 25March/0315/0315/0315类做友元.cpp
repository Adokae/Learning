# include <iostream>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();
	// visit函数访问Building中的属性
	void visit();
	Building* building;
};

class Building
{
	// 好朋友，可以访问成员中的变量
	friend class GoodGay;
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

// 类外写成员函数
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
	cout << "GoodGay类正在访问" << building->m_SittingRoom << endl;
	cout << "GoodGay类正在访问" << building->m_BedRoom << endl;
}

void test1()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test1();
	system("pause");

	return 0;
}

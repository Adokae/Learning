# include <iostream>
using namespace std;

class Building;

class GoodGay
{
public:
	GoodGay();
	void visit(); // ʹ����Է��ʳ�Ա�е�˽�г�Ա
	void visit2();// ʹ�䲻���Է��ʳ�Ա�е�˽�г�Ա

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
	m_SittingRoom = "����";
	m_BedRoom = "����";
}
GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit���ʣ� " << building->m_SittingRoom << endl;
	cout << "visit���ʣ� " << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2���ʣ� " << building->m_SittingRoom << endl;
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

# include <iostream>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();
	// visit��������Building�е�����
	void visit();
	Building* building;
};

class Building
{
	// �����ѣ����Է��ʳ�Ա�еı���
	friend class GoodGay;
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

// ����д��Ա����
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
	cout << "GoodGay�����ڷ���" << building->m_SittingRoom << endl;
	cout << "GoodGay�����ڷ���" << building->m_BedRoom << endl;
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

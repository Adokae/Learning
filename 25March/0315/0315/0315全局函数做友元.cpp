# include <iostream>
using namespace std;
# include <string>
/*
�����У���Щ˽������Ҳ������������ĺ���������з���
��ԪĿ�ģ�����һ���������������һ�����е�˽�г�Ա
��Ԫ�ؼ��֣�friend
��Ԫ����ʵ�֣�
1 ȫ�ֺ�������Ԫ
2 ������Ԫ
3 ��Ա��������Ԫ
*/
class Building
{
	// ��ȫ�ֺ�������ĺ����� ���Է������е�˽�г�Ա
	friend void goodGay(Building* building);
public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

// ȫ�ֺ���
void goodGay(Building *building)
{
	cout << "ȫ�ֺ������ʣ� " << building->m_SittingRoom << endl;
	cout << "ȫ�ֺ������ʣ� " << building->m_BedRoom << endl;
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

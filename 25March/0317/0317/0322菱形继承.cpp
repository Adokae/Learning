# include <iostream>
using namespace std;

/*
���μ̳и��
����������̳�ͬһ�����࣬����ĳ����ͬʱ�̳�����������
*/

class Animal
{
public:
	int m_Age;
};

// ��̳� 
/*
�̳�֮ǰ ���Ϲؼ��� virtual�����̳�
Animal���Ϊ�����

����̳к� SheepTuo�̳е���Animal�е�m_Age 
vbptr:�����ָ�� ����̳к� SheepTuo�̳е�������ָ�� 
����ָ��ͨ��ƫ������ָ��ΪΨһ������
*/
class Sheep:virtual public Animal {};

class Tuo:virtual public Animal {};

class SheepTuo:public Sheep,public Tuo{};

void test1()
{
	SheepTuo st;
	// ���μ̳� �������������ͬ���� ��Ҫ������������
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	// ��̳�֮�����䶼���28
	// �������� ��Դ�˷� ��̳н��
	cout << "Sheep�е�Age " << st.Sheep::m_Age << endl;
	cout << "Tuo�е�Age " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

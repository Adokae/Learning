# include <iostream>
using namespace std;
/*
��̬����2�����ö�̬����ʵ��������Ʒ���ṩ����������Ʒ����
�ṩ�����������ȺͲ�Ҷ
*/

class AbstractDrinking
{
public:
	// ��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourIncup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};
//��������
class Coffee:public AbstractDrinking
{
public:
	// ��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourIncup()
	{
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "���Ǻ�ţ��" << endl;
	}
};

//������Ҷ
class Tea :public AbstractDrinking
{
public:
	// ��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourIncup()
	{
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "ʲô������" << endl;
	}
};

void doWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}

void test1()
{
	doWork(new Coffee);
	cout << "---------------" << endl;
	doWork(new Tea);
	
}
int main()
{
	test1();
	system("pause");

	return 0;
}

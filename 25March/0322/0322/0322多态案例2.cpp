# include <iostream>
using namespace std;
/*
多态案例2：利用多态技术实现制作饮品，提供抽线制作饮品基类
提供子类制作咖啡和茶叶
*/

class AbstractDrinking
{
public:
	// 煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourIncup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourIncup();
		PutSomething();
	}
};
//制作咖啡
class Coffee:public AbstractDrinking
{
public:
	// 煮水
	virtual void Boil()
	{
		cout << "煮开水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourIncup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加糖和牛奶" << endl;
	}
};

//制作茶叶
class Tea :public AbstractDrinking
{
public:
	// 煮水
	virtual void Boil()
	{
		cout << "煮开水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourIncup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "什么都不加" << endl;
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

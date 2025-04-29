# include <iostream>
using namespace std;
/*
电脑组装案例:
电脑主要分为CPU 显卡 内存条
将每个零件封装出抽象基类 提供不同厂商生产不同零件 
创建电脑类提供让电脑工作的函数 调用每个零件工作的接口
测试时组装三台不同的电脑进行工作
*/

class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, VideoCard * vc, Memory * mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	// 工作函数 调用相应接口
	void doWork()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	// 提供析构函数 释放3个电脑零件
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

//构造函数传入三个零件的指针
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

// 具体厂商
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储数据" << endl;
	}
};


class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储数据" << endl;
	}
};


void test1()
{
	// 第一台电脑零件
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelVc = new IntelVideoCard;
	Memory* intelmem = new IntelMemory;

	// 创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelVc, intelmem);
	computer1->doWork();
	delete computer1;

	cout << "------------" << endl;
	// 创建第二台电脑
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard,new LenovoMemory);
	computer2->doWork();
	delete computer2;
	cout << "------------" << endl;
	// 创建第三台电脑
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->doWork();
	delete computer3;
}
int main()
{
	test1();
	system("pause");

	return 0;
}

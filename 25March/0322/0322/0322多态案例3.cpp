# include <iostream>
using namespace std;
/*
������װ����:
������Ҫ��ΪCPU �Կ� �ڴ���
��ÿ�������װ��������� �ṩ��ͬ����������ͬ��� 
�����������ṩ�õ��Թ����ĺ��� ����ÿ����������Ľӿ�
����ʱ��װ��̨��ͬ�ĵ��Խ��й���
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

	// �������� ������Ӧ�ӿ�
	void doWork()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	// �ṩ�������� �ͷ�3���������
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

//���캯���������������ָ��
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

// ���峧��
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢����" << endl;
	}
};


class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢����" << endl;
	}
};


void test1()
{
	// ��һ̨�������
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelVc = new IntelVideoCard;
	Memory* intelmem = new IntelMemory;

	// ������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelVc, intelmem);
	computer1->doWork();
	delete computer1;

	cout << "------------" << endl;
	// �����ڶ�̨����
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard,new LenovoMemory);
	computer2->doWork();
	delete computer2;
	cout << "------------" << endl;
	// ��������̨����
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

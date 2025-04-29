#pragma once
//自己使用的通用的数组

#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	// 有参构造 参数 容量 开辟空间
	MyArray(int capacity)
	{
		//cout << "有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造
	MyArray(const MyArray & arr)
	{
		//cout << "拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		/*this->pAddress = arr.pAddress;*/  //这是浅拷贝
		this->pAddress = new T[arr.m_Capacity];

		// 将arr中的数据都拷贝过来
		for (int i = 0;i < this->m_Size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "operator= 调用" << endl;
		// 先判断堆区是否有数据 若有 先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		// 将arr中的数据都拷贝过来
		for (int i = 0;i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;// this是指向当前对象的指针 解引用就是指向当前对象的引用
	}
	 

	// 尾插法
	void Push_Back(const T& val)
	{
		// 判断容量是否等于大小
		if (this->m_Capacity == this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	// 尾删法
	void Pop_Back()
	{
		// 让用户访问不到最后一个元素
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}
	// 通过下标方式访问数组中的元素
	//operator[]表示运算符重载，允许通过下标访问对象中的成员
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	// 返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	// 返回数组大小
	int getSize()
	{
		return this->m_Size;
	}

	// 析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}

	}
private:
	T * pAddress; // 指针指向堆区开辟的真实数组
	int m_Capacity; // 数组容量
	int m_Size;// 数组大小
};
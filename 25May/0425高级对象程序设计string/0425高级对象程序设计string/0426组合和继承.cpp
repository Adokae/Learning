#include <iostream>
using namespace std;

/*
面向对象语言：类之间的关系：
1 复合：类中含有另一个类 表示为has a
外面的类称为container，所包含的另一个类称为component

构造由内而外:container的构造函数先调用component的构造函数 然后才执行自身的默认构造函数

析构由外而内：container的析构函数先执行自己，然后才调用component的析构函数

2 继承：表示一个类是另一个类中的一种， 表示is a
公有继承：子类完成继承父类的数据
公有继承最有价值的是跟虚函数继承

构造由内而外:derived的构造函数先调用base的默认构造函数 然后才执行自身的构造函数
(子类继承父类，子类要包含父类)

析构由外而内：derived的析构函数先执行自己，然后才调用base的析构函数

继承与虚函数(inheritance with virtual function)：
non-virtual函数：不希望子类重新定义
virtual函数：希望子类重新定义，已有默认定义
pure vitrual函数：希望子类一定要重新定义它，对它没有默认定义

3 委托：类中拥有一个指针指向另一个类

*/



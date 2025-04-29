#特殊属性
'''
特殊属性:
__dict__：获得类对象或实例对象所绑定的所有属性和方法的字典

特殊方法：
__len__()：通过重写该方法，让内置函数len()的参数可以是自定义类型
__add__()：通过重写该方法，可使用自定义对象具有“+”功能
__new__()：用于创建对象
__init__()：对创建对象进行初始化

'''
'''
class A:
    pass
class B:
    pass
class C(A,B):
    def __init__(self,name,age):
        self.name = name
        self.age = age

#创建一个C的实例对象
#特殊属性
x = C('Jack',20)
print(x.__dict__) #实例对象的属性字典
print(C.__dict__) #类的属性
print(x.__class__) #输出对象所属于的类 <class '__main__.C'>
print(C.__bases__) #C类的父类类型的元素 (<class '__main__.A'>, <class '__main__.B'>)
print(C.__base__) #输出一个离它最近的 <class '__main__.A'>
print(C.__mro__) #类的层次结构  (<class '__main__.C'>, <class '__main__.A'>, <class '__main__.B'>, <class 'object'>)
print(A.__subclasses__()) #子类的继承 [<class '__main__.C'>]
'''


#特殊方法
a = 20
b = 100
c = a+b
d = a.__add__(b)
print(c,d) #120 120

class Student:
    def __init__(self,name):
        self.name = name
    def __add__(self,other):
        return self.name+other.name
    def __len__(self):
        return len(self.name)

stu1 = Student("张三")
stu2 = Student("李四")

s = stu1+stu2 #实现加法运算，在类中编写了__add__()的特殊方法
print(s)

print("---------len-------")
lst = [11,12,13,14]
print(len(lst)) #内置函数
print(lst.__len__())
print(len(stu1))
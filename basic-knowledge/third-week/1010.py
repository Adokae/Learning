#动态绑定属性和方法
#python是动态语言，在创建对象之后，可以动态的绑定属性和方法
#每个实例对象的属性值可以不同
'''
class Student:
    def __init__(self,name,age):
        self.name = name
        self.age = age

    def eat(self):
        print(self.name+"要吃饭")

stu1 = Student("张三",20)
stu2 = Student("李四",19)
print(id(stu1)) #1373836919888
print(id(stu2)) #1373836920208 内存地址不同

print("-------为stu2动态绑定性别属性-----")
#在创建实例对象只对单独一个添加
stu2.gender = "女"
print(stu1.name,stu1.age)
print(stu2.name,stu2.age,stu2.gender)

print("-----动态绑定类别-----")
stu1.eat()
stu2.eat()

def show():
    print("定义在类之外，称函数")
#调用函数
stu1.show = show
stu1.show()
#只对stu1绑定了方法,动态绑定
'''

#面向对象三大特征：封装、继承、多态

#继承
#python中若不希望该属性在类对象外部被访问，前面使用两个“_”
'''
class Students:
    def __init__(self,name,age):
        self.name = name
        self.__age = age #不希望在类的外部被使用

    def show(self):
        print(self.name,self.__age)

stu = Students("张三",20)
stu.show()

#在类的外面使用
print(stu.name)
#print(stu.age) #'Students' object has no attribute 'age'

#若想在类外面使用，则要：
print(stu._Students__age)
'''

#继承
'''
语法格式：
class 子类类名（父类1，父类2，...）:
    pass
    
若一个类没有继承任何类，则默认继承object
支持多继承
定义子类时，必须在其构造函数中调用父类的构造函数
'''
'''
class Person(object):
    def __init__(self,name,age):
        self.name = name
        self.age = age

    def info(self):
        print(self.name,self.age)


class Student(Person):
    def __init__(self,name,age,stu_no):
        super().__init__(name,age) #继承父类
        self.stu_no = stu_no
    def info(self):
        super().info()#调用父类
        print(self.stu_no) #重写了方法
class Teacher(Person):
    def __init__(self,name,age,teacherofyear):
        super().__init__(name,age)
        self.teacherofyear = teacherofyear
    def info(self):
        super().info()
        print("教龄为：",self.teacherofyear)


class C(Student,Teacher,Person): #多继承
    pass

stu = Student("张三",20,"2310")
teach = Teacher("李四",34,10)

stu.info()
teach.info()
'''


'''
方法重写：若子类对继承自父类的某个属性或方法不满意，可在子类中对其进行重新编写
重写后方法可通过super.xxx()调用父类中被重写的方法
'''


''''
object类为所有类的父类，所有类内都有object类的属性和方法
内置函数dir()可查看指定对象所有属性
object中的_str_()方法，用于返回一个对于“对象的描述”

'''
'''
class Student:
    def __init__(self,name,age):
        self.name = name
        self.age = age
    def __str__(self):
        return "我叫{0},今年{1}岁".format(self.name,self.age)

stu = Student("张三",20)
print(dir(stu))
print(stu) #<__main__.Student object at 0x000001CB29C9FD90> 内存地址
#修改之后,输出为：我叫张三,今年20岁
'''

#多态
'''
多种形态，即使不知道一个变量所引用的对象到底是什么类型，仍可通过这个变量调用方法，
在运行中根据变量所引用对象的类型，动态决定调用那个对象中的方法
python为动态语言，不关心对象类型，只关心对象行为
'''


class Animal(object):
    def eat(self):
        print("动物会吃")

class Dog(Animal):
    def eat(self):
        print("狗吃骨头")

class Cat(Animal):
    def eat(self):
        print("猫吃鱼")

class Person:
    def eat(self):
        print("人杂食")

#函数
def fun(obj):
    obj.eat()

#调用函数
fun(Cat())
fun(Dog())
fun(Animal())

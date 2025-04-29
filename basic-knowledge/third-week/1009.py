#类
'''
面向过程：线性思维解决问题
面向对象：不能用线性思维解决问题
'''

'''
类：类别，类似事物
对象：类别下的一个具体个例
创建：
class 类名：
     内容

'''

#创建
class Students: #类名由一个或多个单词组成，每个单词首字母大写，其余小写
    native_space = "cq" #直接写在类里面的变量，称为类属性

    #引义的初始化方法
    def __init__(self,name,age): #name age为实例属性
        self.name = name #赋值操作，self.name称为实例属性，将局部变量name的值赋给实例属性
        self.age = age    #习惯上实例属性与局部变量名字相同

   #类属性-写在类里面的def 而写在类外面的def成为函数
   #实例方法 函数名后写self
    def eat(self):
        print("吃饭")

   #类方法 函数名后加cls
    @classmethod
    def cm(cls):
        print("使用classmethod进行修饰，故为类方法")

   #静态方法 函数名后不加
    @staticmethod
    def method():
        print("使用staticmethod进行修饰，故为静态方法")



#函数
def drink():
    print("喝水")


'''
#一切皆对象 类名也成为对象
print(id(Students))
print(type(Students)) #<class 'type'>
print(Students) #<class '__main__.Students'>
'''


'''
对象创建-类的实例化
实例名 = 类名（）
'''
#创建Students类的对象
stu1 = Students("张三",20) #类的实例对象

'''
print(id(stu1))
print(type(stu1)) #<class '__main__.Students'>
print(stu1) #<__main__.Students object at 0x000001C5A1E80C50>

print("Students称为类对象：")
print(id(Students))
print(type(Students)) #<class 'type'>
print(Students) #<class '__main__.Students'>
'''

#使用Students类中的类方法,使用类的实例对象
'''
stu1.eat()   #实例对象名.方法名()
print(stu1.name)
print(stu1.age)

print("--------换一种方法调用-------")
Students.eat(stu1) #此行与75行作用相同，都是调用Students中的eat方法
#类名.方法名(类的实例对象名)--类的实例对象名实际上就是方法定义处的self
#实例方法传递的是实例的对象，即self
'''

#类属性的使用方式
'''
类属性-类中方法外的变量称为类属性，被该类的所有对象所共享
类方法-使用@classmethod修饰的方法，使用类名直接访问的方法，类方法传递的是calss
静态方法-使用@staticmethod修饰的方法，使用类名直接访问的方法
类的实例对象内都有类指针指向类，故类属性为共享的
'''
'''
print(Students.native_space)
stu1 = Students("张三",20)
stu2 = Students("李四",19)
print(stu1.native_space)
print(stu2.native_space) #输出都为cq

#修改名称
Students.native_space = "hrb"
print(stu1.native_space)
print(stu2.native_space) #hrb

#类方法的使用方式
Students.cm()

#静态方法的使用方式，无默认参数
Students.method()
'''



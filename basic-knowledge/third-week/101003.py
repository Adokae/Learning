#特殊方法
#__new__()
class Person(object):

    def __new__(cls, *args, **kwargs):
        print("__new__被调用执行，cls的id值为{0}".format(id(cls)))
        obj = super().__new__(cls)
        print("创建的对象id为{0}".format(id(obj)))
        return obj  #返回到self

    def __init__(self,name,age):
        print("__init__被调用了，self的id值为{0}".format(id(self)))
        self.name = name
        self.age = age

print("object这个类对象id为{0}".format(id(object)))
print("Person这个类对象id为{0}".format(id(Person)))

#创建Person类的实例对象
p1 = Person("张三",20)  #Person传给了__new__的cls，最后self又传给了p1
print("p1这个Person类的实例对象的id为：{0}".format(id(p1)))
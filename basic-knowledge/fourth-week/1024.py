import numpy as np
#time模块中strftime使用
'''
import time
t1 = time.strftime("%m-%d-%H-%M")
print(t1) #10-24-14-22
'''


#类的继承super用法
class Base(object):
    def __init__(self):
        print("enter Base")
        print("leave Base")


class A(Base):
    def __init__(self):
        print("enter A")
        super(A,self).__init__() #此处self是C的实例，故搜索A在MRO中的下一类
        print("leave A")


class B(Base):
    def __init__(self):
        print("enter B")
        super(B,self).__init__()
        print("leave B")

class C(A,B):
    def __init__(self):
        print("enter C")
        super(C,self).__init__()
        print("leave C")

c = C()


'''
定义类时，会产生一个方法解析顺序,MRO列表，表示类继承的顺序
原则：子类在父类前；多父类根据在列表中顺序被检查；下一类中有两个合法选择，选第一个父类
'''
#print(C.mro()) #[<class '__main__.C'>, <class '__main__.A'>, <class '__main__.B'>, <class '__main__.Base'>, <class 'object'>]


'''
运行2次
j = 0
for i in range(1,3):
    print(i)
    j += 1

print(j)
'''

data = np.array([
                [[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1]],
                [[2,2,2],[2,2,2],[2,2,2],[2,2,2],[2,2,2]],
                [[3,3,3],[3,3,3],[3,3,3],[3,3,3],[3,3,3]],
                [[4,4,4],[4,4,4],[4,4,4],[4,4,4],[4,4,4]],
                [[5,5,5],[5,5,5],[5,5,5],[5,5,5],[5,5,5]]
        ],dtype='uint8')
print(data)

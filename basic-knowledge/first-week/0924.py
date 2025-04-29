#注释 单行#  多行‘’‘ ’‘’

#input()函数，接受输入，输入类型为str,使用变量对值进行存储
'''
present = input('what do you want?')
print(present)
'''

#输入两个整数，输出两个数之和
'''a = int(input('输入一个数'))
#a = int(a)
b = int(input('输入另外一个数'))
#b = int(b)
print(a+b)  #若不进行类型转换，此处加号只起到连接作用，因为输入数据为字符串类型'''

#运算符
#算术运算符
'''
print(1+1) #加法
print(2-1)
print(3*5)
print(11/2) #除法运算 
print(11//2)  #整除运算 5
print(11%2)   #取余运算 11/2=5+1 故结果为1
print(2**2)   #冥运算  2的2次方
print("")

print(-9//-2)   #4
print(9//-4)   #结果为-3，一正一负,向下取整(取整数，实际值为-2点多少，取值-3)
print(-9//4)
print("")

print(9%-4)  #结果为-3，公式为：余数=被除数-除数*商 此处商为取整商（要符合一正一负向下取整）9-(-4)*(-3)
print(-9%4)  #结果为3 -9-(-4)*(-3)
'''

#赋值运算符,运算顺序从右到左
'''
i = 3+4
print(i)

a = b = c =20  #链式赋值
print(a,id(a))
print(b,id(b))
print(c,id(c))

#参数赋值
a = 20
a += 30 #a=a+30 50
print(a)
a -= 10 #a=a-10 40
print(a)
a *= 2 #a=a*2 80
print(a)
a /=2 #a=a/2 40.0
print(a)
print(type(a))
a //=2 #a=a//2 20.0
print(a)


#解包赋值,要求左右元素对应
a,b,c = 10,20,30
print(a,b,c,type(a))

#交换两个变量的值
a,b = 10,20
a,b = b,a
print(a,b)
'''

#比较运算符,运算结果为布尔类型;一个变量由三部分组成：标识、类型、值，“==”所比较的变量的值，“is”比较的是对象的标识
'''
a,b = 10,20
print(a > b)
print(a >= b)
print(a < b)
print(a <= b)
print(a == b)
print(a != b)
'''

'''
#可变对象引用具有不同的id值，不可变对象引用时具有相同的id值
a = 10
b = 10
print(a is b) #对比对象的id标识
print(a is not b)
print("")

list1 = [11,22,33,44]
list2 = [11,22,33,44]
print(id(list1))
print(id(list2))
print(list1 == list2)
print(list1 is list2)
print(list1 is not list2)
print("")

c = (1,2,3)
d = (1,2,3)
print(id(c))
print(id(d))
print(c == d)
print(c is d)
'''

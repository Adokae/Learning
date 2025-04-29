#元组-不可变序列，还有字符串.元组：（“对象”,"对象"）
#可变序列-字典、列表
'''
#例子
#可变序列
lst = [10,20,30]
print(id(lst))
print(lst)
lst.append(100)
print(lst)
print(id(lst))
#不可变序列
a = "hello"
b = a+"world"
print(id(a),id(b))
'''

'''
#元组的创建
#第一种
t = ("hello","world",98)
print(t,type(t))

t2 = "hello","world",98 #元组创建也可不加小括号
print(t2,type(t2))

t3 = ("hello",) #元组只有一个元素，要加小括号和逗号
print(t3,type(t3))  #('hello',) <class 'tuple'>
t4 = ("hello") #未加逗号，被视为字符串
print(t4,type(t4)) #hello <class 'str'>

#第二种
t1 = tuple(("hello","world",98))
print(t1,type(t1))

#空元组的创建方式
t5 = ()
t6 = tuple()
print(t5,t6)
'''

'''
元组设置为不可变序列的原因：
（1）多任务环境下，为确保安全性，只有一个对象对序列操作时加锁；而不可变序列则不需要加锁
（2）元组中存储的是对象的应用
 <1>若元组对象本身不可变对象，则不能在引用其它对象
 <2>若元组对象本身为可变对象，则可变对象的应用不可以改变，但数据可以改变
 例：一个元组存储有整型、列表：t=(10,[20,30],8)，
 t[1]=100,将元组索引为1修改为100，是不可以的，实际上元组存储的是列表的应用，应用不可以更改
 t[1].append(100)，在列表中添加元素是可以的
'''

'''
t = (10,[20,30],9)
print(t,type(t))
print(t[0],type(t[0]),id(t[0]))
print(t[1],type(t[1]),id(t[1]))
print(t[2],type(t[2]),id(t[2]))
#尝试将t[1]修改为100
#t[1] = 100  'tuple' object does not support item assignment
t[1].append(100)
print(t,id(t[1])) #列表的内存地址不变
'''

#元组的遍历
t = tuple(("hello","world",90))
for i in t:
    print(i)
print(t[0])  #索引元组的具体位置值
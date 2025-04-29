#集合-可变序列，没有value的字典,集合中元素不可重复,其中元素无序
#集合的创建
'''
#第一种-直接创建
s = {"hello","world",90,90} #打印输出只有三个元素
print(s)

#第二种创建
s1 = set(range(6))
print(s1)
print(set([1,2,3,4]))
print(set((1,2,34,5,6)))
print(set("Python"))
print(set({98,45,67})) #set()将列表、元组、字符串、集合都可转变为集合
print(type({12,39}))  #<class 'set'>

#空集合
s2 = {}
print(type(s2)) #空字典，<class 'dict'>

s3 = set()
print(type(s3)) #<class 'set'>
'''

#集合的操作
#判断操作-in\not in
#新增-add()一次添加一个元素，update()每次至少添加一个元素
'''
删除操作
remove()一次删除一个指定位置元素，指定元素不存在则抛出KeyError
discard()一次删除一个指定位置元素，指定元素不存在则抛出异常
pop()一次删除一个任意元素
clear()清空集合
'''
'''
#判断
s = {10,20,30,40,50}
print(10 in s)
print(10 not in s)

#添加
s.add(80)
print(s)
s.update({90,120,230})
s.update([45,67])
s.update((12,34,98))
print(s)

#删除
s.remove(90)
print(s)
#s.remove(500)
#print(s)   #KeyError: 500

s.discard(500)
print(s)  #不报错

s.pop()  #不能添加参数，只能随即删除一个元素
print(s)

s.clear()
print(s) #set()
'''

#集合间的关系
#判断集合间是否相等,元素相同就相等
'''
s = {10,20,30}
s1 = {10,20,30}
print(s == s1) #True
print(s != s1) #False
'''

#一个集合是否为另一个集合的子集
'''
s = {10,20,30,40,50,60}
s1 = {10,20,30}
s2 = {30,40,56,78}
print(s1.issubset(s)) #True
print(s2.issubset(s)) #False
'''

'''
#判断集合是否为一个集合的超集，B是A的子集，则A是B的超集
s = {10,20,30,40,50,60}
s1 = {10,20,30}
s2 = {30,40,56,78}
print(s.issuperset(s1)) #True
print(s.issuperset(s2)) #False

#判断两个集合是否有交集
print(s.isdisjoint(s2)) #False 有交集为False
s3 = {299,89}
print(s1.isdisjoint(s3)) #True 无交集
'''

#集合的数学操作
'''
#求集合的交集
s = {10,20,30,40,50}
s1 = {10,20,30,78,98}
print(s.intersection(s1))
print(s & s1) #{10, 20, 30}

#并集
print(s.union(s1)) #{98, 40, 10, 78, 50, 20, 30}
print(s | s1)

#差集
print(s.difference(s1)) #{40, 50}
print(s1.difference(s)) #{98,78}
print(s-s1)

#对称差集
print(s.symmetric_difference(s1))
print(s ^ s1)  #{98, 50, 40, 78}
'''

#集合生成式
s = {i for i in range(6)}
print(s)  #{0, 1, 2, 3, 4, 5}

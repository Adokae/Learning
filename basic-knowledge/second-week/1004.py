#列表中的查询操作
#获取列表中的多个元素，列表名[strat:stop:step]
#切片默认为列表中片段的拷贝，step默认为1,不包括stop
#step为正，切片第一个元素默认为列表的第一个元素，从start开始往后切
#step为负，切片第一个元素默认为列表的最后一个元素，从start开始往前切
'''
lst = [10,20,30,40,50,60,70,80,90,100]
lst1 = lst[1:6:1]
print(lst1)
print("原列表：",id(lst))
print("切片1:",id(lst1))

#步长为1
print(lst[1:6])
print(lst[1:6:])

#默认开始、结束
print(lst[:6:2])
print(lst[::2])

#步长为负数,从后往前
print(lst[::-1])
print(lst[5:2:-2])
print(lst[-1:-7:-3])
'''

#列表中查询操作，in或者not in，元素in/not in 列表名
'''
列表中的迭代操作
for 迭代变量 in 列表名：
    操作
'''
'''
lst = [10,20,30,"hello","world"]
print(10 in lst)
print("list" not in lst)

#迭代变量
for i in lst:
    print(i,end=" ")
'''

#列表元素的增加操作,未改变列表的标识
'''
append()-在列表末尾添加一个元素
extend()-在列表末尾至少添加一个元素,也可以是列表元素
insert()-在列表的任意位置添加一个元素
切片-在列表的任意位置至少添加一个元素
'''

'''
lst = [10,20,30,"hello","world"]
print("添加之前：",lst,id(lst))
lst.append("100")
print("添加之后：",lst,id(lst))
lst1 = ["momo","github"]


#在元素末尾添加
#lst.extend([100,40])
lst.extend(lst1)   #extend()都是把列表中的元素添加到原列表中
print(lst,id(lst))
lst.append(lst1)  #apend()是将列表视为一个整体加入到原列表中
print(lst,id(lst))

#在元素任意未知添加
lst.insert(1,100) #在原列表中索引为1的位置添加一个元素100
print(lst,id(lst))

#任意位置添加,将原列表所设置从开始元素后到结束的位置全部换成自己所添加的元素
lst2 = ["12",'14']
lst[1:2] = lst2
print(lst,id(lst))
'''

#列表元素的删除操作
'''
remove()一个删除一个元素，重复元素只删除第一个，元素不存在则返回ValueError
pop()删除指定索引位置上的元素，指定索引不存在则返回IndexError，不指定索引则删除最后一个元素
切片一次至少删除一个元素
clear()清空列表
del删除列表
'''

'''
#remove()操作
lst = [10,20,30,40,50,60,30,40]
lst.remove(30)
print(lst)
#lst.remove(100)

#pop()操作
lst.pop(1)
print(lst)
#lst.pop(10)
lst.pop()
print(lst)

#列表操作
lst1 = lst[1:3]
print(lst)
print(lst1)
lst[1:3] = [] #删除原列表中索引为1、2位置元素
print(lst)

#clear()操作
lst.clear()
print(lst)

#del操作
del lst
# print(lst) 直接删除列表元素
'''

'''
列表元素的修改-为指定索引元素赋予一个新值或为指定切片赋予一个新值

'''
'''
lst = [10,20,30,40,50,60,70,80]
#一个修改一个值
lst[1] = 100
print(lst)

#修改多个值
lst[1:3] = [20,300,400,500]
print(lst)
'''

#列表排序操作
'''
(1)调用sort()方法，列表中所有元素按从小到大顺序排列，也可指定reverse=True,进行降序排列
(2)调用内置函数sorted()，也可指定reverse=True,进行降序排序，原列表不发生改变

'''
lst = [10,30,50,89,3,9,45]
'''
print("排序前：",lst,id(lst))
lst.sort()
print("排序后：",lst,id(lst))
#降序
lst.sort(reverse=True)
print("降序后：",lst)
#升序
lst.sort(reverse=False)
print(lst)
'''

#使用内置函数
'''
lst1 = sorted(lst)
print(lst,id(lst))
print(lst1,id(lst1))

#降序操作
lst2 = sorted(lst,reverse=True)
print(lst2,id(lst2))
'''

'''
#列表生成式-生成列表的公式
#第一个元素是列表所存储的值，表示列表元素的表达式
lst2 = [i for i in range(1,10)]
print(lst2)
lst3 = [i*i for i in range(1,10)]
print(lst3)

#列表中元素的值为2，4，6，8，10
lst4 = [i for i in range(2,11,2)]
print(lst4)
'''
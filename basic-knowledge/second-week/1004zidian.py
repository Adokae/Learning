#字典，python内置数据结构之一，可变序列（进行增、删、改），以键对值方式存储数据，无序序列
#{“键”：值}，键要求为不可变序列，而字符串就是不可变序列
#python中根据key值查找value所在的位置

#字典的创建
'''
#使用花括号
scores = {"张三":100,"李四":98,"王五":89}
print(scores)
print(type(scores))

#使用dict{}
students = dict(name="Mike",age=20,name1 = "John",age1 = 19,)
print(students)

#空字典
d = {}
print(d)
'''

#字典元素的获取
#[] 若字典中不存在指定key，则输出KeyError
#get() 若字典中不存在指定key，返回None
'''
scores = {"张三":100,"李四":98,"王五":89}
print(scores["张三"])
# print(scores["陈留"]) 报错 KeyError
print(scores.get("张三"))
print(scores.get("陈留")) #None
print(scores.get("陈留",99)) #将不存在的索引所对应的返回值改为99
print(scores.get("张三",99)) 
'''

#字典的常用操作
#key的判断 in/not in
'''
scores = {"张三":100,"李四":98,"王五":89}
print("张三" in scores)
print("张三" not in scores)

#删除操作
del scores["张三"]
print(scores)

#清空字典元素
#scores.clear()
#print(scores)

#新增操作
scores["陈六"] = 90 #只能增加一个，若多个，会用()表示为一个
print(scores)

#修改
scores["陈六"] = 87
print(scores)
'''

#获取字典视图
'''
keys()获取字典中所有key
values()获取字典中所有value()
items()获取字典中所有key、value对
'''

'''
scores = {"张三":100,"李四":98,"王五":89}
#获取所有的键
keys = scores.keys()
print(keys,type(keys))
print(list(keys))   #由于keys本身是放置在列表中的，故可将其转换为列表

#获取所有的值
values = scores.values()
print(values,type(values))
print(list(values))

#获取所有的键值对
items = scores.items()
print(items)
print(list(items))  #转换之后的元素为元组
'''

#字典元素的遍历
'''
scores = {"张三":100,"李四":98,"王五":89}
#遍历的是字典中的键,获取值的方法在其后
for i in scores:
    print(i,scores[i],scores.get(i))
    '''

'''
字典的特点：
（1）字典所有元素都是一个key-value对，key不可重复，value可以重复
（2）字典中元素无序
（3）字典中key必须是不可变对象
（4）字典根据需要动态伸缩
（5）字典会浪费较大内存，是一种以空间换时间的数据结构
'''
#举例如下
'''
d = {"name":"张三","name":"李四"}
print(d) #{'name': '李四'}

d = {"name":"张三","nikename":"张三"}
print(d) #{'name': '张三', 'nikename': '张三'}
'''

#字典生成式
#zip(),将可迭代对象作为参数，将对象中元素打包成一个数组，返回由这些元素组成的列表

items = ["Fruits","Books","Others"]
prices = [98,78,60,89,90]
lst = zip(items,prices)
print(list(lst)) #[('Fruits', 98), ('Books', 78), ('Others', 60)]
d = {items.upper():prices for items,prices in zip(items,prices)}#打包过程中以元素少的为基准
print(d)
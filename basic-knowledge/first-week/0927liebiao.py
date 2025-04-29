#列表，用于存储多个元素，可对这些数据进行整体操作。列表中从左往右索引为0，1，2....,从右往左索引为-1，-2，....
'''
list1 = ["hello",'world',"10","14"]
print(id(list1))
print(type(list1))
print(list1)
print(list1[1],list1[-1])
'''

#列表创建
'''
list2 = ["hello","world"]
#创建第二种方法，使用内置函数list()
list3 = list(["10","11","12"])
print(list2[1])
print(list3[2])  #若超出索引 报错“list index out of range”
'''

'''
list4 = list("10","2") #报错：TypeError: list expected at most 1 argument, got 2
print(type(list4))
'''

#列表特点：列表元素有序排列、索引映射唯一数据、可存储重复元素、任意数据类型混存、根据需要动态分配和回收内存

#列表查询操作
#获取列表中指定元素的索引
'''index()>若查询存在多个相同元素，只返回相同元素中的第一个元素的索引
>若查询元素不存在，返回ValueError。还可在指定的start-stop之间查询
'''
list2 = ["hello","world","23",12,23,42,32,"hello"]
print(list2.index("hello"))
#print(list2.index(2))
print(list2.index("23",1,3))

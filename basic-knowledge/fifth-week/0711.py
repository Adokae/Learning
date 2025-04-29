#子木程序视频P58-P
#列表、字典、集合-可变数据类型，元组-不可变数据类型
#列表、元组、字典和集合遍历可用for实现 删除用del实现

'''
#千年虫
lst = [88,89,90,98,00,99] #员工的出生年份的后两位数字
#使用遍历的方式，第一个产生列表中的字符串，第二个产生列表中的整数
# for i in range(len(lst)):
    # if str(lst[i]) != '0':
    #     lst[i] = '19'+str(lst[i])
    # else:
    #     lst[i] = '200'+str(lst[i])

    # if lst[i] != 00:
    #     lst[i] = 1900+lst[i]
    # else:
    #     lst[i] = 2000+lst[i]

#使用enumerate()函数  循环遍历时同时获取元素索引和值
for i,j in enumerate(lst):
    if str(lst[i]) != '0':
        lst[i] = '19'+str(j)
    else:
        lst[i] = '200' + str(j)
print(lst)
'''

#模拟京东购物流程
'''
从键盘录入5个商品信息，展示商品信息，提示用户选择商品，用户选中商品加入到购物车中(购物车中商品要逆序)
选中商品不存在时要有相应提示 输入'q'时循环结束，显示购物车中商品
'''
'''
numC = 5   #录入商品个数
lst = []
for i in range(numC):
    a = input("请输入商品的编号和商品的名称进行商品入库，每次只能输入一件商品:")
    lst.append(a)
lst1 = []
lst2 = []
for i in lst:
    lst1.append(i[0:4])
    lst2.append(i[4:])
    print(i)
d = dict(zip(lst1,lst2)) #也可以直接在列表中取一个元素的前四为判断商品编号
lst3 = []
f = True
while f:
    c = input("请输入要购买的商品编号：")
    if  c != "q":
        if c in lst1:
            e = c+str(d.get(c))
            lst3.append(e)
            print("商品已成功添加到购物车")
        else:
            print("该商品不存在！")
    else:
        f = False
lst3.reverse()
print("-"*50)
print("您购物车里已选择的商品为：")
for i in range(len(lst3)):
    print(lst3[i])
'''

#模拟12306的购票流程
'''
information = {
    "G1569":["北京南-天津南","18:06","18:39","00:33"],
    "G1567":["北京南-天津南","18:15","18:49","00:34"],
    "G8917":["北京南-天津西","18:20","19:19","00:59"],
    "G203":["北京南-天津南","18:35","19:09","00:34"],
}
#打印出车次信息
print("车次   出发站-到达站     出发时间       到达时间     历时时长")
for key in information.keys():
    print(key,end = " ")
    for item in information.get(key):
        print(item,end=" ")
    print()#一行信息遍历完后进行换行
a = input("请输入要购买的车次：")
c = information.get(a,"车次不存在") #乘车信息
if c != "车次不存在":
    b = input("请输入乘车人，如果是多位乘车人使用逗号分隔：")
    print("你已购买了%s %s %s开，请%s尽快换取纸质车票.[铁路客服]" % (a,c[0],c[1],b))
else:
    print("你所选择的车次不存在，请重新选择")
'''

#模拟手机通讯录
#从键盘输入五位好友姓名和电话
'''
s = set()
for i in range(5):
    a = input("请输入第%d位好友的姓名与手机号码：" % (i+1))
    s.add(a)
for i in s:
    print(i)
'''

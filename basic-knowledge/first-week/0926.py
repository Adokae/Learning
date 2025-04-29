'''
嵌套if
if 条件表达式1：
   if 内层表达式：
      内层执行条件1
   else:
      内层执行条件2
else:
   条件执行体
'''
'''
answer = input("请说出答案为yes或者no:")
money = float(input("输入你购买物品的金额数目："))
if answer == "yes":
    if money >= 200:
        print("应支付金额：",money*0.8)
    else:
        print("应支付金额数：",money*0.9)
else:
    print("应支付金额数：",money)'''

#条件表达式
#x if 判断条件 else y 若判断条件成立，执行x,否则，执行y
'''
a = float(input("输入第一个数："))
b = float(input("输入第二个数："))
print(str(a)+"大于等于"+str(b) if a >= b else (str(a)+"小于"+str(b)))
'''

#pass语句
'''
answer = input("请说出答案为yes或者no:")
money = float(input("输入你购买物品的金额数目："))
if answer == "yes":
    if money >= 200:
        print("应支付金额：",money*0.8)
    else:
        print("应支付金额数：",money*0.9)
else:
    pass
'''

#对象可直接放在条件表达式中作为条件判断

#range()函数 随机生成一个整数序列
'''
创建方式:range(stop)：从0-stop 步长为1
range(start,stop):从start-stop 步长为1
range(start,stop,step):从start-stop 步长为step
in \ not in判断是否在序列中
不管range()所表示的整数序列有多长，所占用的内存空间相同，只有用到range()对象时，才会去计算序列中的相关元素
'''

'''
a = range(3)
print(a) #range(0,3) print(range(3))

print(list(a))  #查看所使用对象中的整数序列 [0,1,2]
b = range(1,3)
print(list(b))
c = range(1,10,2)
print(list(c))
print(1 in a)
print(1 not in a)
'''

#循环结构
'''
while；刚开始判断一次，执行完条件后在判断,条件为假跳出循环
while 条件表达式：
      条件执行体
'''
#计算0-9累加和
'''
a = 0
sum = a
while a <= 9:
    a += 1
    sum += a
print(sum)

#计算1-100之间的偶数和
a = 1
sum = 0
while a <= 100:
    if a%2 == 0:
        sum += a
    else:
        sum += 0
    a += 1
print(sum)'''

#for-in循环
'''
遍历对象为可迭代对象-字符串 序列
for 自定义变量 in 可迭代对象：
    循环体
'''

'''
for i in "Python":
    print(i,end=" ")

for a in range(10):
    print(a,end=" ")

for _ in range(4):
    print("r")
'''

#使用for循环，计算1-100之间偶数和
'''
sum = 0
a = 0
#从0开始，加101次才加到100
for i in range(0,101):
    if a%2 == 0:
        sum += a
    a += 1
print(sum)'''

#输出100-999之间的水仙花数，水仙花数为各位数立方和等于该数
for i in range(100,1000):
    a = i // 100
    b = (i - a * 100) // 10
    c = i % 10
    if i == a**3+b**3+c**3:
        print(i)
    else:
        continue #pass


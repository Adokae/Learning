#布尔运算符 and-与 or-或 not-非 in-在其中   not in-不在其中
'''
a,b = 1,2
print(a==1 and b==2)
print(a==1 or b!=2)
print(not a==1)

x = 'hello'
print('he' in x)
print('he' not in x)
'''

#位运算 将数改为二进制后进行运算，对应位进行与或非运算 &-与 |或 <<左移，高位溢出舍弃，低位补0  >>右移，低位溢出舍弃，高位补0
'''
print(4 & 8)
print(4 | 8)
print(4<<1)  #左移1位
print(4<<2)
'''

#运算优先级：算术运算《位运算《比较运算《布尔运算《赋值运算

#程序的组织结构-顺序结构、选择结构、
#顺序结构
'''
print('第一步')
print('第二步')
print('第三步')
'''

#python中一切皆对象，所有对象都有一个布尔值，获取对象的布尔值用bool()
#以下对象的布尔值为False:False、0、None、空字符串\列表\元组\字典\集合
#测试对象布尔值
'''
print(bool(0))

print(bool([])) #空列表
print(bool(list())) #空列表

print(bool(()))
print(bool(tuple()))  #空元组

print(bool({}))
print(bool(dict())) #空字典、

print(bool(set()))  #空集合'''

#选择结构
#单分支结构
# if 条件表达式：
#    条件执行体
'''
m = 1000
s = int(input("输入取款金额："))
if m >= s:
    m = m-s
    print("取款成功，余额为：",m)
'''

#双分支结构
# if 条件表达式：
#    条件执行体1
#else:
#    条件执行体2
'''
m = 1000
s = int(input("输入取款金额："))
if m >= s:
    m = m-s
    print("取款成功，余额为：",m)
else:
    print("卡中余额不足")'''

#多分支结构
# if 条件表达式：
#    条件执行体1
#elif 条件表达式2:
#    条件执行体2
#elif 条件表达式n:
#    条件执行体n
#else:
#    条件执行体n+1
'''
grade = int(input('输入学生成绩：'))
if grade >= 90:
    print("优秀")
elif 90 > grade >=80:
    print("良好")
elif 80 > grade >=70:
    print("中")
elif 70 > grade >=60:
    print("一般")
else:
    print("不及格")
'''
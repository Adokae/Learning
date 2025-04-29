#变量的定义与使用，标识、类型、值,name里存储的是标识
'''
name = 'Mike'
print(name)
print('标识',id(name))
print('类型',type(name))
print('值',name)
'''

#数据类型
#整数型-正数、负数、0，可表示为二进制、十进制、八进制、十六进制
'''
n1 = 90
n2 = -20
n3 = 0
print(n1,type(n1))
print(n2)
print(n3)

print('十进制',118)
print('二进制',0b1010111)
print('八进制',0o176)
print('十六进制',0x1EAF)
'''

#浮点类型-小数
'''
a = 3.14259
print(a,type(a))

#计算机存储浮点数时有时候会不精确
n1 = 1.1
n2 = 2.2
print(n1+n2)
#修改存储，修正
from decimal import Decimal
print(Decimal('1.1')+Decimal('2.2'))
'''

#布尔类型-true(1) or false(0),可转为括号内的整数
'''
f1 = True
f2 = False
print(f1,type(f1))
print(f2,type(f2))
print(f1+1)
print(f2+1)
'''

#字符串-必须用引号定义，单引号和双引号定义的字符串必须在一行，三引号可分布在连续多行
'''
str1 = 'person,people'
str2 = "person,people"
str3 = person,people #三引号
print(str1,type(str1))
print(str2)
print(str3)
'''

#数据类型转换,str()将其他类型转换为字符串,
name = 'Mike'
age = 20
#print('my name is '+name+'this year i am '+age+'') #出错，字符串与整数型连接时出错，需进行类型转换
print('my name is '+name+',this year i am '+str(age)+' years old')

print(str(age),type(str(age)))

#int()换为整数型，其中要求字符串为数字串,且要求为整数
s1 = '198'
print(int(s1),type(int(s1)))

s2 = '198.56'
#print(int(s2))

#float()换为浮点数，
print(float(s2))
print(float(s1),type(float(s1))) #整数加.0
#print(float('hello')) #非数字串不允许转换
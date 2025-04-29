#字符串
'''
字符串是Python中一个基本数据类型，是不可变序列
字符串驻留机制：
仅保存一份且不可变的字符串的方法，不同的值被存放在字符串的驻留池中
驻留机制只对相同的字符串保留一份拷贝，后续创建相同字符串时，不开辟新空间，只把该字符串的地址赋给新创建的变量

驻留机制的几种情况：
<1>字符串的长度为0或1时
<2>符合标识符的字符串,%不符合标识符
<3>字符串只在编译时进行驻留，而非运行时
<4>[-5，256]之间的整数数字

sys中的intern方法强制两个字符串指向同一个对象
Pycharm对字符串进行优化处理，例如在不符合标识符的字符串也被强制为符合标识符

进行字符串拼接时建议使用join方法，而非+,因为其效率更高
'''
'''
#字符串驻留机制
a = 'Python'
b = "Python"
c = Python #三引号
print(a,id(a))
print(b,id(b))
print(c,id(c)) #结果都为Python 140736794101768
'''

#字符串的常用操作
'''
#查询操作
#index()-查找子串substr第一次出现的位置，若查找不到，则抛出ValueError
#rindex()-查找子串substr最后一次出现的位置，若查找不到，则抛出ValueError
#find()-找子串substr第一次出现的位置，若查找不到，则返回-1
#rfind()-查找子串substr最后一次出现的位置，若查找不到，则返回-1

s = "hello,hello"   #逗号也占一个位置
print(s.index("lo"))  #3
print(s.rindex("lo")) #9
print(s.find("lo"))
print(s.rfind("lo"))
#  print(s.index("k"))  #ValueError: substring not found
print(s.find("k")) #-1
'''

#大小写转换
'''
upper()-把字符串所有字母都变成大写
lower()-把字符串所有字母都变成小写
swapcase()-把字符串所有大写字母变成小写，小写字母变成大写
capitalize()-把第一个字符变成大写，其它字符转换成小写
title()-把每个单词的首字母变成大写，其它字母变成小写
'''
'''
s = "hello,python"
a = s.upper() #转换成大写之后，会产生一个新的字符串对象
print(a,id(a))
print(s,id(s))

b = s.lower()
print(b,id(b)) #转换之后会产生一个新的字符串对象
s1 = "Hello,PyThon"

c = s1.swapcase()
print(c,id(c))

d = s1.capitalize()
print(d,id(d))

e = s1.title()
print(e,id(e))
'''

#对齐操作
'''
center()-居中对齐，若设置宽度小于实际宽度则返回原字符串，填充变量默认为字符
ljust()-左对齐
rjust()-右对齐
zfill()-右对齐,左侧用0填充，
'''

'''
s = "hello,python"
print(s.center(20,"*")) #s12个字符，所设置为20个字符，居中对齐，其余位置用*填充

print(s.ljust(20,"*"))
print(s.ljust(10))
print(s.ljust(20))

print(s.rjust(20,"*"))

print(s.zfill(20))
print(s.zfill(10)) #返回原字符
print("-2890".zfill(8)) #-0002890
'''

#分割操作
'''
split():
从字符串左边开始分割，默认的劈字符串是空格字符串，返回值为列表
sep指定劈分隔符

rsplit():
从字符串右边开始劈分
'''
'''
s = "hello python momo"
lst = s.split()
print(lst) #['hello', 'python', 'momo']

s1 = "hello|world|python"
print(s1.split(sep="|")) #设置其分隔符是|,['hello', 'world', 'python']
print(s1.split(sep="|",maxsplit=1)) #['hello', 'world|python']

lst1 = s.rsplit()
print(lst1)
print(s1.rsplit(sep="|"))
print(s1.rsplit(sep="|",maxsplit=1))  #['hello|world', 'python']
'''

#判断字符串操作的方法
'''
isidentifier()-判断指定字符串是否为合法的字符串
isspace()-判断指定字符串是否全部由黑白字符组成（回车、换行、水平制表符）
isalpha()-判断指定字符串是否全部由字母组成
isdecimal()-判断指定字符串是否全部由十进制数字组成
isnumeric()-判断指定字符串是否全部由数字组成
isalnum()-判断指定字符串是否全部由数字和字母组成
'''
'''
#判断字符串是否为合法的标识符
#合法的标识符为字母、数字、下划线
s = "hello,world"
print('1',s.isidentifier()) #False
print("2","hello".isidentifier()) #True
print("3","张三".isidentifier())

print("4","\t".isspace()) #True

print("5","abc".isalpha()) #True
print("6","张三".isalpha()) #True
print("7","张三1".isalpha()) #False

print("8","123".isdecimal()) #True
print("9","123四".isdecimal()) #False,罗马数字不是十进制数字

print("10","123".isnumeric()) #True
print("11","123四".isnumeric()) #True，罗马数字也认为是数字

print("12","123a".isalnum()) #True
print("13","123张三".isalnum()) #True
print("14","123!".isalnum()) #False
'''

#字符串的替换与合并
'''
字符串的替换：
replace()-第一个参数指定被替换的子串，第二个参数指定替换子串的字符串，返回替换后的字符串，替换前的字符串不变。


join()-将列表或元组中的字符串合并为一个字符串
'''
'''
s = "hello,python"
print(s.replace("hello","Java"))
s1 = "hello,hello,hello,python"
print(s1.replace("hello",'Java'))

lst = ["hello","python","world"]
print("|".join(lst)) #hello|python|world
print(" ".join(lst)) #hello python world

t = ("hello","world","python")
print(" ".join(t)) #hello world python

print("*".join("Python")) #P*y*t*h*o*n
'''

#字符串的比较操作
#比较运算符 > >= < <= == !=
'''
首先比较的是两个字符串的第一个字符，若相等则继续比较下一个字符，依次比较，直至两个字符串中字符不相等
比较原理：
两字符比较时，比较的是其原始值(ordinal value),可调用ord()函数查询其原始值
调用chr()函数时指定原始值可得到其对应字符
'''
'''
print("apple" > "app") #True
print(ord("a"),ord("b")) #97 98
print(chr(97),chr(98)) #a b
print("a" > "b") #False

a = b = "python"
c = "python"
print(a == b) #True
print(b == c) #True "=="比较的是值

print(a is b) #is比较的是内存地址(id)是否相等 True
print(b is c) #True,字符串驻留机制
'''

#字符串切片操作 [开始位置：结束位置：步长]
'''
#字符串为不可变类型，没有增、删、改操作，切片操作会产生新的对象
s = "hello,python"
s1 = s[:5]
s2 = s[6:]
s3 = "!"
s4 = s1+s3+s2

print(s1)
print(s2)
print(s4)
print(id(s),id(s1),id(s2),id(s3),id(s4)) #各不相同

print(s[1:5:1])
print(s[::2])
print(s[::-1]) #nohtyp,olleh
print(s[-6::]) #python
'''
'''
#格式化字符串
#(1)使用%作为占位符
name = "张三"
age = 20
print("我叫%s,今年%d岁" % (name,age))

#(2){}作为占位符
print("我叫{0}，今年{1}岁".format(name,age))

#(3)f-string
print(f"我叫{name}，今年{age}岁")

print("%10d" % 99) #10指的是宽度(加上99后的整体宽度)
print(1111111111)

print("%10.3f" % 3.1415926) #.3指的是精度，小数点后位数，10指的是宽度，3.142

print("{0}".format(3.1415926)) #3.1415926
print("{0:.3}".format(3.1415926)) #3.14 .3表示共有三位数字,此处冒号:表示引导符号，
print("{0:10.3f}".format(3.1415926)) #3.142 .3f表示有三位小数，10表示宽度，若使用e表示科学计数法
'''

#字符串的编码与解码
#计算机间字符串的传输是以字节（byte）为单位传输的
#编码-将字符串转换为二进制数据（bytes）
#解码-将bytes转换为字符串
#编解码格式要一致

s = "天涯共此时"
#编码
# 编码方式 str.encode(encoding = 'utf-8'/'GBK',errors = 'strict/ignore/replace')
# 语法格式如上所示，encoding表示所选择的编码方式，errors表示出错后的选择，strict表示若出错直接报错，ignore表示若出错直接忽略，replace表示若出错则替换为？
print(s.encode(encoding="GBK")) #b'\xcc\xec\xd1\xc4\xb9\xb2\xb4\xcb\xca\xb1'
#在GBK这种格式中，一个中文占两个字节
print(s.encode(encoding="UTF-8")) #b'\xe5\xa4\xa9\xe6\xb6\xaf\xe5\x85\xb1\xe6\xad\xa4\xe6\x97\xb6'
#在UTF-8这种格式中，一个中文占三个字节

#解码
# str.decode()
#byte代表的就是一个二进制数据（字节类型数据）
byte = b'\xcc\xec\xd1\xc4\xb9\xb2\xb4\xcb\xca\xb1'
#byte = s.encode(encoding="GBK")
print(byte.decode(encoding="GBK")) #解码

#byte = s.encode(encoding="UTF-8")
byte = b'\xe5\xa4\xa9\xe6\xb6\xaf\xe5\x85\xb1\xe6\xad\xa4\xe6\x97\xb6'
print(byte.decode(encoding="UTF-8"))
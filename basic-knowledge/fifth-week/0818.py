# 第六章：字符串和正则表达式
import re

# 6.1字符串的一些常用方法
# str.lower() 将str全部转换为小写，结果为一个新的字符串
# str.upper() 将str全部转换为大写，结果为一个新的字符串
# str.split(sep=) 将str按指定分隔符sep进行分割，结果为列表
# str.count(sub) 计算sub这个字符串在str中所出现的次数
# str.find(sub) 查询sub在str中是否存在，不存在结果为-1，存在则返回其第一次出现的索引
# str.index(sub) 功能与find一致，区别在于若不存在则程序报错
# str.startswith(s) 查询字符串str是否以s开头
# str.endswith(s) 查询字符串str是否以s结尾 可用于判断文件类型
# str.replace(old,news) 使用news去替换所有的Old字符串，结果为一个新的字符串
# str.center(width,fillchar) 字符串在指定宽度中居中，不足用fillchar填充
# str.join(iter) 在iter的每个元素后增加一个新的字符串str,以str为分隔符，将iter中的所有元素合并为一个新的字符串
# str.strip(chars) 在字符串中去掉左侧和右侧chars中列出的字符串
# str.lstrip(chars) 去掉左侧chars中列出的字符串
# str.rstrip(chars) 去掉右侧chars中列出的字符串


"""
#  常用方法示例
s1 = "HelloWorld"
s1_new1 = s1.lower()
s1_new2 = s1.upper()
print(s1,s1_new1,s1_new2)
a = s1.count("o")
print(a)

s2 = "hello,world"
b = s2.split(",")
print(b,type(b))

c = s2.find("l")
d = s2.index("l")
print(c,d)

print(s2.startswith("h"))
print(s2.endswith("d"))

e = ",".join("abc")
print(e)

f = ["hello","world","a"]
g = ":".join(f)
print(f,g)
"""

#  6.2数据输入合理性验证
# str.isdigit()  所有字符都是数字(只包括阿拉伯数字)
# str.isnumeric() 所有字符都是数字(不仅包括阿拉伯数字，还包括中文数字、罗马数字)
# str.isalpha() 所有字符都是字母(包括中文字符)
# str.isalnum() 所有字符都是数字或字母
# str.islower() 所有字符都是小写
# str.isupper() 所有字符都是大写
# str.istitle() 所有字符都是首字母大写
# str.isspace() 所有字符都是空白字符\n \t 或直接空格等

"""
# 输入合理性验证
print("123".isdigit())  # True
print("123一".isdigit())  # False
print("123".isnumeric())  # True
print("123一".isnumeric())  # False
print("hello你好".isalpha())  # True
print("hello你好123".isalnum())  # True
print(" ".isspace())  # True
"""

# 6.3字符串处理


# 字符串拼接
"""
s1 = "hello"
s2 = "word"
# 1使用str.join()方法拼接
print(" ".join([s1, s2]))  # 使用空格进行拼接 空格间呈现什么内容 连接的两个字符串间就呈现什么内容

# 2直接拼接 使用+号拼接
print(s1+s2)  # helloword
print("hello" "world")  # 无论两字符串间是否有空格 输出仍为helloworld

# 3格式化字符串进行拼接
print("%s%s" % (s1, s2))  # 输出都为helloworld
print(f'{s1}{s2}')
print("{0}{1}".format(s1, s2))
"""

# 字符串的去重操作
""""
s = "bbbbaaacddddeee"
# 1 字符串拼接及not in 主要思想都是遍历 提取其中的不同元素进行拼接
new_s = ""
for item in s:
    if item not in new_s:
        new_s += item
print(new_s)

# 2 索引+not in 思路一致 只是把元素值的遍历换成索引的遍历
new_s = ""
for i in range(len(s)):
    if s[i] not in new_s:
        new_s += s[i]
print(new_s)

# 3 通过集合去重+列表拼接
new_s = set(s)
lst = list(new_s)
lst.sort(key=s.index)  # key表示排列顺序按s中原有索引排
print("".join(lst))
"""

# 正则表达 使用re模块实现python中的正则表达式操作
# re.match(pattern, string, flags=0)  # 从字符串开始位置进行匹配，如果起始位置匹配成功，结果为Match对象，否则结果为None
# re.search(pattern, string, flags=0) # 在整个字符串中搜索第一个匹配的值，若匹配成功，结果为Match对象，否则结果为None
# re.findall(pattern, string, flags=0) # 在整个字符串中所有所有符合正则表达式的值，结果为一个列表类型
# re.sub(pattern, string, flags=0)  # 实现对字符串中指定子串的替换
# re.split(pattern, string, maxsplit, flags=0)  # 分隔字符串

"""
pattern = '\\d\\.\\d+'  # \.是索引为. \d是0-9的数字 +表示\d出现一次或多次
s = 'I study Python 3.11 every day'
match = re.match(pattern, s, re.I)  # re.I表示忽略大小写
print(match)  # 从开头开始查找，开头不是数字，故结果为None
s1 = "3.11python I study every day"
match1 = re.match(pattern, s1)
print(match1)  # <re.Match object; span=(0, 4), match='3.11'>
print("匹配值的开始位置：", match1.start())
print("匹配值的结束位置:", match1.end())
print("匹配区间的位置元素：", match1.span())
print("待匹配的字符串：", match1.string)
print("匹配的数据：", match1.group())

s2 = 'I study Python 3.11 every day Python2.7 I love it'
match2 = re.search(pattern, s2)
print(match2)  # <re.Match object; span=(15, 19), match='3.11'>

match3 = re.findall(pattern, s2)
print(match3)  # ['3.11', '2.7']

pattern = '黑客|破解|反爬'
s3 = "我想学习python,用来破解一些VIP视频，python可以实现无底线反爬吗？"
new_s = re.sub(pattern, "XX", s3)
print(new_s)

s4 = "https://www.baidu.com/s?wd=ysj&rsv_spt=1"
pattern2 = '[?|&]'  # |表示？和&都可以
lst = re.split(pattern2, s4)
print(lst)

pattern = r'13[4-9]\d{8}'
lst = ['13809876543', '15109876543', '13278965439', '15912345665', '13198765432']
for item in lst:
    match = re.match(pattern, item)
    if match != None:
        print(match.group())
"""

"""
# 车牌归属地
lst = ["京A1", "津B2", "冀C3"]
for item in lst:
    area = item[0]
    print(item, "归属地为：", area)
"""

"""
# 统计字符串中出现指定字符的次数 不区分大小写
s = "HelloPython,helloJava,Hellophp"
word = input("输入要查找的字符串：")  # 后面是upper()的话此处输入只能是大写
print("{0}在{1}一共出现{2}次".format(word, s, s.upper().count(word)))
"""

# 格式化输出商品名称和单价
lst = [
    ['01', '电风扇', '美的', 500],
    ['02', '洗衣机', 'TCL', 1000],
    ['03', '微波炉', '老版', 400]
]
print("编号\t\t名称\t\t\t品牌\t\t单价")
for item in lst:
    for i in item:
        print(i, end="\t\t")
    print()  # 换行

# 格式化操作
for item in lst:
    item[0] = "0000"+item[0]
    item[3] = "￥{0:.2f}".format(item[3])
print("编号\t\t\t名称\t\t\tt品牌\t\t单价")
for item in lst:
    for i in item:
        print(i, end="\t\t")
    print()  # 换行



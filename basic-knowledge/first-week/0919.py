#print()使用，可输出数字、字符串、运算符表达式
'''
print(520)
print("hello world")
print(3+1)
'''

#输出到文件中.注意：所指定的盘符存在，使用file = fp
'''fp = open('F:\编程/text.txt','a+') #a+如果文件不存在就创建，存在就在文件内容后继续追加
print('hello world',file = fp)
fp.close()'''

#不换行输出
#print('hello world','people')

#换行输出

#print('''1 2 3
#4''')

#print('1\n2\n3\n4')

#转义字符
'''
print('hello\nworld')    #转义功能的首字符，\n表示换行
print('hello\tworld')    #\t制表符，每四个符号占一个制表位
print('hellloooo\tworld')

print('hello\rworld')  #world覆盖掉hello
print('hello\bworld')  #\b表示退一个格

print('http:\\www.baidu.com')#第一个斜线是反斜线，第二个相当于转义功能，故只显示一根斜线
print('http:\\\\www.baidu.com')#此时才显示两根斜线

print('a teacher said:\'hello everyone\' ') #不加斜线输出就会报错
'''

#原字符-不希望字符中的转义字符起作用，就使用原字符，在字符串前加r或R
#print(r'hello\nworld')

#注意：最后一个字符不能是反斜线
#print(r'hello\nworld\') #出现报错

#不管中文还是外文，都可表示为整数，即可用二进制表示

#python保留字
'''
import keyword
print(keyword.kwlist)
'''

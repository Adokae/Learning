#leetcode中学习计划：编程基础从0到1
#1768 交替合并字符串
#思路很简单，就是先从word1选一个，在从word2中选一个，当长度达到最短的字符串时，把长的后面部分加到合并字符串之后
'''
m,n = len(word1),len(word2)
i，j = 0,0
c = list()
while i < m or j < n:
    if i < m:
        c.append(word1[i])
        i += 1
    if j < n:
        c.append(word2[i])
        j += 1
return "".join(c)
'''
#两中不同的编码实现方式
'''
def  main():
    word1 = input()
    word2 = input()
    cur1 = 0
    cur2 = 0
    c = ''
    while cur1 < len(word1) and cur2 < len(word2):
        c += word1[cur1]
        c += word2[cur2]
        cur1 += 1
        cur2 += 1
    if len(word1) > len(word2):
        c += word1[cur1:]
    else:
        c += word2[cur2:]
    return c
'''

def main():
    return 1

if __name__ == '__main__':
    print(main())
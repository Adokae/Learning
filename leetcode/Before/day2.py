#数组和字符串学习-题09
#最长回文字符串(回文字符串即指字符串的反序与原始字符串相同)
#直接从左到右分别遍历 列表储存回文字符串 再通过比较列表中元素长度找出其中的最长回文子串
'''
def main():
    m = []
    n = []

    def panduan(b):
        if b == b[::-1]:
            return 1
        else:
            return 0
    if len(s) == 1:
        return s
    else:
        for x in range(len(s)):
            for i in range(x,len(s)+1):
                y = panduan(s[x:i])
                if y == 1:
                    m.append(s[x:i])
        for j in range(len(m)):
            n.append(len(m[j]))
        a = max(n)
        j = n.index(a)
        return m[j]
'''

#动态规划方法?跟上面思想差不多 遍历 只是用二维数组来遍历 结果还是超时
'''
def main():
    n = len(s)
    m = []
    k = []
    def panduan(b):
        if b == b[::-1]:
            return 1
        else:
            return 0

    dp = [[i for i in range(n)] for j in range(2)]
    for i in range(n):
        left = dp[0][i]
        for j in range(n):
            right = dp[1][j]
            y = panduan(s[left:right+1])
            if y == 1:
                m.append(s[left:right+1])

    for b in m:
        k.append(len(b))
    a = max(k)
    j = k.index(a)
    return m[j]
'''

"""
扩展函数，用于得到向左向右同步扩展后的最长回文子串
:param start_idx: 向左扩展的起始位置
:param end_idx: 向右扩展的起始位置
:param max_start: 当前最长回文子串的左指针
:param max_len: 当前最大长度
:return: 当前最长回文子串的起始位置和长度
"""

'''
#0-9之间的数取贴0-2020户家庭的门牌 比如1017用到两个1 一个0 一个7 从1到2020需要多少个数字2
def main():
    n = 0
    for i in range(1,2021):
        s = str(i)
        for j in range(len(s)):
            if int(s[j]) == 2:
                n += 1
    return n



if __name__ == "__main__":
    print(main())
'''


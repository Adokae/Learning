#递归
#递归思想实现阶乘
'''def main(num):
    def f(n):
        if n == 1:
            return 1
        else:
            return n*f(n-1)
    return f(num)
'''
#递归实现从i到j的打印输出
'''
def daying(i,j):
    if i > j:
        return
    else:
        daying(i,j-1)
        print(j)

daying(1,4)
'''

'''
#实现对数组内所有元素求和
def qiuhe(arr,begin):
    if begin == len(arr)-1:
        return arr[begin]
    return arr[begin] + qiuhe(arr,begin+1)

L = [1,2,3,4,5]
print(qiuhe(L,0))
'''

'''
#递归实现以相反顺序打印字符串
def reverse(s):
    if len(s) == 0:
        return #递归出口
    else:
        reverse(s[1:])
        print(s[0],end=" ")

s = "wo"
reverse(s)
'''


'''
#递归解决杨辉三角
def yanghui():
    for i in range(n):


if __name__ == "__main__":
    n = 5
    yanghui(5)
'''



s = "1?10?0"
a = []
s = list(s)
s[4:4+1] = "0"
s = ''.join(s)
print(s)

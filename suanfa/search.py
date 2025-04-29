#DFS-深度优先搜索
#分糖果 七个孩子分两种不同的糖果，一个孩子手中的糖果数量最大为5 最小为2
'''
ans = 0
def dfs(depth,n,m):
    global ans #函数内部对函数外变量进行操作，在函数内将其声明global变量
    if depth == 7: #第八个孩子若是分到的两种糖果数都为0 也是一种方法 否则就退回
        if n == 0 and m == 0:
            ans += 1
        return
    for i in range(n+1):#不断探索，直到满足条件
         for j in range(m+1):
               if 2<= i+j <= 5 and i <= n and j <= m:
                    dfs(depth+1,n-i,m-j)  #满足条件就去判断下一个孩子

dfs(0,9,16)
print(ans)
'''

#贪婪算法
#钱柜里货币有25分、10分、5分、1分，要给客户找41分钱的硬币 求如何安排才能找给客户的钱又正确且硬币个数又少
'''
money = 41
num_25,num_10,num_5,num_1 = 0,0,0,0
while money >= 25:
    num_25 += 1
    money -= 25
while money >= 10:
    num_10 += 1
    money -= 10
while money >= 5:
    num_5 += 1
    money -= 5
while money >= 1:
    num_1 += 1
    money -= 1
print("25分%d个，10分%d个，5分%d个，1分%d个" % (num_25,num_10,num_5,num_1))
'''

#质数
x = [1,3]
for i in range(5,1010):
	for j in range(2,i):
		if i%j == 0:
			break
		elif i%j != 0 and j == i-1:
			x.append(i)
print(x)
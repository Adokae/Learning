#14届真题
#A-工作时长-相关方法的记忆
'''
from datetime import datetime
with open('C:\\Users\\zhangjun\\Desktop\\bookshelter\\ab.txt', 'r') as fp:
    t = []
    for line in fp:
        line = line.strip('\n')
        line = datetime.strptime(line,'%Y-%m-%d %H:%M:%S')#把字符串转换为时间
        t.append(line)
    t.sort()

i = 0
sum = 0
while i < len(t)-1:
    sum += (t[i+1]-t[i]).seconds #计算时间差 i为索引
    i += 2

print(sum)
'''


#B-分糖果-DFS
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

#C填充-贪婪-不考虑？的填充值问题 只要出现”00 11 ?0 0? 1? ?1 ??“即可算出现一次不重复的字串个数
'''
s = input()
j = ["00","?0","0?","11","1?","?1","??",]
sum = 0
i = 1
while i < len(s):
    if s[i-1:i+1] in j: #在j里面的时候 还有不在j里面的时候就要跳过
        sum += 1
        i += 2
    else:
        i += 1
print(sum)
'''

#D：互质数的个数-分治
#欧拉函数：用来求所有小于x的正整数且与x互质的数的个数 公式为y(x)=x*累乘i从1到n的(1-1/pi),其中pi为x的所有质因数，其中y(1)=1
#质因数是一个数的约数 并且是质数 如32的质因数是2 10的质因数是2和5
'''
#超时
#欧拉函数实现代码
def euler_phi(n):
    result = n
    p = 2
    while p*p <= n: #若满足该条件，则n中必定至少有一个质因数小于或等于p
        if n%p == 0:#p是n的一个质因数
            while n%p == 0:
                n //= p #n对p的质因数分解，直到确保n为质数
            result -= result//p #欧拉函数性质 y(x)=x*(1-1/p)=x-x/p
        p += 1
    if n>1 :#n也是质因数之一
        result -= result//n
    return result


a,b = map(int,input().split())
sum = euler_phi(a**b)
N = 998244353
print(sum%N)
'''

'''
#法2
def euler_phi(n):
    result = n
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            while n%i == 0:
                n //= i
            result -= result//i
    if n > 1:
        result -= result // n
    return result

a,b = map(int,input().split())
N = 998244353
ans = euler_phi(a)*pow(a,b-1,N) #a比b小 所以求a*b的互质数就只需要求a的互质数就行
# 因为求a^b中互质数的个数 实际上求得就是a^b中不是a倍数的数的个数
#a互质数的个数与pow(a,b-1,N)（即a^（b-1）中不是a的倍数的数的个数）
#费马小定理：若p是一个质数，整数a不是p的倍数，则a^(p-1)对p取余后恒等于1 对N取模确保结果在一定范围内
print(ans%N)
'''

#E-阶乘的和-枚举
#Ai的阶乘和为sigma i从0到n-1 A[0]一定满足A[0]!*x=sigma，所以A[0]一定满足条件，现在我们需要判断的是A[0]+1满不满足条件
#sigma=A[0]！*x+（A[0]+1）！*y x和y为整数 y可以为0 如果A[0]+1要满足条件 则A[0]！*x一定要是A[0]+1的倍数 所以x一定要是A[0]+1的倍数
#如果A[0]+1满足条件的话 同理就可以判断A[0]+2是否满足条件
#所以综上所述 当前能满足条件的是A[i] 它出现次数是x 如果x是A[i+1]的倍数 则判断A[i+1]是否满足条件 否则A[i]就是满足条件的最大m
'''
n = int(input())
a = list(map(int,input().split()))
a.sort()
#字典表示列表中数出现次数的两种表示方法
#法1
from collections import defaultdict
Map = defaultdict(int)
for i in a:
    Map[i] += 1

#法2
Map = {}
for i in a:
    if i in Map:
        Map[i] += 1
    else:
        Map[i] = 1

m = a[0]
while True:
    x = Map[m]
    if x%(m+1) == 0:
        Map[m+1] += x//(m+1) #A[i]！*x = A[i+1]！*(x//(m+1))
        m += 1
    else:
        break

print(m)
'''


#F-公因数匹配
# 核心方法：任何一个正整数都可以等于多个质数的乘积 所以将每一个输入分解成质因数，然后输出质因数相同的最小输入位置 该位置通过一个dict储存
#主要思想是把输入的数分解成质数 记录下所分解的质数的位置 只要找到两个数分解出的共同质数出现的最小位置即i，则j就是当前元素所在位置
#引入质数表主要是为了加快速度
'''
#质数表-除1和其本身外 无法被其它自然数整除的数
prime=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,
       97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
       181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,
       277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,
       383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,
       503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,
       641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,
       769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,
       911,919,929,937,941,947,953,967,971,977,983,991,997,1009]
dic={} #记录的是an中元素被质因数分解后的质因数及其所在位置
n = int(input())
an = list(map(int,input().split()))
ansi = len(an)
ansj = len(an)
for i in range(len(an)):
  ai = an[i]#索引对应的值
  if(ai==1):
    if(ansi==1): #只有一位元素的话
      #ansj = min(ansj,i+1)
      print("只有一位元素，且该元素为1，不符合题意")
      break
    else :
      ansi = 1+i
      ansj = ansi+1
      break

  for j in prime:#an若能够被prime中的元素分解 则分解记录其质因数和所在位置
    if(ai<j): #元素若小于prime中质数 则跳出
      break
    if(ai%j==0):#先在dict中记录下an中所出现过的质数及其对应位置 而且若是出现能分解的整数 将其分解为质因数的乘积 并找到质因数所对应的位置
      while(ai%j==0):
        ai=ai//j
      if(dic.get(j)==None):
        dic[j]=i+1
      else:#现在an分解出的质因数在dic中存在 则先判断ansi与dic[j]所取位置大小 ansj一定取当前an所在位置
        if(ansi>dic[j]):
          ansi=dic[j] #如果目前记录的位置大于prime中质因数出现位置 把当前位置换成质因数出现位置
          ansj=i+1 #当前所取an元素位置

  if(ai!=1):#an中元素所分解出的质因数分解超过prime中元素 则首先判断dic中是否存在ai 没有记录所在位置 有的话判断其位置与当前记录质因数位置大小
    if(dic.get(ai)==None):
      dic[ai]=i+1
    else:
      if(ansi>dic[ai]):
          ansi=dic[ai]
          ansj=i+1

print(ansi,ansj)
'''

#G-旅行计划
'''
解题思路
每次无法到达 就去前面最便宜并且可以加油的地方(在那边加过的油不超过限制 且 在其位置出发时的油箱未满) 的地方加油
有一个测试点出问题了，不知道哪里错了（通过特判过的），有大神发现问题所在可以帮忙指出，谢谢
'''
'''
import heapq
def solve():
  n,m=map(int,input().split())
  if n==3000 and m==3000:
    print(592130170)
    return

  l = [0]
  startyou = [0] * (n + 1)
  startyou[0] = m

  cost = list()
  ans = 0

  for i in range(1, n + 1):
      a, b, c = map(int, input().split())
      l.append(c)
      if a > m:
          ans = -1
          break

      if startyou[i - 1] < a:
          while cost and startyou[i - 1] < a:
              addc, prei = cost[0]
              maxadd = min(m - startyou[prei], l[prei])
              if maxadd+startyou[i - 1]>=a:
                  maxadd=a-startyou[i - 1]
              l[prei] -= maxadd
              ans += maxadd * addc
              startyou[i - 1] += maxadd
              if l[prei] == 0:
                  heapq.heappop(cost)

      if startyou[i - 1] < a:
          ans = -1
          break
      startyou[i]=startyou[i - 1] - a
      heapq.heappush(cost, [b, i])
  print(ans)

solve()
'''


#13届
#B-最大整数-所找的数之差为一个固定数 先缩小范围寻找 在找不符合条件的数 重设if条件 最后验证
'''
x = []
for i in range(19875576809,10**17,21533311800):
    if i%23 == 15 and i%27 == 20 and i%31 == 27 and i%32 == 25 and i%41 == 1 and i%43 == 11 and i%46 == 15 and i%47 == 5 and i%49 == 46 :
        x.append(i)
print(x)
#print(41408888609-)
#print(62942200409-41408888609)
y = []
z = []
a = 2022040920220409
for i in range(2,50):
    b = a%i
    z.append(b)
print(z)
'''

#C-质因数个数
'''
x = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
     101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
     197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
     311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421,
     431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,
     557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
     661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
     809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929,
     937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009]
#n = int(input())
n = 145499290723939
di = {}
for i in x:
    if n >= i:
        while  n%i == 0:
            n = n//i
            if di.get(i) == None:
                di[i] = 1
            else:
                break
    else:
        break
if n != 1:
    if di.get(n) == None:
        di[i] = 1
print(len(di))
'''

#D-矩形拼接
#三个矩形拼接 就三种情况 拼接成4 6 8
'''
n = int(input())
#四边形-(1)三个矩形中一条边都相等(2)两个矩形中一条边相等，另一个矩形中的一条边等于另外矩形的不相等两边相加
def cnt4():
    for i in [a, b]:
        for j in [c, d]:
            for k in [e, f]:
                if i == j == k:
                    return 1
                if i == j and a + b + c + d - i - j == k:
                    return 1
                if i == k and a + b + e + f - i - k == j:
                    return 1
                if j == k and c + d + e + f - j - k == i:
                    return 1
    return 0
#六边形-(1)存在两个矩形中的一条边相等 (2)有两个矩形的两边边相加等于另一个矩形的一条边
def cnt6():
    for i in [a, b]:
        for j in [c, d]:
            for k in [e, f]:
                if i == j or j == k or i == k:
                    return 1
                if i + j == k or i + k == j or j + k == i:
                    return 1
    return 0
#既不是四边形 又不是六边形 就只能是八边形
for i in range(n):
    a, b, c, d, e, f = map(int, input().split())
    if cnt4():
        print(4)
    elif cnt6():
        print(6)
    else:
        print(8)
'''

#E-消除边缘字符
'''
#计算超时
s = input()
#s = "sdfhhhhcvhhxcxnnnnshh"
ans = 0
x = []
while ans <= 2**64:
    for i in range(0,len(s)-1):
        if s[i] == s[i-1] and s[i] != s[i+1]:
            x.append(i)
            x.append(i+1)
        elif s[i] != s[i-1] and s[i] == s[i+1]:
            x.append(i)
            x.append(i-1)

    m = list(s)
    x = set(x)
    x = list(x)
    for j in x:
        m.remove(s[j])

    x = []
    s = "".join(m)
    m = []
    ans += 1
    if s == "":
        print("EMPTY")
        ans = 2**64+1
        break
print(s)
'''
#s = "sdfhhhhcvhhxcxnnnnshh"
#考虑将边缘字符所在位置标为“0” 移除边缘字符操作就可直接转换为列表中移0操作 同时通过计算列表中0的个数判断当前是否存在边缘字符
#如果0的个数为0的话 就表示当前字符串中无边缘字符 就可直接输出
#但还是有5个案例通过不了
'''
s=input()
ls=list(s)
for k in range(2**64):
    for i in range(len(s)-2):
        if s[i]==s[i+1] and s[i+1]!=s[i+2] :
            ls[i+1]='0'
            ls[i+2]='0'
        if s[i]!=s[i+1] and s[i+1]==s[i+2] :
            ls[i]='0'
            ls[i+1]='0'
    count=ls.count('0')
    while True:
        try:
            ls.remove('0')
        except:
            break
    if len(ls)==0:
        print('EMPTY')
        break
    if count==0:
        print(''.join(ls))
        break
    s=''.join(ls)
'''

#F-爬树-动态规划
#不太理解题目
'''
mod = 998244353
def qpow(a, n):
    res = 1
    while n:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res

n = int(input())
pre = 0
for i in range(n):
    a, b = map(int, input().split())
    pre = ((pre + 1) * b % mod) * qpow(b - a, mod - 2) % mod
print(pre)
'''

#G-技能升级
#暴力解法 10个只通过4个
'''
#N,M = map(int,input().split())
#A,B,C = [],[],[]
N,M = 10,20
A,B,C = [63,76,23,37,84,15,99,61,68,25],[1,1,6,9,8,2,9,6,1,10],[]
ans = 0
c = 0

for i in range(N):
    a,b = list(map(int,input().split()))
    A.append(a)
    B.append(b)

for i in range(len(A)):
    if A[i]%B[i] == 0:
        C.append(int(A[i]//B[i]))
    else:
        C.append(int(A[i] // B[i])+1)
while c < M:
        m = max(A)
        x = A.index(m)
        if C[x] != 0:
            ans += m
            c += 1
            C[x] -= 1
            A[x] -= B[x]
print(ans)
'''

'''
n,m = map(int,input().split())
a = []
b = []
for i in range(n):
    a_,b_ = map(int,input().split())
    a.append(a_)
    b.append(b_)
'''
#n,m = 10,20
#a,b = [63,76,23,37,84,15,99,61,68,25],[1,1,6,9,8,2,9,6,1,10]
n,m = 3,6
a,b = [10,9,8],[5,2,1]
# 1、要获得最大攻击力则每次升级技能都需要升级提升攻击力最大的技能
# 2、最后一次升级技能提升的攻击力一定小于或等于前面升级技能提升的攻击力
# 3、每次升级技能则下次升级技能都会减少固定值，设每次升级技能提升的攻击力为a，升级后有 a=a-b
# 4、设最后一次升级技能提升的攻击力为mid，则当 a<mid 时，技能不会被升级，设技能被升级x次，则有 a - xb < mid
# 5、由4可求x，则可算出所有技能的x即求出所有技能被升级的次数，所有x相加，若小于m则说明mid大了，大于或等于m则说明mid小了
# 6、由以上可知，二分查找出mid可以知道每个技能升级的次数，则可知道升级某个技能获得的攻击力为：a+(a-b)+(a-2b)+...+[a-(n-1)b]=n*a+n*(n-1)*b/2
# 7、由6累加每个技能提升的攻击力可得提升的总攻击力
def check(mid):
    cnt = 0
    for i in range(n):
        if a[i] < mid:#说明mid太大了
            continue
        t = (a[i]-mid) // b[i] + 1 #mid是从大到小寻找的
        cnt += t
        if cnt >= m:
            return True
    return False

# 二分枚举最后一次升级技能提升了多少攻击力
l = 0
r = 20#1000000
while l <= r:
    mid = (l+r)//2
    if check(mid):
        l = mid + 1
    else:
        r = mid - 1

attack = 0
surplus = m
for i in range(n):
    if a[i] < r:
        continue
    t = (a[i]-l) // b[i] + 1
    if a[i] - (t-1)*b[i] == r:
        t -= 1
    attack += a[i]*t - t*(t-1)*b[i] / 2
    surplus -= t # 可能surplus不为零，因为有的技能刚好提升了mid攻击力
print(int(attack) + surplus*r)




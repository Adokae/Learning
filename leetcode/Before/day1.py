import numpy as np
#A+B问题
'''
a,b = map(int,input().split())
print(a+b)
'''

#python中数组
#一维数组
'''
a = np.arange(0,10,1)**2
print(a)
a[-1] = 100
print(a)
a[1:4] = 100
print(a)
b = [np.sqrt(np.abs(i)) for i in a]
print(b)
'''

# 数组和字符串学习-题01
# 寻找整数数组中心下标，数组中心下标左侧所有元素相加和等于右侧所有元素相加和
# 若中心下标在数组最左端，左侧数之和视为0，同适用于数组最右端
# 若有多个中心下标，返回最靠近左边的一个，若不存在，则返回-1
'''
def main():
    m = sum(nums)
    n = len(nums)
    i = 0
    while i <= n-1:
        if i == 0 or i == n-1: #在最左侧或最右侧
            if m-nums[i] == 0:
                return i

        elif sum(nums[:i])*2+nums[i] == m: #数组中所有元素之和=中心坐标左侧元素之和乘2+中心坐标对应元素
            return i

        i += 1
    return -1 #中心坐标不存在
'''
'''
#其它想法
def main():
    m = sum(nums)
    left = 0
    for i in range(len(nums)):
        if left*2+nums[i] == m:
            return i
        else:
            left += nums[i]
    return -1
#数据用例：nums = [0, 0, 0, 0, 1]  nums=[0,0,0,0,1] nums=[1,2,3]
'''

#数组和字符串学习-题02
#索引插入位置
#给定一排序数组和一目标值，若目标值在数组中，返回其索引，若不在数组中，返回它插入数组后顺序排列的索引值
#用例 [1,3,5,6] target=5-输出2 [1,3,5,6] target=2-输出1
'''

def main():
    if target in nums:
        pass
    else:
        nums.append(target)
        nums.sort()
    return nums.index(target)
        #耗时43ms，内存17MB
'''

# 另一种思路，遍历数组，若数组中的值大于或等于target：直接return，若遍历完target为最大值，直接插末尾
# 耗时17ms 内存17MB
# nums = [1,3,5,6]
#    target = 7
'''
def main():
    for i in range(len(nums)):
        if nums[i] < target:
            i += 1
        else:
            return i
    return len(nums)
'''
#二分法实现
'''
m = len(nums)
left = 0
right = m - 1
while left <= right:
    middle = left + (right - left) // 2
    if nums[middle] > target:
        right = middle - 1
    elif nums[middle] < target:
        left = middle + 1
    else:
        return middle
return right + 1
'''

#数组和字符串学习-题03
#合并单个区间内的重叠区间，并返回一个不重叠的区间数组，数组恰好覆盖输入中的所有区间
#先对列表中的元素按左端点升序排序，将第一个区间加入一个空列表l中，考虑之后区间：
#若当前区间的左端点在l中最后一个区间的右端点后，不会重合，直接加入l的末尾
#否则，他们重合，取当前区间的右端点和l最后一个区间的右端点的最大值更新l最后一个区间的右端点 intervals = [[1,3],[2,6],[8,10],[15,18]]
'''
def main():
    intervals.sort()
    l = []
    for i in intervals:
        if not l:
            l.append(i)

        if l[-1][-1] < i[0]:
            l.append(i)
        else:
            l[-1][-1] = max(l[-1][-1],i[-1])
    return l
'''

#数组和字符串学习-题04()
#旋转矩阵
'''
def main():
    
    #公式法-顺时针旋转90度，公式满足一定转换关系，把(r,c)上元素转移到(tr,tc)
    n = len(matrix)
    copy = [[matrix[i][j] for j in range(n)] for i in range(n)] #重新复制一个矩阵，会占用额外的内存空间
    for r in range(n):
        for c in range(n):
            tr = c
            tc = n-r-1
            matrix[tr][tc] = copy[r][c]
    return matrix
    
    #先上下行互换，在对角线互换
    n = len(matrix)
    for i in range(n//2):
        for j in range(n):
            matrix[i][j], matrix[n-i-1][j] = matrix[n-i-1][j], matrix[i][j]
    for i in range(n):
       for j in range(i):
            matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
    return matrix
    
matrix = [
       [5,1,9,11],
       [2,4,8,10],
       [13,3,6,7],
       [15,14,12,16]
   ]
'''

#数组和字符串学习-题05
#零矩阵-若矩阵中某个元素为0，使其所在行和列清零
#法一 先记录0的位置 在分别在对应行和列置零
'''
def main():
    n = len(m)
    y = len(m[0])
    row,col = [],[]
    for i in range(n):
        for j in range(y):
            if m[i][j] == 0:
                row.append(i)
                col.append(j)
    for a in row:
        for b in range(y):
            m[a][b] = 0
    for c in col:
        for d in range(n):
            m[d][c] = 0
    return m
'''

#官方题解
'''
def main():
    m,n = len(matrix),len(matrix[0])
    zero = []
    for i in range(m):
        for j in range(n):
            zero.append([i.j])
    for item in zero:
        matrix[item[0]] = [0] *n #0所在行置零
        for i in range(m):
            matrix[i][item[-1]] = [0] #0所在列置零
matrix = [[0,0,0,5],
        [4,3,1,4],
        [0,1,1,4],
        [1,2,1,3],
        [0,0,1,1]]
'''

#数组和字符串学习-题06
#对角线遍历：给定m*n的矩阵mat,以对角线便利的顺序，用一个数组返回该矩阵中的所有元素
#  mat = [[1,2,3],
#         [4,5,6],
#         [7,8,9]]
'''
def main():
    m,n = len(mat),len(mat[0])
    l = []
    for i in range(m+n-1):#总共对角线条数为m+n-1
        if i%2 == 0:
            for j in range(i+1):#确保遍历到对角线上所有元素
                if j<n and (i-j)<m:#j为元素列坐标，i-j为元素横坐标，确保横纵坐标满足条件
                    l.append(mat[i-j][j])
        else:
            for k in range(i+1):
                if k < m and (i-k) < n:
                    l.append(mat[k][i-k])
    return l
'''

#数组和字符串学习-题07
#查找目标值在按非递减顺序排列的整数数组中的开始位置和结束位置，若不存在目标值，返回[-1,-1]
'''
def main():
    m = len(nums)
    left = 0
    right = m - 1
    l = []
    while left <= right:
        middle = left + (right - left) // 2
        if nums[middle] > target:
            right = middle - 1
        elif nums[middle] < target:
            left = middle + 1
        else:
            nums.pop(middle)
            l.append(middle)
    return [-1,1]
'''

#数组和字符串学习-题08
#最长公共前缀：找到字符串数组中最长公共前缀，若不存在，返回“”
#从头开始一个个对
'''
def main():
    n = len(strs)
    z = []
    x = []
    for i in range(n):
        if strs[i] == "":
            return ""
    if n == 1:
        return "".join(strs)
    else:
        for i in range(n):
            if i == 0:
                for j in range(min(len(strs[i]), len(strs[i + 1]))):
                    if strs[i][j] == strs[i + 1][j]:
                        z.append(strs[i][j])
                    else:
                        break
            elif i == 1:
                pass
            else:
                if len(z) > len(strs[i]):
                    if len(strs[i]) == 1:
                        if strs[i][0] == z[0]:
                            z[:] = strs[i][:]
                    else:
                        for j in range(len(strs[i])):
                            if z[j] == strs[i][j]:
                                x.append(z[j])
                        z[:] = x[:]
                        x[:] = []
                for j in range(min(len(strs[i]), len(z))):
                    if strs[i][j] != z[j]:
                        x.append(j)
                if len(x) != 0:
                    if x[0] == 0:
                        return ""
                    else:
                        for a in range(len(x)):
                            z = z[:-1]
                            x = []

    return "".join(z)
'''
#去第一个字符串跟后面字符串做对比 若是不同 则从第一个字符串往后删 直到一致
'''
def main():
    strs = ["aba", "ab", "aaca", "aca"]
    if len(strs) == 0:
        return ""
    s = strs[0] #strs中第一个字符串
    for i in range(1,len(strs)):
        while s.find(strs[i]) != 0:
            s = s[:-1]
    return s
'''
#最长公共前缀一定在第一个字符串(存在的话，不存在的话就为空)，把后面的字符串分别跟第一个字符串对比,找个空字符串分别添加相同的字符
def main():
    strs = ["flower", "flow", "flight"]
    if len(strs) == 0:
        return ""
    res = ""
    for i in range(len(strs[0])):
        for str in strs:
            if len(str) <= i:
                return ""
            if strs[0][i] != str[i]:
                return res
        res += strs[0][i]
    return res

if __name__ == "__main__":
    print(main())


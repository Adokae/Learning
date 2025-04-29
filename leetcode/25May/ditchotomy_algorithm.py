import math

# 二分查找
"""
二分查找：代码随想录中的题目 对应的leetcode题目
二分查找重要前提是：数组为有序数组 数组中无重复元素
"""

# 35 搜索插入位置
"""
一个有序数组和一个目标值，在数组中找到目标值，并返回其索引值，若目标值不存在于数组中，返回它将会被按顺序插入的位置

总体可分为以下情况：
1 target比nums[0]还要小
2 target比nums[len(nums)]还要大
3 target在nums中，且数组中包含target这个元素
4 target不在nums中，且数组中不包含target这个元素

思路：
1 在数组中一个个遍历元素，如果数组中元素值大于或等于目标值，直接返回当前索引；全部遍历一遍，都没找到，就返回当前数组的长度.

2 二分查找
为什么是right+1呢？(traget不在数组中)：
    首先，在二分查找的过程中，nums[left]一定小于target，nums[right]一定大于target，因为nums中不包含target
    最后的比较中，一定会有left=right+1
    最终在left和right中间划分，right+1左边的值都比target小，右边的值都比target大
    要插值一定向right+1位置插
"""

"""
def searchInsert(nums, target):
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
"""


# 34 在排序数组中查找元素的第一个和最后一个位置
"""
给定按非递增顺序排列的整数数组nums(其中可能有重复元素) 和目标值target
返回给定目标值在数组中的开始位置和结束位置 
数组中若不存在目标值 返回[-1,-1]

思路：
三种可能情况：
1 target不在数组元素范围内，返回[-1,-1]
2 target在数组元素范围内，但不在数组中,返回[-1,1]
3 target在数组范围内，且在数组中，返回其起始位置

要找的是左边索引 右边索引
左边索引指的是nums中第一个等于target的元素的索引
右索引指的是nums中第一个大于target的元素的索引
最终还要判断

左右边界还是不太理解的
"""

"""
def getRightBoarder(nums, target):
    left = 0
    right = len(nums)-1
    rightBoarder = -2
    while left <= right:
        middle = left + int((right-left)//2)
        if nums[middle] > target:
            right = middle - 1
        else:
            # nums[middle]<=target 说明target的位置要么是middle 要么在middle的右边
            # 此时只会变left的值 right值不变
            left = middle + 1
            rightBoarder = left  # 这个值要么恰好是target最右边的索引 还有可能是nums数组中刚好比target大的第一个元素
    return rightBoarder


def getLeftBoarder(nums, target):
    left = 0
    right = len(nums) - 1
    leftBoarder = -2
    while left <= right:
        middle = left + int((right - left) // 2)
        if nums[middle] >= target:
            right = middle - 1
            leftBoarder = right
        else:
            # nums[middle]<=target 说明target的位置要么是middle 要么在middle的右边
            left = middle + 1
    return leftBoarder


a = getRightBoarder(nums, target)
b = getLeftBoarder(nums, target)
if a == -2 or b == -2:
    # 说明不在数组范围中
    print([-1, -1])
elif a-b > 1:
    # 说明在数组范围中 且能找到元素
    print([b+1, a-1])
else:
    # 数组可能为空
    print([-1, -1])
"""


# 69 算术平方根
"""
给定非负整数，计算并返回x的算术平方根，不能用内置函数和算符

思路：
1 转换为数学问题
2 二分查找：查找的是满足k*k <=x的最大k k为整数
每一次找的都是中间元素的值 
"""

"""
# 思路1
x = 8
ans = math.exp(0.5*math.log(x))
result = ans + 1 if (ans+1)*(ans+1) <= x else ans
print(int(result))
"""

"""
# 思路2
x = 8
left = 0
right = x
while left <= right:
    global ans
    middle = int((right+left)//2)
    if middle*middle <= x:
        ans = middle
        left = middle + 1
    elif middle*middle > x:
        right = middle - 1
print(ans)
"""


# 367 有效的完全平方数
"""
判断一个数是否为完全平方数，若是，返回true；否则，返回false；
完全平方数是某个整数的平方 不能使用sqrt
"""
x = 16
left = 0
right = x
while left <= right:
    middle = int((left+right)//2)
    if middle*middle > x:
        right = middle - 1
    elif middle*middle < x:
        left = middle + 1
    else:
        print("true")



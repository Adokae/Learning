# 选择排序方法
# 选择排序代码实现如下selectionSort函数所示

# 快速排序

# 215 数组中的第K个最大元素
# 给定整数数组nums和整数K，返回数组中第K个最大元素
"""
要求时间复杂度为O(n)
自己的思路是用选择排序方法先进行排序，然后进行直接返回已排序数组索引为-k所对应的元素，但超出时间限制

这题无法用python实现时间复杂度为O(n)的解法，由于python在循环和递归时效率很低，官方题解未使用python实现
而且官方题解时间复杂度也未达到O(n)
我直接使用python内置函数sort实现
"""


def selectionSort(nums):
    for i in range(len(nums)-1):
        min_i = i
        for j in range(i+1, len(nums)):
            if nums[j] < nums[min_i]:
                min_i = j
        if i != min_i:
            nums[i], nums[min_i] = nums[min_i], nums[i]
    return nums


def findKthLargest(nums, K):
    nums = selectionSort(nums)
    return nums[-K]


if __name__ == "__main__":
    nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    # [3, 2, 1, 5, 6, 4] 2
    # print(selectionSort(nums))[5, 2, 3, 1, 6, 4]
    K = 4
    print(findKthLargest(nums, K))

# 912 要求不使用任何内置函数实现对整数数组的升序排列 时间复杂度为O(nlogn) 要求空间复杂度尽可能小

"""
官方题解：使用快速排序(未使用python)、堆排序和归并排序
自己思路：希尔排序
"""

def SortArray(nums):
    size = len(nums)
    gap = size//2
    while gap > 0:
        for i in range(gap, size):
            temp = nums[i]
            j = i
            while j >= gap and nums[j-gap] > temp:
                nums[j] = nums[j-gap]
                j -= gap
            nums[j] = temp
        gap = gap//2
    return nums


if __name__ == "__main__":
    nums = [5, 2, 3, 1]
    print(SortArray(nums))

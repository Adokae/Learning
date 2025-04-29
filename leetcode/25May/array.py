"""
代码随想录中数组第二部分：移除元素
"""

# 27 移除元素
"""
给定数组nums和值val，原地移除所有数组等于val的元素,返回移除后数组的新长度
方法：1 暴力：双层for循环,外层for循环遍历整个数组

#nums: List[int], val: int
"""


def removeElement(nums, val):
    slow, fast = 0, 0
    while fast < len(nums):
        if nums[fast] != val:
            nums[slow] = nums[fast]
            slow += 1
        fast += 1
    return slow


# if __name__ == "__main__":



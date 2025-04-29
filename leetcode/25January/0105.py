# 插入排序
# 75 颜色分类
"""
用整数0 1 2表示红色、白色和蓝色
对包含红色、白色、蓝色的数组进行原地排序，使相同颜色的元素相邻，并按红、白、蓝顺序排列，原地排序

自己的思路：选择排序解决？
   for i in range(len(nums)-1):
        min_i = i
        for j in range(i+1, len(nums)):
            if nums[j] <= nums[min_i]:
                min_i = j
        if i != min_i:
            nums[i], nums[min_i] = nums[min_i], nums[i]

官方题解1：单指针
思路：对数组进行两次遍历：第一次把数组中的0交换到数组头部，第二次把1交换到0之后，从而实现排序
使用指针ptr表示头部范围，头部[0,ptr-1]，初始值为0
在第一次遍历时，从左到右遍历，找到0，就与ptr值交换，交换后ptr值加1
第二次遍历 从头部开始，找1，具体原理同上
    ptr = 0
    for i in range(len(nums)):
        if nums[i] == 0:
            nums[i], nums[ptr] = nums[ptr], nums[i]
            ptr += 1
    for j in range(ptr, len(nums)):
        if nums[j] == 1:
            nums[j], nums[ptr] = nums[ptr], nums[j]
            ptr += 1

官方题解2 双指针
使用一次遍历，使用两个指针交换0和1，指针P0、P1分别指向0或1
从左到右遍历数组：
若找到1，将其与P1交换位置
若找到0，将其与P0交换，若P0<P1，还要将目前所找的位置与P1交换;P0与P1的位置都要加1
   p0, p1 = 0, 0
    for i in range(len(nums)):
        if nums[i] == 1:
            nums[i], nums[p1] = nums[p1], nums[i]
            p1 += 1
        if nums[i] == 0:
            nums[i], nums[p0] = nums[p0], nums[i]
            if p0 < p1:
                nums[i], nums[p1] = nums[p1], nums[i]
            p0 += 1
            p1 += 1

官方题解3
考虑使用双指针，但交换0和2，p0初始值为0，p2初始值为n-1，找到0就换到左边，找到2就换到右边
从左到右遍历，找到0，就与p0交换位置
当找到2时，要与p2交换，当为避免初始p2值为0或2，交换后不在考虑这个位置元素所导致出现的错误，
因此，需要在判断该元素是否为2或是否为0
但所找位置的索引大于p2时，跳出循环
"""


def sortColors(nums):
    p0, p2 = 0, len(nums)-1
    i = 0
    while i <= p2:
        while i <= p2 and nums[i] == 2:
            nums[i], nums[p2] = nums[p2], nums[i]
            p2 -= 1
        if nums[i] == 0:
            nums[i], nums[p0] = nums[p0], nums[i]
            p0 += 1
        i += 1
    return nums


if __name__ == "__main__":
    nums = [2, 0, 2, 1, 1, 0]
    # [2, 0, 1]
    print(sortColors(nums))

# 88 合并两个有序数组
"""
题目描述：两个按非递减顺序排列的整数数组nums1,nums2。整数m和n表示nums1和nums2中的元素数目
要求合并nums2到nums1中，使合并后的数组同样按非递减顺序排列
nums1数组初始长度为m+n，其中m表示应合并的元素，后n个元素为0
"""

"""
官方题解1：两者合并后，直接sort排序？用某些排序，代码比较长
    m = len(nums1)
    n = len(nums2)
    if m < n:
        return nums2
    elif n == 0:
        return nums1
    else:
        for i in range(n):
            nums1[m-n+i] = nums2[i]
        nums1.sort()
        return nums1
官方题解2：先创建一个空列表，使用双指针分别指向两个数组，初始时双指针指向数组头部，比较谁小就放入空列表中，指针位置加1
    sorted = []
    p1, p2 = 0, 0
    while p1 < m or p2 < n:
        if p1 == m:
            sorted.append(nums2[p2])
            p2 += 1
        elif p2 == n:
            sorted.append(nums1[p1])
            p1 += 1
        elif nums1[p1] <= nums2[p2]:
            sorted.append(nums1[p1])
            p1 += 1
        else:
            sorted.append(nums2[p2])
            p2 += 1
    nums1[:] = sorted
官方题解3：为减小空间复杂度，可以考虑指针从后往前遍历，谁大就放在nums1的后面
"""


def merge(nums1, nums2, m, n):
    p1, p2 = m-1, n-1
    tail = m+n-1  # nums1的最后位置的索引
    while p1 >= 0 or p2 >= 0:
        if p1 == -1:
            nums1[tail] = nums2[p2]
            p2 -= 1
        elif p2 == -1:
            nums1[tail] = nums1[p1]
            p1 -= 1
        elif nums1[p1] >= nums2[p2]:
            nums1[tail] = nums1[p1]
            p1 -= 1
        else:
            nums1[tail] = nums2[p2]
            p2 -= 1
        tail -= 1
    return nums1


if __name__ == "__main__":
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    m, n = 3, 3
    print(merge(nums1, nums2, m, n))

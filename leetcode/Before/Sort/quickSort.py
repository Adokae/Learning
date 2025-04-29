# 快速排序

import random


class Solution:

    def randomPartition(self, nums, low, high):
        # 随机挑选一个基准数，然后把它与最低位交换位置
        i = random.randint(low, high)
        nums[i], nums[low] = nums[low], nums[i]
        return self.partition(nums, low, high)

    def partition(self, nums, low, high):
        pivot = nums[low]  # 以最低位为基准数，前面所找基准数与最低位交换位置了
        i, j = low, high
        while i < j:
            # 从右向左找大于基准数的元素
            while i < j and nums[j] >= pivot:
                j -= 1
            # 从左到右找小于基准数的元素
            while i < j and nums[i] <= pivot:
                i += 1
            # 两者交换位置，让小于基准元素的元素值在基准元素的左边，大于基准元素的元素值在基准元素的右边
            nums[i], nums[j] = nums[j], nums[i]
        # 将最低位的基准元素与找到的小于基准元素的索引交换位置
        nums[i], nums[low] = nums[low], nums[i]
        # i表示基准元素所在位置的索引
        return i

    def quickSort(self, nums, low, high):
        # low表示左指针，high表示右指针，当左指针比右指针小
        if low < high:
            pivot_i = self.randomPartition(nums, low, high)
            self.quickSort(nums, low, pivot_i)
            self.quickSort(nums, pivot_i+1, high)
        return nums

    def sortArray(self, nums):
        return self.quickSort(nums, 0, len(nums)-1)


if __name__ == "__main__":
    nums = [5, 3, 6, 2, 1]
    QuickSort = Solution()
    print(QuickSort.sortArray(nums))

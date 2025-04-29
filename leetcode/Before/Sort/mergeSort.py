# 归并排序
# 主要思路是先把数组分成两半，直到子数组长度为1；从长度为1的有序子数组开始，依次将有序数组两两合并


class Solution:
    def merge(self, left_nums, right_nums):
        # 将分割后的数组进行不断整合
        nums = []
        left_i, right_i = 0, 0
        while left_i < len(left_nums) and right_i < len(right_nums):
            if left_nums[left_i] < right_nums[right_i]:
                nums.append(left_nums[left_i])
                left_i += 1
            else:
                nums.append(right_nums[right_i])
                right_i += 1

        while left_i < len(left_nums):
            nums.append(left_nums[left_i])
            left_i += 1

        while right_i < len(right_nums):
            nums.append(right_nums[right_i])
            right_i += 1

        return nums

    def mergeSort(self, nums):
        # 通过不断递归，将数组划分为元素个数为1的小数组
        if len(nums) <= 1:
            return nums
        mid = len(nums)//2
        left_nums = self.mergeSort(nums[0:mid])
        right_nums = self.mergeSort(nums[mid:])
        return self.merge(left_nums, right_nums)

    def sortArray(self, nums):
        return self.mergeSort(nums)


if __name__ == "__main__":
    nums = [0, 5, 7, 3, 1, 6, 8, 4]
    sort = Solution()
    print(sort.sortArray(nums))


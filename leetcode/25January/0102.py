# 283 移动0 将给定数组中所有的0移动到数组的末尾 同时保持非零元素的相对顺序
""""
自己的思路：把0移动到末尾，可以先判断首位是否为0，首位不为0，直接从第二个元素开始比较，
若首位为0，从数组首位逐次与后面元素比较，可能会有一下情况：
1）若两个元素都为0，不交换
2）首位不为0，不交换
3）只有比较的首位为0，另一个元素不为0，进行交换，交换完成，进行元素次位与后面元素的比较
   for i in range(len(nums)-1):
        if nums[i] == 0:
            for j in range(i+1, len(nums)):
                if nums[j] != 0:
                    nums[i], nums[j] = nums[j], nums[i]
                    break

官方题解：
使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部
右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移
左指针左边都是非零数，右指针左边直到左指针处都为0
"""


def moveZeroes(nums):
    n = len(nums)
    left = right = 0
    while right < n:
        if nums[right] != 0:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
        right += 1
    return nums


if __name__ == "__main__":
    nums = [1, 2, 0, 3, 4]
    #  [0] [0, 1, 0, 3, 12]
    print(moveZeroes(nums))

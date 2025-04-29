# 希尔排序


def shellSort(nums):
    size = len(nums)
    gap = size//2  # 最开始间隔数组长度取一半
    while gap > 0:
        for i in range(gap, size):
            # 从gap直到数组末尾
            temp = nums[i]
            j = i
            while j >= gap and nums[j-gap] >= temp:
                nums[j] = nums[j-gap]  # 后面的数比最开始的temp值大 把前面的值赋值给后面 数组中间隔为gap的数组进行排序
                j -= gap
            nums[j] = temp  # 实际上交换的是两个位置的元素值
        gap = gap//2
    return nums


if __name__ == "__main__":
    nums = [3, 2, 1, 5]
    # [7, 2, 6, 8, 0, 4, 1, 5, 9, 3]
    print(shellSort(nums))

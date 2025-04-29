#  选择排序算法实现


def selectionSort(nums):
    for i in range(len(nums)-1):
        min_i = i
        for j in range(i+1, len(nums)):
            if nums[j] < nums[min_i]:
                min_i = j
        if i != min_i:
            nums[i], nums[min_i] = nums[min_i], nums[i]
    return nums


if __name__ == "__main__":
    nums = [3, 2, 1, 5, 6, 4]
    print(selectionSort(nums))

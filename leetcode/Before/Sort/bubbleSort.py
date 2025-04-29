# 冒泡排序算法实现


def bubbleSort(nums):
    for i in range(len(nums)-1):
        flag = False  # 标志位 若未发生元素交换 就退出循环
        # 从前面往后面依次比较大小
        for j in range(len(nums)-i-1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                flag = True
        if not flag:
            break
    return nums


if __name__ == "__main__":
    nums = [6, 5, 2, 1, 4]
    print(bubbleSort(nums))

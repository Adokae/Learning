# 2024年11月16日

# 1 724寻找数组的中心下标
# 中心下标左侧元素之和与右侧元素之和相等 若中心下标在最左侧 其左侧数之和为0 同样适用于右侧
# 若不存在中心下标 返回-1

def pivoIndex(nums):
    """
    # 法1 思路也是官方思路
    # 先求数组中的总和 然后在遍历 但值达到总和值的一半时 返回索引
    m = sum(nums)
    left_value = 0
    i = 0
    # 下标左侧元素值的两倍+该元素值不等于数组总和(不满足中心下标要求) 而且该元素索引小于等于数组长度-1(避免超出索引长度)
    while left_value*2+nums[i] != m and i <= len(nums)-2:
        left_value += nums[i]
        i += 1
    # 进行最终的判断
    if sum(nums[:i]) == sum(nums[i+1:]):
        return i
    else:
        return -1
    """
# 法2 思路 自己最开始想到的是从中间开始找索引 算左边值和右边值 左边值大 索引左移 但这种思路只适合数组元素值为正数
# 在考虑元素有负数时 遍历 但这样算法复杂度N的二次方
    for i in range(len(nums)):
        left_value = sum(nums[:i])
        right_value = sum(nums[i+1:])
        if left_value == right_value:
            return i
    return -1


if __name__ == "__main__":
    # [1, 2, 3][1][2, 1, -1][1, 7, 3, 6, 5, 6]
    # [-1, -1, -1, -1, 0, 1]
    nums = [-1, -1, -1, -1, -1, 0]
    print(pivoIndex(nums))




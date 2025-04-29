# 第一题
# 给定整数数组和目标值，找出数组中和为目标值两个整数，返回它们在数组中的索引值

def twoSum(nums, target):
    # 遍历 最基本的思路 时间复杂度为n^2
    # for i in range(len(nums)):
    #     a = nums[i]
    #     for j in range(i+1, len(nums)):
    #         b = nums[j]
    #         if target == a+b:
    #             return [i, j]

    # 哈希表(还不太理解) 时间复杂度为n
    # 创建一个空字典，遍历数组，
    # 若目标值减去当前遍历到的数组值后的值在字典的键中，则返回该键对应对索引(所对应的索引就是该值在数组中所对应的索引值)
    # 否则就把该值和该值对应的索引加入到字典中
    numDict = dict()
    for i in range(len(nums)):
        if target - nums[i] in numDict:
            return numDict[target - nums[i]], i
        numDict[nums[i]] = i
    return [0]


if __name__ == "__main__":
    nums = [3, 2, 4]
    target = 6
    print(twoSum(nums, target))

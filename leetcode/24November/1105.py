# 189 轮转数组
# 给定一个整数数组，向右轮转k个位置，k为非负数

# 原地翻转
# 首先对数组nums整个翻转，对翻转后的前k个元素在翻转，后n-k个元素在翻转，n表示数组长度

# 函数中使用->None表示该函数没有返回值

def rev(nums, left, right):
    while left < right:
        x = nums[left]
        nums[left] = nums[right]
        nums[right] = x
        left += 1
        right -= 1
    return nums


def rotate(nums, k):
    # 要求原地翻转
    # a = nums[len(nums)-k:]
    # b = list(set(nums)-set(a))
    # a.extend(b)
    n = len(nums)
    k = k % n  # 长度大于n
    rev(nums, 0, n-1)
    rev(nums, 0, k-1)
    rev(nums, k, n-1)
    return nums


if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    # 法1：反转
    # print(rotate(nums, k))

    # 法2：之前思路就是截取前n-k个元素 后k个元素 把后k个元素加上前n-k个元素
    # n = len(nums)
    # print(nums[-k % n:])  # 这是索引，python中索引从0开始
    # nums = nums[-k % n:] + nums[:-k % n]  # 一行解决问题
    # print(-3 % 7)  # 得到4 原因：-3对7取整为-1 -3-(7*-1)=4

    # 法3
    # 重复k次：把最后一个元素插入列表中的第一个位置
    # nums.pop()用于从列表中移除一个元素，并返回该元素的值
    for i in range(k):
        nums.insert(0, nums.pop())

    print(nums)


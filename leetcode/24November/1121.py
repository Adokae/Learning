# 485 最大连续1的个数
# 给定一个二进制数组 计算其中最大连续1的个数
# 自己没做出来，而且没有思路 看其他人的思路

def findMaxConsecutiveOnes(nums):
    # 思路1 遍历该数组中的每一个元素 加上当前元素，在乘以当前元素，如果为1，则就是连续1的个数，如果为0，该值就清为0
    """
    num = 0
    maxconsecutive = 0
    for i in nums:
        num = (num+i)*i
        if num > maxconsecutive:
            maxconsecutive = num
    return maxconsecutive
    """

   #  思路2 遍历该数组 记录之前最大连续1的个数和当前最大连续1的个数
   #  若当前数为1 当前连续1的个数加1 若为0 当前连续1的个数为0 并比较更新之前最大连续1的个数
    num = 0
    maxcon = 0
    for i in nums:
        if i == 1:
            num += 1
        else:
            maxcon = max(num, maxcon)
            num = 0
    maxcon = max(num, maxcon)
    return maxcon


# 238 除自身以外数组的乘积
# 给定长度n(n>1)的整数数组nums，返回输出数组output，其中output[i]等于nums中除nums[i]之外其余各元素的乘积
# 例：输入[1,2,3,4] 输出[24,12,8,6]
# 不允许使用乘法
# 官方题解1-answer = 前缀之积*后缀之积
# nums = [1, 2, 3, 4] 中对第一个元素1来说，它的前缀之积为1，对第二个元素2来说，它的前缀之积等于第一个前缀之积*它前面的元素 以此类推
# 后缀之积跟前缀之积类似，只是顺序相反
# 官方题解2-降低空间复杂度 首先使用answer存储前缀之积，然后使用后缀之积
# 官方题解2-降低空间复杂度 首先使用answer存储前缀之积，后缀之积不用数组存储，而是用一个数进行不断更新，同时乘以answer的前缀之积得到最终结果
def productExceptSelf(nums):
    forward_value = 1
    backward_value = 1
    forward = [1]
    # answer = [1]*len(nums)
    for i in range(len(nums)-1):
        forward_value *= nums[i]
        forward.append(forward_value)
    j = -1  # j的判断条件要大于等于(-(len(nums))+1)，因为while循环里面要做-1操作，要避免超出索引
    while j >= (-(len(nums))+1):
        backward_value *= nums[j]  # 此为j-1的后缀之积，因为j=-1的后缀之积为1
        j -= 1
        forward[j] *= backward_value
    # 后缀之积使用answer存储
    # for x in range(len(answer)):
    #     answer[x] *= forward[x]
    return forward


if __name__ == "__main__":
    # nums = [1, 0, 1, 0, 1, 1]
    # print(findMaxConsecutiveOnes(nums))
    nums = [1, 2, 3, 4]  # [-1, 1, 0, -3, 3]
    print(productExceptSelf(nums))

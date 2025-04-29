# 66 加1
# 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加1
# 数组中最高位数字存放在数组的首位，数组中每个元素只存储单个数字


def plusone(digits):
# 自己的思路
# 把列表转化为一个整数 对整数加1 然后在将整数转换为列表
# 时间复杂度 3n+1
    # n = len(digits)
    # num = 0
    # for i in range(n):
    #     num += 10 ** (n - i - 1) * digits[i]
    # num = num + 1
    # num = list(str(num))
    # for i in range(len(num)):
    #     num[i] = int(num[i])
    # print(num)
    # return num

#  法2 从后面遍历 看值是否为9
#  为9则该位变为0  不为9则该位加1
#  思想是从后判断各位是否为9，为9则该位变为0，若整体遍历完都为9，则加首位，且首位为1
    for i in range(len(digits)-1, -1, -1):
        if digits[i] < 9:
            digits[i] += 1  # 若某一位不为9，则该位加1，跳出循环
            return digits
        digits[i] = 0  # 该位为9，则改为变为0
    return [1] + digits  # 遍历完后 都为9 则加首位


if __name__ == "__main__":
    # digits = [9, 9, 9]
    digits = [1, 1, 9]
    print(plusone(digits))

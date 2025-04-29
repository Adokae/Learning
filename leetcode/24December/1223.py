# 排序算法
# 1 冒泡排序

# 算法基本原理

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


# 力扣习题164 破解闯关密码
# 给一个元素为非负整数的数组 返回数组中所有元素拼接后的最小整数
# 官方题解法： 要比较拼接后的数字大小：比较两个字符串x和y
# 若x+y > y+x,则x>y，x和y的顺序要互换
# 若x+y < y+x,则x<y，x和y的顺序不发生改变

def crackPassword(password):
    for i in range(len(password)-1):
        flag = False  # 标志位 若未发生元素交换 就退出循环
        # 从前面往后面依次比较大小
        for j in range(len(password)-i-1):
            if int(str(password[j])+str(password[j+1])) > int(str(password[j+1])+str(password[j])):
                password[j], password[j+1] = password[j+1], password[j]
                flag = True
        if not flag:
            break
    nums = ""
    for a in password:
        nums += str(a)
    return nums


if __name__ == "__main__":
    # 验证冒泡算法函数的正确性
    # nums = [9, 1, 5, 8, 3, 7, 4, 6, 2]
    # print(bubbleSort(nums))

    # leetcode 164
    # password = [15, 8, 7]
    password = [0, 30, 34, 5, 9]
    print(crackPassword(password))

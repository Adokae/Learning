# 73 矩阵置零
# m*n的矩阵 将其中为0元素所在的行和列都置为0 原地算法实现
"""
自己的思路：先找为0元素所在行和列，再将所在行和列使用for循环置为0
   zero_list = []
    for row in range(m):
        for col in range(n):
            if matrix[row][col] == 0:
                zero_list.append(row)
                zero_list.append(col)
    i = 0  # 存0列表中的第一个元素
    while i <= len(zero_list)-1:
        row = zero_list[i]
        for j in range(n):
            matrix[row][j] = 0
        col = zero_list[i+1]
        for j in range(m):
            matrix[j][col] = 0
        i += 2
"""

"""
官方题解1：
(1)使用标记数组，使用两个标记数组记录每行和每列是否有为0元素，将为0元素所在行和列标记为true
    zero_row, zero_col = [0]*m , [0]*n
    for row in range(m):
        for col in range(n):
            if matrix[row][col] == 0:
                zero_row[row] = 1
                zero_col[col] = 1
    # 自己考虑将其置零用的是for循环 将该行或该列元素置为0
    # if条件表示如果是该行或该列标志为1，则将该行或该列置为0
    # 但官方题解代码
    for row in range(m):
        for col in range(n):
            if zero_row[row] or zero_col[col]:
                matrix[row][col] = 0

# 官方题解2
# 为实现降低空间复杂度 先使用两个标记变量分别记录矩阵第一行和第一列是否包含0
# 用矩阵第一行和第一列存储该矩阵中某行、某列是否存在为0元素(若存在为0元素，该行/列本来就要为0，若不存在，该元素也未改变)
# 最后根据矩阵第一行和第一列的值先改变矩阵其他行列为0元素值 最后在改变矩阵第一行和第一列值
first_row = any(matrix[0][j] == 0 for j in range(n))
first_col = any(matrix[j][0] == 0 for j in range(m))
for row in range(1, m):
    for col in range(1, n):
        if matrix[row][col] == 0:
            matrix[0][col] = matrix[row][0] = 0
for row in range(1, m):
    for col in range(1, n):
        if matrix[0][col]==0 or matrix[row][0]==0:
            matrix[row][col] = 0
if first_row:
    for col in range(n):
        matrix[0][col] = 0
if first_col:
    for row in range(m):
        matrix[row][0] = 0
"""



def setZeros(matrix):
    m = len(matrix)  # 行数
    n = len(matrix[0])  # 列数
    # 官方题解3 在题解2的基础上进行改进
    # 使用标记数组标记第一列是否有为0元素 然后遍历除去第一列的数组 若出现0 将出现0的行和列所对应的第一行/列记录位置标为0
    # 从后面开始将矩阵改为0，不然会改变第一列元素的值，导致改行未出现0也会变为0
    first_col = any(matrix[j][0] == 0 for j in range(m))
    for row in range(m):
        for col in range(1, n):
            if matrix[row][col] == 0:
                matrix[row][0], matrix[0][col] = 0, 0
    for row in range(m-1, -1, -1):
        for col in range(1, n):
            if matrix[row][0] == 0 or matrix[0][col] == 0:
                matrix[row][col] = 0
    if first_col:
        for row in range(m):
            matrix[row][0] = 0

    return matrix


if __name__ == "__main__":
    # matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    print(setZeros(matrix))

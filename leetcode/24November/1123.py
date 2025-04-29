# 498 对角线遍历 对m*n的矩阵以对角线遍历的顺序 用数组返回这个矩阵中的所有元素
# 自己的思路：在3*3列元素 列表中元素对应mat中的位置分别是(0,0), (0,1),(1,0), (2,0),(1,1),(0,2), (1,2),(2,1), (2,2)
# 各分割开的位置相加分别是0 1 2 3 4 最大元素和是行数+列数-2  但一个问题是各部起始元素位置无法找到规律 0 1 2 1 2？
# --由官方题解可知

# 官方思路：
""""
首先确定m行n列矩阵共有m+n-1条对角线，相邻对角线遍历方向不同，m+n-1条对角线的取值范围是[0,m+n-2]
对角线i为偶数时，遍历方向从下往上；为奇数时，遍历方向从上到下
(1)从下往上遍历时，i<m时，起始位置为(i, 0)；i>=m时，起始位置为(m-1,i-m+1);行索引-1，列索引+1，直到边缘位置
(1)从上往下遍历时，i<n时，起始位置为(0，i)；i>=n时，起始位置为(i-n+1，n-1)；行索引+1，列索引-1，直到边缘位置
"""


def findDiagonalOrder(mat):
    row = len(mat)
    col = len(mat[0])
    c = row+col-1  # 每层元素的最大和-对角线个数
    m = []
    for i in range(c):
        if i % 2 == 0:
            # 遍历方向从下往上
            if i < row:
                row_i = i
            else:
                row_i = row-1
            while row_i >= 0:
                col_i = i - row_i
                if (row_i <= row-1) and (col_i <= col-1):
                    m.append(mat[row_i][col_i])
                    row_i -= 1
                else:
                    break
        else:
            # 遍历方向从上往下
            if i < col:
                col_i = i
            else:
                col_i = col-1
            while col_i >= 0:
                row_i = i - col_i
                if (row_i <= row-1) and (col_i <= col-1):
                    m.append(mat[row_i][col_i])
                    col_i -= 1
                else:
                    break
    return m


# 48 旋转图像 n*n的二维矩阵 原地将图像顺时针旋转90度
# 讨论区思路：把矩阵元素按对角线翻转 然后在对每一行元素逆序  此思路自己未实现
"""
如何做到矩阵元素按对角线翻转呢：采用498题遍历对角线元素的思路
确定n行n列矩阵共有2n-1条对角线，取值范围是[0,2n-2] 起始位置为(i, 0),与起始位置替换位置的元素位置为(0,i) 
不更换元素位置的终止条件是更换元素次数达到n次
"""

""""
官方题解：
第一种思路：
(1)从旋转90度中可以查看到变换规律：n*n矩阵，第一行第x个元素转换为最后一列第x个元素 
matrix[row][col] ->matrix[col][n-row-1]
先使用一个新矩阵存储转换后的矩阵，再将转换后的新矩阵值赋值给原矩阵
第二种思路：
(2)要求原地翻转，考虑使用一个额外元素预先存储一个元素，以避免该元素被覆盖
翻转元素实际上是元素的逐步赋值：
(row,col)->(col,n-row-1)->(n-row-1,n-col-1)->(n-col-1,row)->(row,col)
"""
# 官方题解第一种思路
"""
   matrix_new = [[0] * n for _ in range(n)]
   for row in range(n):
       for col in range(n):
           matrix_new[col][n-row-1] = matrix[row][col]
   matrix[:] = matrix_new  # 此操作保留matrix的应用不变 即内存地址不变 所储存的内容改变
   """
# 官方题解第二种思路
# 它是先提取位置元素的数据 在交换位置 故不会存在覆盖问题
# 行数和列数也是寻找规律吗？
"""
 for i in range(n//2):
     for j in range((n+1)//2):
         matrix[i][j], matrix[n - j - 1][i], matrix[j][n - i - 1], matrix[n - i - 1][n - j - 1]\
             = matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1], matrix[i][j], matrix[j][n - i - 1]
 """

def rotate(matrix):
    n = len(matrix)
    # 第三种思路 先水平翻转 在按主对角线翻转
    # 水平翻转
    for row in range(n//2):
        for col in range(n):
            matrix[row][col], matrix[n-row-1][col] = matrix[n-row-1][col], matrix[row][col]
    # 按对角线翻转
    # 每一行翻转的元素不一致
    for row in range(n):
        for col in range(row):
            matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]
    return matrix


if __name__ == "__main__":
    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]  # [[1, 2], [3, 4]]
    # print(findDiagonalOrder(mat)) # 498
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    # [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(rotate(matrix))

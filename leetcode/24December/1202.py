# 54 螺旋矩阵
# 对m*n矩阵 按顺时针螺旋顺序 返回矩阵中的所有元素
# 自己没有思路
"""
官方解法：
(1)模拟螺旋矩阵路径，从左上角开始，初始方向向右，但路径超出界限或访问已经访问过的元素，就转换方向
方向包括(0,1)->(1,0)->(0,-1)->(-1,0)
考虑访问已经访问过的元素的原因：但螺旋矩阵中的螺旋路径到达第一列的第二个元素，如果只设置条件为路径不超出界限，
则会继续访问索引(0,0)的元素
    visited = [[False] * columns for _ in range(rows)]
    total = rows * columns  # 总共访问的元素
    order = [0] * total
    directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    # 根据螺旋顺序访问矩阵元素时 索引值(row,column)的行列变化就是根据加方向值行进的
    row, column = 0, 0
    directionIndex = 0
    for i in range(total):
        order[i] = matrix[row][column]
        visited[row][column] = True
        nextRow, nextColumn = row + directions[directionIndex][0], column + directions[directionIndex][1]
        # 先生成下一行和列判断行列是否在矩阵中 下一元素是否被访问过 若都满足 则访问该元素
        # 不满足 改变方向
        if not (0 <= nextRow < rows and 0 <= nextColumn < columns and not visited[nextRow][nextColumn]):
            directionIndex = (directionIndex + 1) % 4
        row += directions[directionIndex][0]
        column += directions[directionIndex][1]
(2)按层模拟
把矩阵分成若干层，第k层是到最近边界距离为k的顶点
每层：从左上方开始，按顺时针方向遍历
"""


def spiralOrder(matrix):
    if not matrix or not matrix[0]:
        return list()
    rows, columns = len(matrix), len(matrix[0])
    top, left = 0, 0
    bottom, right = rows - 1, columns - 1
    order = []
    while bottom >= top and right >= left:
        row = top
        for column in range(left, right + 1):
            order.append(matrix[row][column])
        column = right
        for row in range(top + 1, bottom + 1):
            order.append(matrix[row][column])
        #  防止出现一行或一列元素的情况
        if left < right and top < bottom:
            row = bottom
            for column in range(right - 1, left, -1):
                order.append(matrix[row][column])
            column = left
            for row in range(bottom, top, -1):
                order.append(matrix[row][column])
        top, left = top + 1, left + 1
        bottom, right = bottom - 1, right - 1
    return order


if __name__ == "__main__":
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(spiralOrder(matrix))

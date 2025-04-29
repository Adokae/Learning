# 59 螺旋矩阵2
# 参考螺旋矩阵的思路，螺旋矩阵是提取矩阵中的元素，而本题是更改矩阵中的元素
# 官方思路也是按照之前螺旋矩阵的思路


def generateMatrix(n):
    matrix = [[0]*n for _ in range(n)]
    # elements = [i for i in range(1, n**2+1)]
    element = 1
    top, left = 0, 0
    bottom, right = n-1, n-1
    index = 0
    while bottom >= top and right >= left and element <= n**2:
        row = top
        for column in range(left, right+1):
            matrix[row][column] = element
            element += 1
            # index += 1 elements[index]
        column = right
        for row in range(top+1, bottom+1):
            matrix[row][column] = element
            element += 1
            # index += 1  elements[index]
        #  防止出现一行或一列元素的情况
        if left < right and top < bottom:
            row = bottom
            for column in range(right-1, left, -1):
                matrix[row][column] = element
                element += 1
                # index += 1   elements[index]
            column = left
            for row in range(bottom, top, -1):
                matrix[row][column] = element
                element += 1
                # index += 1   elements[index]
        top, left = top+1, left+1
        bottom, right = bottom-1, right-1
    return matrix


# 289 生命游戏
# 最初思路是看该元素周围元素(周围最多考虑八个元素，根据实际情况考虑)，但后面又有要求同时更新的问题，如何做到同时更新？创建一个新矩阵？
# 官方题解1 暴力解法 创建一个新数组 将应改变的值放置到新数组中改变
"""
    neighbors = [(-1, -1), (1, 1), (-1, 0), (1, 0), (0, -1), (0, 1), (-1, 1), (1, -1)]
    rows = len(board)
    columns = len(board[0])
    # copy_board = [[0]*columns for _ in range(rows)]
    # for row in range(rows):
    #     for column in range(columns):
    #         copy_board[row][column] = board[row][column]
    # 更便捷的复制方式
    copy_board = [[board[row][column] for column in range(columns)] for row in range(rows)]
    for row in range(rows):
        for column in range(columns):
            live = 0
            for neighbor in neighbors:
                r = row + neighbor[0]
                c = column + neighbor[1]  # 周围元素的行和列
                # 周围元素为活细胞时
                if (r >= 0 and r <= rows-1) and (c >= 0 and c <= columns-1) and (board[r][c] == 1):
                        live += 1
            if copy_board[row][column] == 1 and (live < 2 or live > 3):
                    board[row][column] = 0
            elif copy_board[row][column] == 0 and (live == 3):
                board[row][column] = 1
"""
# 官方题解2 引人新状态进入暂存
"""
引入新状态如下：
1）活细胞周围位置的活细胞数小于2，该活细胞死亡，细胞值-1
2）活细胞周围位置的活细胞数为2或3，该活细胞存活，细胞值1
3）活细胞周围位置的活细胞数大于3，该活细胞死亡，细胞值-1  # 设-1 绝对值为1 表明该位置前一时刻还是活细胞
4）死亡细胞周围位置的活细胞数为3，该死亡细胞存活，细胞值2
"""
def gameOfLife(board):
    # 题解2
    neighbors = [(-1, -1), (1, 1), (-1, 0), (1, 0), (0, -1), (0, 1), (-1, 1), (1, -1)]
    rows = len(board)
    columns = len(board[0])
    for row in range(rows):
        for column in range(columns):
            live = 0
            for neighbor in neighbors:
                r = row + neighbor[0]
                c = column + neighbor[1]  # 周围元素的行和列
                # 周围元素为活细胞时
                # 此处取绝对值 因为取值为-1的元素前一个时隙还是活细胞 转换时一定要考虑前一个时隙
                if (r >= 0 and r <= rows-1) and (c >= 0 and c <= columns-1) and (abs(board[r][c]) == 1):
                        live += 1
            if board[row][column] == 1 and (live < 2 or live > 3):
                board[row][column] = -1
            elif board[row][column] == 0 and live == 3:
                board[row][column] = 2

    for row in range(rows):
        for column in range(columns):
            if board[row][column] == -1:
                board[row][column] = 0
            elif board[row][column] == 2:
                board[row][column] = 1
    return board


if __name__ == "__main__":
    # n = 6
    # print(generateMatrix(n))  # 59 螺旋矩阵
    board = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
    # board = [[1, 1], [1, 1]]
    print(gameOfLife(board))  # 289 生命游戏

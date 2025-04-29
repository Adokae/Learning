#字符菱形,int(input('请输入菱形对角线边长：'))\
#end=''，没有end,print()语句自动换行；加上它，数据不会自动换行，而是在输出数据后面加上空格，空格数取决于括号里面的空格数
a = input()
rows = 5
row = 1
while row <= rows:
    col = 1  # 每次内循环col都从1开始，打印前面空格的个数
    while col <= (rows - row):  # 内层while就是单纯打印空格，由于*号后带空格，故第一步开始要间隔4
        print(' ', end='')  # 空格的打印不换行，end在此就是让它不换行
        col += 2
    print(row * a)  # 每一行打印完空格后，接着在同一行打印星星，且打印完星星后print默认换行,*后带空格
    row += 2

bottom = rows - 2
while bottom > 0:
    col = 1  # 保证每次内循环col都从1开始，打印前面空格的个数
    while bottom + col <= rows:
        print(' ', end='')  # 空格的打印不换行
        col += 2
    print(bottom * a)  # 每一行打印完空格后，接着在同一行打印星星，星星个数与行数相等，且打印完星星后print默认换行
    bottom -= 2
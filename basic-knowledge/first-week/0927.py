#流程控制语句break,常用来结束循环结构，常与if一起使用
#从键盘输入密码，最多输入三次，若正确结束循环
'''
for i in range(3):
    secret = input("请输入密码：")
    if secret == "888":
        print("密码正确")
        break
    else:
        print("密码错误")
'''

'''
a = 0
while a < 3:
    secret = input("请输入密码：")
    if secret == "888":
        print("密码正确")
        break
    else:
        print("密码错误")
        a += 1
else:
    print("对不起，密码输入次数已经达到三次")
'''

#continue 结束当前循环，进入下一次循环，通常与if一起使用
#要求输出1到50之间所有5的倍数
'''
for i in range(1,51):
    if i%5 != 0:
        continue
    else:
         print(i)
'''

#嵌套循环,循环结构中又嵌套了另外完整的循环结构，内层作为外层的循环体执行
#输出一个三行四列的矩形
'''
for i in range(1,4):
    for j in range(1,5):
        print("*",end="\t")
    print()#完成每一列“*”打印后换行
'''

#打印一个直角三角形
'''
a = input("输入：")
for i in range(1,10):
    print(i*a)
'''

#输出一个九九乘法表
'''
for i in range(1,10):
    for j in range(1,i+1):
        print(i,"*",j,"=",i*j,end="  ")
    print()
    #print('') 每一行结束后换行
'''

#二重循环中的break和continue用于控制本层循环
'''
for i in range(5):
    for j in range(1,11):
        if j%2 == 0:
        #    break   #直接跳出for循环了
           continue  #继续进行内层for循环
        print(j,end=" ")
    print()
'''


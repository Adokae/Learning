#文件路径连接
'''
import os

path1 = "/path/with space"
path2 = "file with space.txt"

joined_path = os.path.join(path1, path2)
a = os.path.join(path1,"stft",path2)
print(joined_path)
print(a)
'''

'''
#矩阵
import numpy as np
arr = np.arange(16).reshape((2,2,4))
#arange表示数据大小,包括初始值、最后值、步长,reshape中(2,2,4)表示构造两个2x4维矩阵
c = np.array([[1,2,3],[4,5,6]])

print(arr)
print(c)
print(c.reshape(3,2)) #三行两列
print(c.reshape(-1,1))#不知道几行，确定一列
'''


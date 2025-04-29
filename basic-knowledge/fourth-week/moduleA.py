#if __name__ == '_main_'理解

#模块A
a = 100
print("this is module A")
#print(a)

#若是不想在模块B中运行输出a，可加如下语句：
if __name__ == '__main__':
    print(a)


# 第七章 python中异常处理 bug Pycharm的调试模式

# try...except语法结构为：
# try:
#   可能会抛出异常的代码
# except:
#     异常处理代码(报错后执行代码)

# try...except...except语法结构为：
# try:
#   可能会抛出异常的代码
# except 异常类型A:
#     异常处理代码(报错后执行代码)
# except 异常类型B:
#     异常处理代码(报错后执行代码)
# 遵循先子类后父类
# 示例 除数不能为0或字符串
"""
try:
    n1 = int(input("输入一个整数："))
    n2 = int(input("输入另一个整数："))
    result = n1/n2
    print("结果为：", result)
except ZeroDivisionError:
    print("输入有误，除数为0")
except ValueError:
    print("所输入值为字符串，不能将字符串转换为整数")
except BaseException:
    print("未知异常")
"""

# try...except...else的语法结构为
# try...except语法结构为：
# try:
#   可能会抛出异常的代码
# except:
#     异常处理代码(报错后执行代码)
# else:
# 没有抛异常要执行的代码

# try...except...else...finally的语法结构为
# try...except语法结构为：
# try:
#   可能会抛出异常的代码
# except:
#     异常处理代码(报错后执行代码)
# else:
# 没有抛异常要执行的代码
# finally:
# 无论是否产生异常都要执行的代码
"""
# 示例
try:
    n1 = int(input("输入一个整数："))
    n2 = int(input("输入另一个整数："))
    result = n1/n2
except ZeroDivisionError:
    print("输入有误，除数为0")
except ValueError:
    print("所输入值为字符串，不能将字符串转换为整数")
except BaseException:
    print("未知异常")
else:
    print("结果为：", result)
finally:
    print("程序运行结束")
"""

# raise 抛出异常，从而提醒程序出现异常情况，程序能正确地处理这些异常情况
# 语法结构为： raise [Exception类型(异常描述信息)]

"""
try:
    gender = input("请输入你的性别：")
    if gender != "男" and gender != "女":
        raise Exception("性别只能是男或女")
    else:
        print("输入性别正确")
except Exception as e:
    print(e)
"""

# python中常见异常
# ZeroDivisionError:除数为0，引发的异常
# IndexError:索引超出范围所引发的异常
# KeyError:字典取值时key不存在所引发的异常
# NameError:使用一个没有声明变量时引发的异常
# SyntaxError:python中语法错误
# ValueError:传入的值错误
# AttributeError:属性或方法不存在的异常
# TypeError:类型不合适引发的异常
# IndentationError:不正确缩进引发的异常

# SyntaxError
# print("hello)

#变量的浅拷贝、深拷贝
class CPU:
    pass

class Disk:
    pass

class Computer:
    def __init__(self,cpu,disk):
        self.cpu = cpu
        self.disk = disk

#变量赋值
#cpu1、cpu2指向同一个对象
cpu1 = CPU()
cpu2 = cpu1
print(cpu1,id(cpu1)) #<__main__.CPU object at 0x000002163BA0C9D0> 2294512929232
print(cpu2,id(cpu2))  #<__main__.CPU object at 0x000002163BA0C9D0> 2294512929232


#浅拷贝
print('---------------')
disk = Disk() #创建一个实例对象
computer = Computer(cpu1,disk)
#实例对象中的cpu、disk会指向CPU、Disk的实例对象的地址

import copy
computer2 = copy.copy(computer)
#将computer这个实例对象拷贝一份，但所拷贝的cpu、disk不变
print(computer,computer.cpu,computer.disk)
#<__main__.Computer object at 0x000002337C7E0B50> <__main__.CPU object at 0x000002337C7E0B10> <__main__.Disk object at 0x000002337C7E0B90>
print(computer2,computer2.cpu,computer2.disk)
#<__main__.Computer object at 0x000002337C7E0BD0> <__main__.CPU object at 0x000002337C7E0B10> <__main__.Disk object at 0x000002337C7E0B90>


print("-----------------")
#深拷贝
computer3 = copy.deepcopy(computer)
#拷贝的computer,把子对象也拷贝一份，所拷贝的地址会变化
print(computer,computer.cpu,computer.disk)
#<__main__.Computer object at 0x000001B25C180C10> <__main__.CPU object at 0x000001B25C180BD0> <__main__.Disk object at 0x000001B25C180C50>
print(computer3,computer3.cpu,computer3.disk)
#<__main__.Computer object at 0x000001B25C180DD0> <__main__.CPU object at 0x000001B25C180D90> <__main__.Disk object at 0x000001B25C181010>

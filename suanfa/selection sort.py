#二分查找
#左闭右闭
#查找指定元素在有序列表中的位置
nums = [-1,0,3,9,11,13,22,27,33,57,66,77]
m = len(nums)
target = 33
left = 0
right = m-1
while left <= right:
    middle = left +(right-left)//2
    if nums[middle] > target:
        right = middle-1
    elif nums[middle] < target:
        left = middle+1
    else:
        print(middle)
        break
if left > middle:
    print(-1)

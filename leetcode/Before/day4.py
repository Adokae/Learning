import random
#力扣-455 分发饼干 贪婪算法 直接一个个对比
'''
g = [1,2] #孩子胃口
s = [1,2,3]   #饼干尺寸
sum = 0
i = 0 #孩子
j = 0 #饼干
while i < len(g):
    if j < len(s):
        if s[j] >= g[i]:
            sum += 1
            i += 1
            j += 1
        else:
            j += 1
    else:
        break

print(sum)
'''

'''
#力扣-435 无重叠区间-贪婪算法
#排序，从第二个元素中的开始比较start2<end1,则发生重叠，此时比较end1与end2，谁更长，则去除哪一位元素
#  [[1,2],[2,3],[3,4],[1,2]] [[1,2],[2,3]]
intervals =  [[1,2],[1,2],[1,2]]
intervals.sort()
print(intervals)
sum = 0
for i in range(1,len(intervals)):
    if intervals[i][0] < intervals[i-1][1]:
        sum += 1
        if intervals[i][1] >= intervals[i-1][1]:
            intervals[i][1] = intervals[i-1][1]

print(sum)
'''

#力扣-912排序数组 分治算法
'''
nums = [5,0,7,3,1,6,8,4]#   [5,2,3,1] [5,1,1,2,0,0]

#选择排序 nums长度为n 首先要从n个数中找到最小的排在第一位 然后从n-1个数中找到最小的排在第二位 以此类推 直到排序完成
def selectsort(s):
    for i in range(0,len(nums)-1): #从0到第n-1个数 因为还需要找后面的数与其对比大小
        min = nums[i]
        dex = 0
        for j in range(i,len(nums)):
            if nums[j] < min:
                min = nums[j]
                dex = j
        if dex != 0:
            nums[i],nums[dex] =  nums[dex],nums[i]

'''

'''
#冒泡排序 对比每队相邻元素 若前者比后者大 则交换两者次序
for i in range(len(nums)-1,-1,-1):
    for j in range(0,i):
        if nums[j] > nums[j+1]:
            nums[j],nums[j+1] = nums[j+1],nums[j]
print(nums)
'''

#插入排序 首先确定第一个数 比较第一个数和第二个数大小 插入第二个数 然后确定第一个 第二个数 比较插入第三个数 以此类推
'''
#nums = [65,27,59,64,58]
for i in range(1,len(nums)):
    x = nums[i]
    j = i-1
    while j >= 0:#分布判断 先把大的数置于后面 找到插入数的具体位置后才将具体位置的数变为所要插入的数
        if x <= nums[j]:
            nums[j+1] = nums[j]
            j -= 1
        else:
            break
    nums[j+1] = x
print(nums)
'''

#归并排序-先对半分，直至只有一个元素，对于左边，先排序第一个和第二个元素，在排序第一个 第二个 第三个元素 直至左边排序完成
#右边排序同理 最后直接对两个有序数列排序
'''
def merge(s,start,mid,end):
    tmp = []
    l = start
    r = mid+1
    while l <= mid and r <= end:
        if s[l] <= s[r]:
            tmp.append(s[l])
            l += 1
        else:
            tmp.append(s[r])
            r += 1
    tmp.extend(s[l:mid+1])
    tmp.extend(s[r:end+1])
    for i in range(start,end+1):
        s[i] = tmp[i-start]

def mergesort(s,start,end):
    if start == end:
        return
    mid = (start+end)//2
    mergesort(s,start,mid)
    mergesort(s,mid+1,end)
    merge(s,start,mid,end)

mergesort(nums,0,7)
print(nums)
'''

'''
#桶排序-适用数据分布均匀的排序
def bucketsort(s):
    maxv = max(s)
    minv = min(s)
    bucket = [[],[],[]]
    bucketCount = 3
    perbucket = (maxv-minv+bucketCount)//bucketCount #通过找寻最大值和最小值确定每个桶中元素个数
    for num in s: #把元素分配到对应桶中
        bucketidx = (num-minv)//perbucket
        bucket[bucketidx].append(num)

    for i in range(bucketCount):#桶中元素排序
        selectsort(bucket[i])
    idx = 0

    for i in range(bucketCount): #把桶中元素按顺序排列到一个序列中 以完成排序操作
        for j in bucket[i]:
            s[idx] = j
            idx += 1


#计数排序-适用数据量大但数据范围小的排序 以空间换时间
def countsort(s):
    maxs = max(s)
    mins = min(s)
    n = maxs-mins+1
    a = [0]*n
    for i in s:
        a[i] += 1
    s.clear()
    for j in range(len(a)): #使c产生a中对应索引元素的值与个数 然后加到s中
        c = [j]*a[j]
        s.extend(c)

#基数排序
def radisort(s):
    base = 1
    maxs = max(s)
    while base <= maxs:
        bucket = []
        for idx in range(10):
            bucket.append([]) #创建10个桶，空列表

        for num in s:
            idx = num//base%10
            bucket[idx].append(num) #桶中个位排序、十位

        l = 0

        for idx in range(10):
            for v in bucket[idx]:
                s[l] = v
                l += 1

        base *= 10
'''
#nums = [421,240,115,532,305,34,124]

#快速排序
'''
def quicksortpivot(s,start,end):
    pivot = start
    j = start+1
    for i in range(j,end+1):
        if s[i] <= s[start]: #第一位作为基准位，后面元素跟基准位对比，比基准位小，就交换元素位置，j表示该位置左边元素都比基准位小，右边都比基准位大
            s[i],s[j] = s[j],s[i]
            j += 1
    s[pivot],s[j-1] = s[j-1],s[pivot]
    pivot = j-1
    return pivot
'''

'''
#随机快速排序

def quicksortpivot(s,start,end):
    randidx = random.randint(start,end)
    s[start],s[randidx] = s[randidx],s[start] #随机选取一个量来替代左边的基量，避免出现序列有序状态时，快速排序中所划分出的两个子序列中一个没有元素
    pivot = start                             #一个则比原来少一个元素，引入一个随机变量破坏这种有序状态
    j = start+1
    for i in range(start+1,end+1):
        if s[i] <= s[pivot]:
            s[i],s[j] = s[j],s[i]
            j += 1
    s[pivot], s[j - 1] = s[j - 1], s[pivot]
    pivot = j - 1
    return pivot


def quicksort(s,start,end):
    if start >= end:
        return
    pivot = quicksortpivot(s,start,end)
    quicksort(s,start,pivot-1)
    quicksort(s,pivot+1,end)

#quicksort(nums,0,7)

#希尔排序
def shellsort(s):
    n = len(s)
    gap = n//2
    while gap>0:
        for i in range(gap,n):
            x = s[i]
            j = i
            while j>=gap: #判断i i+gap对应元素的大小，如果右边元素小于左边元素就交换次序
                if x < s[j-gap]:
                    s[j] = s[j-gap]
                else:
                    break
                j -= gap
            s[j] = x
        gap //= 2

#堆排序
def maxheapify(heap,start,end):
    son = start*2
    while son<=end:
        if son+1 <= end and heap[son+1]>heap[son]:
            son += 1
        if heap[son] > heap[start]:
            heap[start],heap[son] = heap[son],heap[start]
            start,son = son,son*2
        else:
            break

def heapsort(s):
    heap = [None]+s
    root = 1
    l = len(heap)
    for i in range(l//2,root-1,-1):
        maxheapify(heap,i,l-1)
    for i in range(l-1,root,-1):
        heap[i],heap[root] = heap[root],heap[i]
        maxheapify(heap,root,i-1)

    return heap[root:]

print(heapsort(nums))
'''

#leetcode-876-链表的中间节点


#leetcode-383-赎金信
def main(ransomNote,magazine):

#法一：直接暴力 先将其转换为列表 移除ransomNote与manazine相同的字符 在判断ransomNote长度 若为0 说明能够构成

    # ransomNote = list(ransomNote)
    # magazine = list(magazine)
    # for i in range(len(magazine)):
    #     if magazine[i] in ransomNote:
    #         ransomNote.remove(magazine[i])
    # if len(ransomNote) == 0:
    #     return True
    # else:
    #     return False

#法2 思路与法1类似 先将ransomNote处理为集合 缩小搜索范围 然后判断ransomNote中的字符数与magazine中对应的字符数目 若大于 则不能构成

   l = set(list(ransomNote))
   for i in l:
       if ransomNote.count(i) > magazine.count(i):
           return False
   return True

if __name__ == "__main__":
    ransomNote = "aaaab"
    magazine = "baa"
    print(main(ransomNote,magazine))
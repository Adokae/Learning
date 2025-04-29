# 堆排序
# 索引为i的节点(非叶子节点)的父节点是[i-1]/2，左子节点是2*i+1，右子节点是2*i+2
# 索引为i的节点(非根节点)的根节点下标是(i-1)/2(向下取整)
# 下面是用大顶堆实现推排序算法(用顺序存储表示堆)

class MaxHeap:
    def __init__(self):
        self.max_heap = []

    def peek(self):
        # 访问堆顶元素，若堆为空，返回空；否则，返回堆的首个元素
        if not self.max_heap:
            return None
        return self.max_heap[0]

    # push和shift_up函数用来向堆中插入元素
    def push(self, val):
        self.max_heap.append(val)  # 将新元素插入到堆的末尾
        size = len(self.max_heap)
        self.shift_up(size-1)
    #  从新插入元素节点开始，将该节点与其父节点比较，若新节点的值大于其父节点值，交换位置
    #  否则，结束；重复上述步骤，直到新节点不大于其父节点或达到堆的根节点

    def shift_up(self, i):
        # 但未超出节点范围，且子节点大于父节点，交换该子节点与父节点的值
        while (i-1)//2 >= 0 and self.max_heap[i] > self.max_heap[(i-1)//2]:
            self.max_heap[i], self.max_heap[(i-1)//2] = self.max_heap[(i-1)//2], self.max_heap[i]
            i = (i-1)//2

    # pop和shift_down函数用来删除堆顶元素
    def pop(self):
        # 若堆未空，手动抛出异常：堆未空，否则继续删除操作
        if not self.max_heap:
            raise IndexError("堆为空")
        size = len(self.max_heap)
        self.max_heap[0], self.max_heap[size-1] = self.max_heap[size-1], self.max_heap[0]  # 堆顶元素与堆末尾元素交换
        val = self.max_heap.pop()  # 删除末尾元素，堆长度相应减1，返回所删除的元素，即最大元素
        size -= 1
        self.shift_down(0, size)
        return val

    def shift_down(self, i, n):
        # 最开始输入i是堆顶元素，n表示堆的长度，用于重新调整堆结构，使其满足最大堆的要求
        # 调整节点i与其两个子节点的大小顺序
        while 2*i+1 < n:
            left, right = 2*i+1, 2*i+2
            # 第一个if-else 用来判断较大的子节点
            if 2*i+2 >= n:
                larger = left  # 右子节点超出堆索引，larger就为left
            else:
                if self.max_heap[left] >= self.max_heap[right]:
                    larger = left
                else:
                    larger = right
            # 若当前节点的值小于其子节点值，交换其位置
            if self.max_heap[i] < self.max_heap[larger]:
                self.max_heap[i], self.max_heap[larger] = self.max_heap[larger], self.max_heap[i]
                i = larger
            else:
                break

    def buildMaxHeap(self, nums):
        # 创建一个数组实现堆结构，将原始数组元素依次存入堆结构数组中
        size = len(nums)
        for i in range(size):
            self.max_heap.append(nums[i])
        # size是整个数组长，数组最大索引为size-1，最大索引所对应的根节点为(size-1-1)/2
        for i in range((size-2)//2, -1, -1):
            self.shift_down(i, size)

    def maxHeapSort(self, nums):
        self.buildMaxHeap(nums)
        size = len(self.max_heap)
        for i in range(size-1, -1, -1):
            self.max_heap[0], self.max_heap[i] = self.max_heap[i], self.max_heap[0]  # 交换堆顶与堆底元素位置
            self.shift_down(0, i)  # 重新调整位置,调整的位置是从[0,i]的位置，不在考虑堆底元素
        return self.max_heap


class Solution:
    def maxHeapSort(self, nums):
        return MaxHeap().maxHeapSort(nums)

    def sortArray(self, nums):
        return self.maxHeapSort(nums)


if __name__ == "__main__":
    nums = [3, 8, 5, 1, 2, 9]
    # [10, 25, 6, 8, 7, 1, 20, 23, 16, 19, 17, 3, 18, 14]
    print(Solution().sortArray(nums))

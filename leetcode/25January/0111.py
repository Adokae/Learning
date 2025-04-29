# 170 交易逆序对的总数
"""
如果前一天以股价高于后一天的股价，则可认为存在一个交易逆序对。
输入一段时间内的股票交易记录record，返回其中存在的交易逆序对总数
"""

"""
自己思路：遍历(两个for循环，超时)
    for i in range(len(record)-1):
        for j in range(i, len(record)):
            if record[i] > record[j]:
                count += 1
官方题解思路1：
基于归并排序的分治思想，在合并两个子序列时，使用lPtr和rPtr分别指向左边子序列、右边子序列的第一个元素
计算逆序对的时候，若lPtr指向的数字小于rPtr，但比[0,...,rPtr-1]大，此时贡献rPtr个逆序对

"""


# 官方题解1
def mergeSort(record, tmp, l, r):
    if l >= r:
        return 0
    mid = (l+r)//2
    inv_count = mergeSort(record, tmp, l, mid) + mergeSort(record, tmp, mid+1, r)
    i, j, pos = l, mid+1, l
    while i <= mid and j <= r:
        if record[i] <= record[j]:
            tmp[pos] = record[i]
            i += 1
            inv_count += (j-(mid+1))
        else:
            tmp[pos] = record[j]
            j += 1
        pos += 1
    for k in range(i, mid+1):
        tmp[pos] = record[k]
        inv_count += (j-(mid+1))
        pos += 1
    for k in range(j, r+1):
        tmp[pos] = record[k]
        pos += 1
    record[l:r+1] = tmp[l:r+1]
    return inv_count


def reversePairs(record):
    n = len(record)
    tmp = [0]*n  # 最开始输入的是列表，排序前的空列表，
    return mergeSort(record, tmp, 0, n-1)


if __name__ == "__main__":
    record = [9, 7, 5, 4, 6]
    print(reversePairs(record))

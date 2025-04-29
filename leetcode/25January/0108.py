# 506 相对名次
"""
题目描述：
整数数组score表示运动员的得分，所有得分互不相同，数组长度为n
根据运动员的得分决定名次，得分越高名次越高
第一名得金牌"Gold Medal"，第二名获银牌"Silver Medal"，第三名获铜牌"Bronze Medal"
第四名到第n的运动员，获得名次编号"x"
使用长度为n的数组answer返回获奖情况
"""

# 自己的思路：先排序，在确定名次
"""
    size = len(score)
    answer = score[:]
    gap = size//2
    while gap > 0:
        for i in range(gap, size):
            temp = score[i]
            j = i
            while j >= gap and score[j-gap] < temp:
                score[j-gap], score[j] = score[j], score[j-gap]
                j -= gap
            score[j] = temp
        gap = gap//2
    for k in range(size):
        element = answer[k]
        index = score.index(element)
        if index == 0:
            answer[k] = "Gold Medal"
        elif index == 1:
            answer[k] = "Silver Medal"
        elif index == 2:
            answer[k] = "Bronze Medal"
        else:
            answer[k] = str(index+1)
"""


def findRelativeRanks(score):
    desc = ("Gold Medal", "Silver Medal", "Bronze Medal")
    answer = [""]*len(score)
    # enumerate(score)将score中每个元素与其对应的索引一起打包成一个元组，元组中第一个元素是索引，第二个元素是分数值
    # sorted()是对enumerate()的结果进行排序，排序依据是-x[1]，x[1]表示取元组中的第二个元素，即分数值，-x[1]表示取负数，即逆序排列
    arr = sorted(enumerate(score), key=lambda x: -x[1])  # 最终得到的是按分数从大到小排列，元组的第一个元素表示索引值
    # idx表示分数值的原始索引，i表示排序后的元素索引
    for i, (idx, _) in enumerate(arr):
        answer[idx] = desc[i] if i < 3 else str(i+1)
    return answer


if __name__ == "__main__":
    score = [10, 3, 8, 9, 4]
    # [5, 4, 3, 2, 1]
    print(findRelativeRanks(score))

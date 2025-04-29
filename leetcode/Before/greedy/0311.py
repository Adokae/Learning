# 贪心算法


# leetcode 455 分发饼干
# def main(g, s):
#     g.sort()
#     s.sort()
#     sum = 0
#     if len(s) == 0:
#         return sum
#     else:
#         i_index = 0
#         j_index = 0
#         while i_index <= len(g)-1 and j_index <= len(s)-1:
#             if g[i_index] <= s[j_index]:
#                 sum += 1
#                 i_index += 1
#                 j_index += 1
#             else:
#                 j_index += 1
#         return sum
# g = [1, 2]
# s = [1, 2, 3]
# print(main(g, s))

# 无重叠区间
"""
转换为总区间个数-不重叠区间的最多个数
就计算不重叠区间 比较当前不重叠区间的右边值 跟后面区间的左边值比较
"""


def main(intervals):
    intervals.sort()
    end_pos = intervals[0][1]
    count = 1
    for i in range(1, len(intervals)):
        if end_pos <= intervals[i][0]:
            end_pos = intervals[i][0]
            count += 1
    return len(intervals)-count


if __name__ == "__main__":
    intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
    print(main(intervals))

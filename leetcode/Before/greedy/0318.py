# 力扣 860 柠檬水找零

def Change(bills):
    count_5 = 0
    count_10 = 0
    count_20 = 0
    for i in bills:
        if i == 5:
            count_5 += 1
        elif i == 10:
            count_5 -= 1
            count_10 += 1
        else:
            count_20 += 1
            if count_10 > 0 and count_5 > 0:
                count_10 -= 1
                count_5 -= 1
            elif count_5 > 0 and count_10 == 0:
                count_5 -= 3
            else:
                return False
        if count_5 < 0 or count_10 < 0:
            return False
    return True


if __name__ == "__main__":
    bills = [5, 5, 5, 10, 20]
    print(Change(bills))

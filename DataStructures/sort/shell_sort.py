import random

# 希尔排序，每次交换的两个元素，有一定的间隔，消除的逆序对不只一个
# 时间复杂度 O(n^(1.3-2))
def shellSort(li):
    gap = len(li) // 2
    while gap > 0:
        for i in range(gap, len(li)):
            tmp = li[i]
            j = i - gap
            # 插入
            while j >= 0 and li[j] > tmp:
                li[j + gap] = li[j]
                j -= gap
            li[j + gap] = tmp
        gap = gap // 2  # 原始希尔排序增量序列，每次整除2，直至1


if __name__ == '__main__':
    li = list(range(10000))
    random.shuffle(li)
    shellSort(li)
    print(li)
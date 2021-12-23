# 假设输入数据应该尽可能地均匀分布在每个桶中, 时间复杂度为 O(n) 假如桶数量合适，n 的常数项比较大
# 将元素插入到不同的桶里，对每个桶里的元素进行排序

def bucketSort(nums, bucketAmount=100):

    buckets = [[] for _ in range(bucketAmount)] # 创建桶
    minValue = min(nums)
    maxValue = max(nums)
    length = maxValue - minValue + 1
    gap = length // bucketAmount  # 桶和桶之间的间距
    for num in nums:
        # 装桶
        i = min((num - minValue) // gap, bucketAmount - 1)
        buckets[i].append(num)
        # 桶内排序，借助其他排序算法，这里是插入排序
        j = len(buckets[i]) - 2
        while j >= 0 and buckets[i][j] > num:
            buckets[i][j + 1] = buckets[i][j]
            j -= 1
        buckets[i][j + 1] = num

    # 将桶拼到一起
    nums.clear()
    for buc in buckets:
        nums.extend(buc)


if __name__ == '__main__':
    import random
    nums = [random.randint(0, 10000) for i in range(100)]
    bucketSort(nums)
    print(nums)

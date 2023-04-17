# 倒序遍历的计数排序，时间复杂度O(n + k) (k 是整数的范围大小)
def countingSort(nums):
    if len(nums) <= 1:
        return
    minValue = min(nums)
    maxValue = max(nums)
    length = maxValue - minValue + 1 # 计数范围
    
    count = [0 for _ in range(length)]
    for num in nums:
        count[num - minValue] += 1
    # 每个元素在结果数组中的最后一个下标位置 = 前面比自己小的数字的总数 + 自己的数量 - 1
    for i in range(1, length):
        count[i] += count[i-1]
    result = [0 for _ in range(len(nums))]
    for num in nums[::-1]:
        count[num - minValue] -= 1
        result[count[num-minValue]] = num
    for i in range(len(nums)):
        nums[i] = result[i]

if __name__ == '__main__':
    import random
    li = [random.randint(0, 100) for _ in range(100)]
    print(li)
    countingSort(li)
    print(li)
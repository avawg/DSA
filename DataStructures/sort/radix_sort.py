# 基数排序 LSD (Least significant digital) 最低位优先实现
# 时间复杂度为 O(d * (n + k)) (d 表示最长数字的位数，k 表示每个基数可能的取值范围大小)
def radixSort(nums):
    # 计算最大数字的长度
    max_num = 0
    for num in nums:
        max_num = max(max_num, abs(num))
    maxDigitLength = 0
    while max_num != 0:
        maxDigitLength += 1
        max_num //= 10
    # 使用计数排序算法对基数进行排序
    dev = 1  # 除数
    count = [0 for _ in range(19)]  #
    result = [0 for _ in range(len(nums))]
    for _ in range(maxDigitLength):
        for num in nums:
            # 求基数 位: 个, 十, 百, 千...  下标 [0, 18] 对应基数 [-9, 9]
            # python 负数求模 取余不一致
            radix = (num // dev % 10 if num >= 0 else 0 -
                     abs(num) // dev % 10) + 9
            count[radix] += 1
        for i in range(1, 19):
            count[i] += count[i - 1]
        # 使用倒序遍历的方式完成计数排序
        for num in nums[::-1]:
            radix = (num // dev % 10 if num >= 0 else 0 -
                     abs(num) // dev % 10) + 9
            count[radix] -= 1
            result[count[radix]] = num
        # 将结果拷贝回nums数组
        for i in range(len(nums)):
            nums[i] = result[i]
        dev *= 10
        for i in range(19):
            count[i] = 0


if __name__ == '__main__':
    import random
    nums = [random.randint(-1000, 1000) for _ in range(100)]
    radixSort(nums)
    print(nums)
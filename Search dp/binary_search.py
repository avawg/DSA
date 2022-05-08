# 二分查找 已排好序的列表 时间复杂度O(logn)
import random

# 查找 >= val 的第一个下标
def binary_search(nums, val):
    left, right = 0, len(nums) - 1
    while left < right:
        mid = left + (right - left) // 2
        if nums[mid] >= val:
            right = mid
        else:
            left = mid + 1
    return left if nums[left] >= val else -1

# # 查找 <= val 的最后一个下标
# def binarySearch(nums, val):
#     left, right = 0, len(nums) - 1
#     while left < right:
#         mid = left + (right - left + 1) // 2
#         if nums[mid] <= val:
#             left = mid
#         else:
#             right = mid - 1
#     return left if nums[left] <= val else -1

if __name__ == '__main__':
    nums = list(range(1000000))
    print(binary_search(nums, 25))
    print(binary_search(nums, 216661))
# 二分查找 已排好序的列表 时间复杂度O(logn)
import random
from cal_time import calTime


# 查找等于val的第一个下标
@calTime
def binarySearch(nums, val):
    left, right = 0, len(nums) - 1
    res = -1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == val:
            res = mid
            right = mid - 1
        elif val < nums[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return res


# # 查找等于val的数字下标，所有值不重复
# @calTime
# def binarySearch(nums, val):
#     left, right = 0, len(nums) - 1
#     while left <= right:
#         mid = (left + right) // 2
#         if nums[mid] == val:
#             return mid
#         elif val < nums[mid]:
#             right = mid - 1
#         else:
#             left = mid + 1
#     return -1

# # 查找等于val的最后一个下标
# @calTime
# def binarySearch(nums, val):
#     left, right = 0, len(nums) - 1
#     res = -1
#     while left <= right:
#         mid = (left + right) // 2
#         if nums[mid] == val:
#             res = mid
#             left = mid + 1
#         elif val < nums[mid]:
#             right = mid - 1
#         else:
#             left = mid + 1
#     return res

if __name__ == '__main__':
    nums = list(range(1000000))
    print(binarySearch(nums, 25))
    print(binarySearch(nums, 216661))
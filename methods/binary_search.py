from typing import List


# find a number in sorted array nums[]
def binary_search1(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums) - 1  ###
    while left <= right:  ###
        mid = int((left + right) / 2)
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1  ###
        elif nums[mid] > target:
            right = mid - 1  ###
    return -1


def binary_search2(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums)  ###
    while left < right:  ###
        mid = int((left + right) / 2)
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1  ###
        elif nums[mid] > target:
            right = mid  ###
    return -1


# find the left bound of target when there are several targets
def left_bound1(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums)
    while left < right:
        mid = int((left + right) / 2)
        if nums[mid] >= target:
            right = mid
        elif nums[mid] < target:
            left = mid + 1
    if left == len(nums) or nums[left] != target:
        return -1
    else:
        return left


def left_bound2(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums)-1
    while left <= right:
        mid = int((left + right) / 2)
        if nums[mid] >= target:
            right = mid - 1
        elif nums[mid] < target:
            left = mid + 1
    if left == len(nums) or nums[left] != target:
        return -1
    else:
        return left


# find the left bound of target when there are several targets
def right_bound1(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums)
    while left < right:
        mid = int((left + right) / 2)
        if nums[mid] <= target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid
    if left == 0 or nums[left-1] != target:
        return -1
    else:
        return left-1


def right_bound2(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums)-1
    while left <= right:
        mid = int((left + right) / 2)
        if nums[mid] <= target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
    if left == 0 or nums[left - 1] != target:
        return -1
    else:
        return left - 1

nums = [1, 2, 2, 2, 3]
res1 = binary_search2(nums, 2)
res2 = left_bound2(nums, 2)
res3 = right_bound2(nums, 2)
print(res3)

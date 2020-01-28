from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == val:
                del nums[i]
            else:
                i += 1
        return len(nums)

    def removeElement_2(self, nums: List[int], val: int) -> int:
        cnt = 0
        for i in range(len(nums)):
            if nums[i] == val:
                cnt += 1
            else:
                 nums[i-cnt] = nums[i]
        return len(nums) - cnt

    def removeElement_3(self, nums: List[int], val: int) -> int:
        cnt = 0  # counter of valid elements
        for i in range(len(nums)):
            if nums[i] != val:
                nums[cnt] = nums[i]
                cnt += 1
        return cnt

slt = Solution()
nums = [3, 2, 2, 3]
val = 3
res = slt.removeElement_3(nums, val)
print(nums[0:res])
print(res)
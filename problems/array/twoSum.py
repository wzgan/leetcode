from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        for x in range(len(nums)):
            if target-nums[x] in hash:
                return [hash[target-nums[x]], x]
            else:
                hash[nums[x]] = x
        return []


slt = Solution()
nums = [2, 7, 11, 15]
target = 9
res = slt.twoSum(nums, target)
print(res)
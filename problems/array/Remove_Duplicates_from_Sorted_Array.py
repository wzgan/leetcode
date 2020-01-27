from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums)-1:
            i += 1
            if(nums[i] == nums[i-1]):
                del nums[i]
                i -= 1
        return len(nums)


slt = Solution()
nums = [0,0,1,1,1,2,2,3,3,4]
res = slt.removeDuplicates(nums)
print(res)
print(nums)

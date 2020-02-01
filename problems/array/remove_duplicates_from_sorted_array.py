from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums)-1:
            if(nums[i] == nums[i+1]):
                del nums[i+1]
            else:
                i += 1
        return len(nums)

    def removeDuplicates2(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                cnt += 1
            else:
                nums[i+1-cnt] = nums[i+1]
        return len(nums) - cnt

slt = Solution()
nums = [0,0,1,1,1,2,2,3,3,4]
res = slt.removeDuplicates2(nums)
print(res)
print(nums)

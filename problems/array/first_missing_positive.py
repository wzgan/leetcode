from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        print(nums)
        if len(nums) == 0:
            return 1
        if nums[-1] <= 0:
            return 1
        for i in range(len(nums)):
            if nums[i] > 0:
                if (i == 0 or nums[i - 1] <= 0) and nums[i] > 1:
                    return 1
                if i == len(nums) - 1 or (nums[i + 1] - nums[i]) > 1:
                    return nums[i] + 1


# put the valid number in corresponding position
# boundary condition: 1 ~ len(nums) are all contained in nums
    def firstMissingPositive2(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 1

        i = 0
        while i < len(nums):
            # to switch the number in [i] to correct position,
            # until the position already has corresponding number,
            # or the number in [i] is invalid
            # to make sure every valid number in correct position
            if 0 < nums[i] <= len(nums) and nums[nums[i]-1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
            else:
                i += 1

        for j in range(len(nums)):
            if nums[j] != j + 1:
                return j + 1
        return j + 2


slt = Solution()
nums = [1, 1, 1]
res = slt.firstMissingPositive2(nums)
print(res)

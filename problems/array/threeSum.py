from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []

        for i in range(len(nums) - 2):
            if i > 0 and nums[i - 1] == nums[i]:
                continue

            if nums[i] > 0:
                break

            target = 0 - nums[i]
            l, r = i + 1, len(nums) - 1
            while l < r:
                if (nums[l] + nums[r] == target):
                    if (l == i + 1) \
                            or (r == len(nums) - 1) \
                            or (nums[l] != nums[l - 1]) \
                            or (nums[r] != nums[r + 1]):
                        res.append([nums[i], nums[l], nums[r]])
                    l, r = l + 1, r - 1
                elif (nums[l] + nums[r] > target):
                    r -= 1
                else:
                    l += 1

        return res

slt = Solution()
nums = [-1, 0, 1, 2, -1, -4]
res = slt.threeSum(nums)
print(res)

from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = nums[0] + nums[1] + nums[2]

        for i in range(len(nums)-2):
            l, r = i+1, len(nums)-1
            while l < r:
                sum = nums[l] + nums[r] + nums[i]

                if sum == target:
                    return target

                if abs(sum - target) < abs(res - target):
                    res = sum

                if sum < target:
                    l += 1
                elif sum > target:
                    r -= 1
        return res


array = [0, 1, 2]
slt = Solution()
res = slt.threeSumClosest(array, 0)
print(res)
from typing import List

class Solution:
    def rotate1(self, nums: List[int], k: int) -> None:
        k = k % len(nums)
        #nums[:] = nums[-k:] + nums[:len(nums)-k] # wrong when k==0
        nums[:] = nums[-k:] + nums[:-k]

    def rotate2(self, nums: List[int], k: int) -> None:
        def reverse(nums: List[int], start: int, end: int) -> None:
            if start < 0 or end < 0:
                return
            # while start < end:
            #     temp = nums[start]
            #     nums[start] = nums[end]
            #     nums[end] = temp
            #     start += 1
            #     end -= 1
            while start < end:
                nums[start], nums[end] = nums[end], nums[start]
                start, end = start + 1, end - 1

        k = k % len(nums)
        reverse(nums, 0, len(nums)-k-1)
        reverse(nums, len(nums)-k, len(nums)-1)
        reverse(nums, 0, len(nums)-1)

    def rotate3(self, nums: List[int], k: int) -> None:
        k = k % len(nums)
        nums[ :len(nums)-k] = nums[-k-1: : -1]
        nums[len(nums)-k: ] = nums[ : -k-1: -1]
        nums.reverse()

slt = Solution()
nums = [1, 2, 3, 4, 5, 6, 7]
slt.rotate2(nums, 3)
print(nums)



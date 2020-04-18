# https://leetcode.com/problems/h-index-ii/description/
from typing import List

class Solution:
    def hIndex1(self, citations: List[int]) -> int:
        for i in range(len(citations)-1, -1, -1):
            if citations[i] < len(citations) - i:
                return len(citations)-i-1
        return len(citations)

    def hIndex2(self, citations: List[int]) -> int:
        l, r, length = 0, len(citations)-1, len(citations)
        while l <= r:
            mid = int((l + r) / 2)
            if citations[mid] == length - mid:
                return length - mid
            elif citations[mid] > length - mid:
                r = mid - 1
            else:
                l = mid + 1
        return length - l


slt = Solution()
citations = [3,3,5,8,25]
res = slt.hIndex1(citations)
print(res)
# https://leetcode.com/problems/h-index/description/
from typing import List

class Solution:
    def hIndex1(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        if len(citations) == 0 or citations[0] == 0:
            return 0
        for i in range(len(citations)):
            if citations[i] < i+1:
                return i
        return i+1

    def hIndex2(self, citations: List[int]) -> int:
        cntList = [0 for _ in range(len(citations)+1)]
        for x in citations:
            if x > len(citations):
                cntList[len(citations)] += 1
            else:
                cntList[x] += 1

        # sum = 0
        # for i in range(len(cntList)):
        #     if i > 0:
        #         sum += cntList[i-1]
        #     total = len(citations)-sum
        #     if total < i:
        #         return i-1
        # return len(citations)

        sum = 0
        for i in range(len(cntList)-1, -1, -1):
            sum += cntList[i]
            if sum >= i:
                return i
        return 0


slt = Solution()
citations = [3,0,6,1,5]
res = slt.hIndex2(citations)
print(res)
# https://leetcode.com/problems/gas-station/description/
from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        list_len = len(gas)
        for i in range(list_len):
            j = i
            gasQuan = 0
            while j < list_len + i:
                gasQuan = gasQuan + gas[j % list_len] - cost[j % list_len]
                if gasQuan < 0:
                    if j >= list_len:   # no solution
                        i = list_len
                    else:               # start point move to the position next to j
                        i = j % list_len
                    break
                j += 1
            if j == i + list_len:
                return i
        return -1

slt = Solution()
gas  = [2,3,4]
cost = [3,4,3]
ret = slt.canCompleteCircuit(gas, cost)
print(ret)
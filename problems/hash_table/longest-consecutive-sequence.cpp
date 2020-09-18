//
// Created by 甘唯哲 on 2020/9/19.
//

//https://leetcode.com/problems/longest-consecutive-sequence/

#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> numsSet;
        for (int num : nums)
        {
            numsSet.insert(num);
        }

        int res = 0;
        while (!numsSet.empty())
        {
            int num = *numsSet.begin();
            numsSet.erase(num);
            int prev = num-1, next = num+1;
            while (numsSet.count(prev))
            {
                numsSet.erase(prev--);
            }

            while (numsSet.count(next))
            {
                numsSet.erase(next++);
            }

            res = std::max(res, next-prev-1);
        }

        return res;
    }
};
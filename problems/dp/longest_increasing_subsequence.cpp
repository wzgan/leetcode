//
// Created by 甘唯哲 on 2020/7/13.
//

// https://leetcode.com/problems/longest-increasing-subsequence/

#include <vector>
//#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        std::vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        int res = 1;
        for (int i = 0; i < dp.size(); i++)
        {
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
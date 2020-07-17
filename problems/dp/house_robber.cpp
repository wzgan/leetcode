//
// Created by 甘唯哲 on 2020/7/18.
//

// https://leetcode.com/problems/house-robber/

#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums)
    {
        int s = nums.size();
        if (s == 0) return 0;
        std::vector<int> dp(s+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 0; i <= s; ++i)
        {
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[s];
    }
};
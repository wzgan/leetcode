//
// Created by 甘唯哲 on 2020/7/13.
//

// https://leetcode.com/problems/maximum-subarray/

#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        std::vector<int> dp(nums);
        dp[0] = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            if (dp[i-1] > 0)
                dp[i] = dp[i-1] + nums[i];
        }

        int res = dp[0];
        for (int j = 0; j < dp.size(); ++j)
        {
            res = std::max(res, dp[j]);
        }
        return res;
    }
};
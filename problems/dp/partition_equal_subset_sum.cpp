//
// Created by 甘唯哲 on 2020/7/14.
//

// https://leetcode.com/problems/partition-equal-subset-sum/

#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int>& nums)
    {
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 2 == 1) return false;

        std::vector<std::vector<bool>> dp(nums.size()+1, std::vector<bool>(sum/2+1, false));
        for (int i = 0; i <= nums.size(); ++i)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i <= nums.size(); ++i)
        {
            for (int j = sum/2; j >= 1; --j)
            {
                if (j < nums[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][sum/2];
    }

    //状态压缩
    bool canPartition2(std::vector<int>& nums)
    {
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 2 == 1) return false;

        std::vector<bool> dp(sum/2+1, false);
        dp[0] = true;

        for (int i = 1; i < nums.size()+1; ++i)
        {
            for (int j = sum/2; j >= 1; --j)
            {
                //if (j < nums[i-1]) dp[j] = dp[j];
                if (j >= nums[i-1])
                    dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[sum/2];
    }
};
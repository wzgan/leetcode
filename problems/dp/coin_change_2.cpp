//
// Created by 甘唯哲 on 2020/7/14.
//

// https://leetcode.com/problems/coin-change-2/

#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins)
    {
        std::vector<std::vector<int>> dp(coins.size()+1, std::vector<int>(amount+1, 0));
        for (int i = 0; i <= coins.size(); ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= coins.size(); ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                if (j < coins[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }

        return dp[coins.size()][amount];
    }

    //空间压缩
    int change2(int amount, std::vector<int>& coins)
    {
        std::vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= coins.size(); ++i)
        {
            for (int j = 1; j < amount; ++j)
            {
                if (j >= coins[i-1])
                    dp[j] = dp[j] + dp[j-coins[i-1]];
            }
        }

        return dp[amount];
    }
};
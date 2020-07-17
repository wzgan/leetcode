//
// Created by 甘唯哲 on 2020/7/18.
//

// https://leetcode.com/problems/longest-common-subsequence/

#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        int s1 = text1.size();
        int s2 = text2.size();
        std::vector<std::vector<int>> dp(s1+1, std::vector<int>(s2+1, 0));

        for (int i = 1; i <= s1; ++i)
        {
            for (int j = 1; j <= s2; ++j)
            {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
            }
        }

        return dp[s1][s2];
    }
};
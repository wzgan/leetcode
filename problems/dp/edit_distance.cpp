//
// Created by 甘唯哲 on 2020/7/15.
//

// https://leetcode.com/problems/edit-distance/

#include <string>
#include <vector>

class Solution {
public:
    int dp(std::string& word1, std::string& word2, int i, int j,
            std::vector<std::vector<int>>& memo)
    {
        if (i == -1) return j+1;
        if (j == -1) return i+1;

        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if (word1[i] == word2[j])
        {
            memo[i][j] = dp(word1, word2, i-1, j-1, memo);
        }
        else
        {
            int res = std::min(dp(word1, word2, i-1, j-1, memo) + 1, dp(word1, word2, i-1 ,j, memo) + 1);
            memo[i][j] = std::min(res, dp(word1, word2, i, j-1, memo) + 1);
        }
        return memo[i][j];
    }

    int minDistance1(std::string word1, std::string word2)
    {
        std::vector<std::vector<int>> memo(word1.size(), std::vector<int>(word2.size(), -1));
        return dp(word1, word2, word1.size()-1, word2.size()-1, memo);
    }


    int minDistance2(std::string word1, std::string word2)
    {
        int m = word1.size(), n = word2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                } else
                {
                    dp[i][j] = std::min(1 + dp[i][j-1], 1 + dp[i-1][j]);
                    dp[i][j] = std::min(dp[i][j], 1 + dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    //空间压缩
    int minDistance3(std::string word1, std::string word2)
    {

    }
};
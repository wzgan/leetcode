//
// Created by 甘唯哲 on 2020/7/19.
//

// https://leetcode.com/problems/longest-palindromic-subsequence/


#include <string>
#include <vector>


class Solution {
public:
    int longestPalindromeSubseq(std::string s)
    {
        int sz = s.size();
        std::vector<std::vector<int>> dp(sz+1, std::vector<int>(sz+1, 0));
        for (int i = 0; i <= sz; ++i)
        {
            dp[i][i] = 1;
        }

//        for (int i = sz-1; i >= 1; --i)
//        {
//            for (int j = i+1; j <= sz; ++j)
//            {
//                if (s[i-1] == s[j-1])
//                    dp[i][j] = dp[i+1][j-1] + 2;
//                else
//                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
//            }
//        }

        //斜向遍历
        for (int k = 2; k <= sz; ++k)
        {
            for (int i = 1, j = k; j <= sz; ++i, ++j)
            {
                if (s[i-1] == s[j-1])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[1][sz];
    }
};
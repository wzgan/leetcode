//
// Created by 甘唯哲 on 2020/7/23.
//
#include <string>
#include <vector>

//返回最长公共子串
class Solution
{
public:
    std::string longestCommonSubstring(std::string s1, std::string s2)
    {
        int sz1 = s1.size(), sz2 = s2.size();
        std::vector<std::vector<std::string>> dp(sz1+1, std::vector<std::string>(sz2+1, ""));

        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else
                    dp[i][j] = "";
            }
        }

        int maxLen = 0;
        int maxi = 0, maxj = 0;
        for (int i = 0; i <= sz1; ++i)
        {
            for (int j = 0; j <= sz2; ++j)
            {
                if (dp[i][j].size() > maxLen)
                {
                    maxLen = dp[i][j].size();
                    maxi = i;
                    maxj = j;
                }
            }
        }
        return dp[maxi][maxj];
    }
};

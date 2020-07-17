//
// Created by 甘唯哲 on 2020/7/16.
//

// https://leetcode.com/problems/super-egg-drop/

#include <vector>

class Solution {
public:
    int superEggDrop(int K, int N)
    {
        std::vector<std::vector<int>> dp(K+1, std::vector<int>(N+1, N));
        for (int i = 1; i <= K; ++i)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= N; ++j)
        {
            dp[1][j] = j;
        }

        for (int i = 2; i <= K; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
//                for (int k = 1; k <= j; ++k)
//                {
//                    dp[i][j] = std::min(dp[i][j], 1 + std::max(dp[i][j-k], dp[i-1][k-1]));
//                }
                int l = 1, r = j;
                int res = N+1;
                while (l <= r)
                {
                    int mid = (l + r)/2;
                    int b = dp[i-1][mid-1];
                    int nb = dp[i][j-mid];
                    if (b > nb)
                    {
                        r = mid-1;
                        res = std::min(res, 1 + b);
                    } else
                    {
                        l = mid+1;
                        res = std::min(res, 1 + nb);
                    }
                }
                dp[i][j] = res;
            }
        }

        return dp[K][N];
    }

    int superEggDrop2(int K, int N)
    {
        std::vector<std::vector<int>> dp(K+1, std::vector<int>(N+1, -1));
        for (int i = 0; i <= K; ++i)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= N; ++j)
        {
            dp[0][j] = 0;
        }

        int j = 0;
//        for (j = 1; dp[K][j] < N; ++j)
        while (dp[K][j] < N)
        {
            j++;
            for (int i = 1; i <= K; ++i)
            {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1;
            }
        }
        return j;
    }
};
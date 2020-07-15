//
// Created by 甘唯哲 on 2020/7/11.
//

#include <vector>

// 重叠子问题的剪枝：记录子问题的结果
int fib(int N)
{
    if (N <= 2) return 1;
    return fib(N-1) + fib(N-2);
}


//自顶向下
int helper(int N, std::vector<int>& memo)
{
    if (N <= 2) return 1;
    if (memo[N] != 0) return memo[N];
    memo[N] = helper(N - 1, memo) + helper(N - 2, memo);
    return memo[N];
}

int fib2(int N)
{
    if (N < 1) return 0;
    std::vector<int> memo(N+1, 0);
    return helper(N, memo);
}


//自底向上
int fib3(int N)
{
    std::vector<int> dp(N+1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}

//状态压缩：将dp数组进行压缩
int fib3_1(int N)
{
    if (N <= 2) return 1;
    int pre1 = 1, pre2 = 1; int sum = 0;
    for (int i = 3; i <= N; ++i)
    {
        sum = pre1 + pre2;
        pre2 = pre1;
        pre1 = sum;
    }
    return sum;
}


//
// 凑零钱问题
//
int coinChange(std::vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int res = amount + 1;
    for (int i = 0; i < coins.size(); ++i)
    {
        int subRes = coinChange(coins, amount - coins[i]);
        if (subRes == -1) continue;
        res = std::min(res, 1 + subRes);
    }
    return res;
}

//加入备忘录
int coinChange2(std::vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    std::vector<int> dp(amount+1, amount + 1);
    if (dp[amount] != amount + 1) return dp[amount];
    int res = amount + 1;
    for (int i = 0; i < coins.size(); ++i)
    {
        int subRes = coinChange(coins, amount - coins[i]);
        if (subRes < -1) continue;
        res = std::min(res, 1 + subRes);
    }
    dp[amount] = res == amount + 1 ? -1 : res;
    return res;
}

//自底向上迭代
int coinChange3(std::vector<int>& coins, int amount)
{
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < coins.size(); ++j)
        {
            if (i - coins[j] < 0) continue;
            dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

//按照完全背包问题(coins change 2)的递推关系式
int coinsChange4(std::vector<int>& coins, int amount)
{
    std::vector<std::vector<int>> dp(coins.size()+1, std::vector<int>(amount+1, amount+1));
    for (int i = 0; i <= coins.size() ; ++i)
    {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= amount; ++j)
    {
        dp[0][j] = amount + 1;
    }
    for (int i = 1; i <= coins.size() ; ++i)
    {
        for (int j = 1; j <= amount; ++j)
        {
            if (j < coins[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = std::min(dp[i-1][j], 1 + dp[i][j-coins[j-1]]);
        }
    }
    return dp[coins.size()][amount] == amount + 1 ? -1 : dp[coins.size()][amount];
}

//
//背包问题
//dp[i][j]: 前i个物品放入容量为j的背包的最大价值
//
int knapsack(int W, int N, std::vector<int>& wt, std::vector<int>& val)
{
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            if (j < wt[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
        }
    }
    return dp[N][W];
}

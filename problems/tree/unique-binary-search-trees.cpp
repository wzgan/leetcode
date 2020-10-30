//https://leetcode.com/problems/unique-binary-search-trees/

#include <vector>

class Solution {
public:
    int numTrees(int n) 
    {
        std::vector<int> memo(n+1, 0);
        memo[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
        	int res = 2*memo[i-1];
        	for (int j = 1; j <= i-2; ++j)
        	{
        		res += memo[j] * memo[i-j-1];
        	}
        	memo[i] = res;
        }
        return memo[n];
    }
};


//
// Created by 甘唯哲 on 2020/7/22.
//

// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>

class Solution {
public:
    std::vector<int> direction{-1, 0, 1, 0, -1};

    void dfs(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& can_reach, int row, int col)
    {
        can_reach[row][col] = true;

        for (int i = 0; i < 4; ++i)
        {
            int r = row + direction[i], c = col + direction[i+1];
            if (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size())
            {
                if (matrix[r][c] >= matrix[row][col] && !can_reach[r][c])
                    dfs(matrix, can_reach, r, c);
            }
        }
    }

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) 
    {
        if (matrix.empty())
            return std::vector<std::vector<int>>();

        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<bool>> can_reach_p(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> can_reach_a(m, std::vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            dfs(matrix, can_reach_p, i, 0);
            dfs(matrix, can_reach_a, i, n-1);
        }
        for (int i = 0; i < n; ++i)
        {
            dfs(matrix, can_reach_p, 0, i);
            dfs(matrix, can_reach_a, m-1, i);
        }

        std::vector<std::vector<int>> res;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (can_reach_a[i][j] && can_reach_p[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
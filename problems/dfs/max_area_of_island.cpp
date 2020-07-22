//
// Created by 甘唯哲 on 2020/7/22.
//

// https://leetcode.com/problems/max-area-of-island/

#include <vector>
#include <stack>

class Solution {
public:
    int dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& isVisited,
            int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return 0;

        if (isVisited[row][col] || grid[row][col] == 0)
            return 0;

        isVisited[row][col] = true;

        int res = 1;
        res += dfs(grid, isVisited, row+1, col);
        res += dfs(grid, isVisited, row-1, col);
        res += dfs(grid, isVisited, row, col+1);
        res += dfs(grid, isVisited, row, col-1);

        return res;
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<bool>> isVisited(m, std::vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!isVisited[i][j] && grid[i][j] == 1)
                    res = std::max(res,dfs(grid, isVisited, i, j));
            }
        }
        return res;
    }

    //iteration
    int maxAreaOfIsland2(std::vector<std::vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    //dfs
                    int area = 0;
                    std::stack<std::pair<int, int>> s;
                    s.push({i, j});
                    while (!s.empty())
                    {
                        int r = s.top().first, c = s.top().second;
                        s.pop();
                        if (r < 0 || r >= m || c < 0 || c >= n)
                        {
                            continue;
                        }
                        if (grid[r][c] == 0)
                        {
                            continue;
                        }

                        area += 1;
                        grid[r][c] = 0;

                        s.push({r+1, c});
                        s.push({r-1, c});
                        s.push({r, c+1});
                        s.push({r, c-1});
                    }
                    res = std::max(res, area);
                }
            }
        }
        return res;
    }
};
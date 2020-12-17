//
// Created by g23811 on 2020/12/17.
//

//https://leetcode.com/problems/surrounded-regions

#include <vector>

class Solution {
public:
    void dfs(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& bVisited, int row, int col)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        {
            return;
        }

        if (bVisited[row][col] || board[row][col] == 'X')
        {
            return;
        }

        bVisited[row][col] = true;

        dfs(board, bVisited, row+1, col);
        dfs(board, bVisited, row-1, col);
        dfs(board, bVisited, row, col+1);
        dfs(board, bVisited, row, col-1);
    }
    
    void solve(std::vector<std::vector<char>>& board)
    {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> bVisited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O' && !bVisited[i][0])
                dfs(board, bVisited, i, 0);

            if (board[i][n-1] == 'O' && !bVisited[i][n-1])
                dfs(board, bVisited, i, n-1);
        }
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O' && !bVisited[0][j])
                dfs(board, bVisited, 0, j);

            if (board[m-1][j] == 'O' && !bVisited[m-1][j])
                dfs(board, bVisited, m-1, j);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!bVisited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
//
// Created by 甘唯哲 on 2020/7/21.
//

// https://leetcode.com/problems/sudoku-solver/

#include <vector>

class Solution {
public:
    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char ch)
    {
        for (int i = 0; i <= 8; ++i)
        {
            if (board[i][col] == ch)
                return false;

            if (board[row][i] == ch)
                return false;

            if (board[i/3 + row / 3 * 3][i % 3 + col / 3 * 3] == ch)
                return false;
        }

        return true;
    }

    bool backtracking(std::vector<std::vector<char>>& board, int row, int col)
    {
        if (col > 8)
        {
            if (row == 8)
                return true;
            row += 1;
            col = 0;
        }

        if (board[row][col] != '.')
            return backtracking(board, row, col + 1);

        for (char ch = '1'; ch <= '9'; ++ch)
        {
            if (!isValid(board, row, col, ch))
                continue;
            board[row][col] = ch;
            if (backtracking(board, row, col + 1))
                return true;
            board[row][col] = '.';
        }

        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board)
    {
        backtracking(board, 0, 0);
    }
};
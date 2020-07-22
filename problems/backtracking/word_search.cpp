//
// Created by 甘唯哲 on 2020/7/21.
//

// https://leetcode.com/problems/word-search/

#include <vector>
#include <string>

class Solution {
public:
    bool backtracking(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& isVisited,
            std::string& word, int row, int col, int i)
    {
        if (i == word.size())
            return true;

        if (row<0 || row == board.size() || col < 0 || col == board[0].size())
            return false;

        if (isVisited[row][col] || board[row][col] != word[i])
            return false;

        isVisited[row][col] = true;


        if (backtracking(board, isVisited, word, row+1, col, i+1))
            return true;

        if (backtracking(board, isVisited, word, row-1, col, i+1))
            return true;

        if (backtracking(board, isVisited, word, row, col+1, i+1))
            return true;

        if (backtracking(board, isVisited, word, row, col-1, i+1))
            return true;

        isVisited[row][col] = false;
        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        std::vector<std::vector<bool>> isVisited(board.size(), std::vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (backtracking(board, isVisited, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
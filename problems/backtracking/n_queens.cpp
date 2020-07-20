//
// Created by 甘唯哲 on 2020/7/20.
//

// https://leetcode.com/problems/n-queens/

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> res;

    bool isValid(int row, std::vector<std::string>& track, int n)
    {
        int col = track.size();

        for (int i = 0; i <= col-1; ++i)
        {
            if (track[i][row] == 'Q')
                return false;
        }

        for (int i = col-1, j = row-1; (i >= 0)&&(j >= 0); --i, --j)
        {
            if (track[i][j] == 'Q')
                return false;
        }

        for (int i = col-1, j = row+1; (i >= 0)&&(j <= n-1); --i, ++j)
        {
            if (track[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backtracking(int n, std::vector<std::string>& track)
    {
        if (track.size() == n)
        {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (!isValid(i, track, n))
                continue;

            std::string str(n, '.');
            str[i] = 'Q';
            track.push_back(str);
            backtracking(n, track);
            track.pop_back();
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::string> track;
        backtracking(n, track);
        return res;
    }
};
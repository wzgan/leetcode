//
// Created by 甘唯哲 on 2020/7/21.
//

// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> res;

    void backtracking(int left, int right, std::string& track)
    {
        if (left > right)
            return;

        if (left == 0 && right == 0)
        {
            res.push_back(track);
            return;
        }

        if (left > 0)
        {
            track.push_back('(');
            backtracking(left-1, right, track);
            track.pop_back();
        }

        if (right > 0)
        {
            track.push_back(')');
            backtracking(left, right-1, track);
            track.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        std::string track;
        backtracking(3, 3, track);
        return res;
    }
};
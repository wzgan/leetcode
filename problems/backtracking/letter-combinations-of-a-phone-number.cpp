//
// Created by g23811 on 2020/12/16.
//

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/

#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> res;

    void digitToString(const char digit, std::string& str)
    {
        if(digit < '7')
        {
            for(int i = 0; i < 3; ++i)
            {
                str += ('a' + 3*(digit-'2') + i);
            }
        }
        else
        {
            if(digit == '7')    str = "pqrs";
            if(digit == '8')    str = "tuv";
            if(digit == '9')    str = "wxyz";
        }
    }

    void backtrack(const std::string& digits, std::string& track)
    {
        int sz_track = track.length();
        if(sz_track == digits.length())
        {
            res.push_back(track);
            return;
        }

        std::string str;
        digitToString(digits[sz_track], str);
        for(int i = 0; i < str.length(); ++i)
        {
            track += str[i];
            backtrack(digits, track);
            track.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(std::string digits)
    {
        if(digits.length() == 0) return res;
        std::string track;
        backtrack(digits, track);
        return res;
    }
};
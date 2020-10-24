//
// Created by 甘唯哲 on 2020/10/5.
//

//https://leetcode.com/problems/shortest-palindrome/

#include <string>

class Solution {
public:
    std::string shortestPalindrome(std::string s)
    {
        int sz = s.size();
        if(sz == 0) return "";
        int cur = 0;
        while(s[cur] == s[0])
            cur++;
        int maxLen = cur;
        while(cur < sz)
        {
            int l = cur, r = cur;
            while(r+1 < sz && s[r] == s[r+1])
                r++;
            cur = r+1;
            while(l-1 >= 0 && r+1 < sz && s[l-1] == s[r+1])
            {
                l--;
                r++;
            }
            if(l == 0)
                maxLen = r-l+1;
        }
        std::string addStr = s.substr(maxLen, sz-maxLen);
        std::reverse(addStr.begin(), addStr.end());
        return addStr+s;
    }

    //1.reverse the
    std::string shortestPalindrome2(std::string s)
    {

    }
};
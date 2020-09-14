//
// Created by 甘唯哲 on 2020/9/14.
//

//https://leetcode.com/problems/daily-temperatures/

#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& T)
    {
        std::vector<int> res(T.size(), 0);
        std::stack<std::pair<int, int>> s;
        for (int i = T.size()-1; i >= 0; --i)
        {
            while (!s.empty() && s.top().first <= T[i])
            {
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top().second-i;
            s.push(std::make_pair(T[i], i));
        }
        return res;
    }
};
//
// Created by 甘唯哲 on 2020/7/21.
//

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> res;

    void backtracking(int n, int k, std::vector<int>& track)
    {
        if (track.size() == k)
        {
            res.push_back(track);
            return;
        }

        int i = track.empty() ? 1 : track.back()+1;
        for ( ; i <= n; ++i)
        {
            track.push_back(i);
            backtracking(n, k, track);
            track.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<int> track;
        backtracking(n, k, track);
        return res;
    }
};
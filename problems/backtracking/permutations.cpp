//
// Created by 甘唯哲 on 2020/7/20.
//

// https://leetcode.com/problems/permutations/

#include <vector>

class Solution {
public:
    void backtracking(std::vector<int>& nums, std::vector<int>& track, std::vector<std::vector<int>>& res)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (std::find(track.begin(), track.end(), nums[i]) != track.end())
                continue;
            track.push_back(nums[i]);
            backtracking(nums, track, res);
            track.pop_back();
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> track;
        backtracking(nums, track, res);
        return res;
    }
};
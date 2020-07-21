//
// Created by 甘唯哲 on 2020/7/21.
//

// https://leetcode.com/problems/subsets/

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> res;

    void backtracking(std::vector<int>& nums, int start, std::vector<int>& track)
    {
        res.push_back(track);
//        if (!track.empty() && (track.back() == nums.back()))
//            return;

//        auto it = track.empty() ? nums.begin() : ++std::find(nums.begin(), nums.end(), track.back());
        for (int i = start ; i < nums.size(); ++i)
        {
            track.push_back(nums[i]);
//            res.push_back(track);
            backtracking(nums, ++start, track);
            track.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<int> track;
        backtracking(nums, 0, track);
//        res.push_back(std::vector<int>());
        return res;
    }
};
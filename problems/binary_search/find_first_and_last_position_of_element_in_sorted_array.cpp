//
// Created by 甘唯哲 on 2020/7/24.
//

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>

class Solution {
public:
    int lower_bound(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (target > nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        if (left == nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    int upper_bound(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
                right = mid;
            else
                left = mid + 1;
        }
        if (left == 0 || nums[left-1] != target)
            return -1;
        return left-1;
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        std::vector<int> res;
        int lb = lower_bound(nums, target);
        int ub = upper_bound(nums, target);
        res.push_back(lb);
        res.push_back(ub);
        return res;
    }
};
//
// Created by 甘唯哲 on 2020/7/25.
//

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums)
    {
        int left = 0, right = nums.size()-1, res = nums[0];
        while (left <= right)
        {
            int mid = (left + right)/2;
            if (nums[mid] > nums[left])
            {
                left = mid + 1;
                res = std::min(res, nums[left]);
            }
            else if (nums[mid] < nums[left])
            {
                right = mid - 1;
                res = std::min(res, nums[mid]);
            }
            else
            {
                left += 1;
                res = std::min(res, nums[left]);
            }
        }
        return res;
    }
};
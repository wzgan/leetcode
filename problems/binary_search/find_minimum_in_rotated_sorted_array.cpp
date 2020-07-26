//
// Created by 甘唯哲 on 2020/7/25.
//

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums)
    {
        int res = nums[0], left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = (left + right)/2;
            if (nums[mid] <= nums[right])
            {
                right = mid - 1;
                res = std::min(res, nums[mid]);
            }
            else if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
        }
        return res;
    }
};
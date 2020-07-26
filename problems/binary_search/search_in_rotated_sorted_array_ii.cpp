//
// Created by 甘唯哲 on 2020/7/24.
//

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < nums[left]) //右侧有序
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else if (nums[mid] > nums[left]) //左侧有序
            {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if (nums[mid] == nums[left]) //无法确定target的位置
            {
                left += 1;
            }
        }
        return false;
    }
};

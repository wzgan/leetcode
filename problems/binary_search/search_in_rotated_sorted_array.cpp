//
// Created by 甘唯哲 on 2020/7/24.
//

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[left]) //左侧有序
            {
                if (target < nums[mid] && target >= nums[left])
                    right = mid-1;
                else
                    left = mid + 1;
            }
            else if (nums[mid] < nums[left]) //右侧有序
            {
                if (target > nums[mid] && target < nums[left])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return -1;
    }
};
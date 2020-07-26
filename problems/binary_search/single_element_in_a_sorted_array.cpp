//
// Created by 甘唯哲 on 2020/7/26.
//

#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums)
    {
        int left = 0, right = nums.size()-1;

        if (nums.size() == 1)
            return nums[0];

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (mid % 2 != 0)
            {
                if (nums[mid-1] == nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if (mid % 2 == 0)
            {
                if (nums[mid+1] == nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return nums[left];
    }
};
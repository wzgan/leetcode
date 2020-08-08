//
// Created by 甘唯哲 on 2020/8/8.
//

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums)
    {
        int s = nums[0], q = nums[0];

        while (1)
        {
            s = nums[s];
            q = nums[nums[q]];
            if (s == q)
                break;
        }

        s = nums[0];
        while (s != q)
        {
            s = nums[s];
            q = nums[q];
        }

        return s;
    }
};
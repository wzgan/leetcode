//
// Created by 甘唯哲 on 2020/8/8.
//

#include <vector>

class Solution {
public:
    //like a link-list circle
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

    //use index
    int findDuplicate2(std::vector<int>& nums)
    {
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            while (nums[i] != i)
//            {
//                if (nums[nums[i]] == nums[i])
//                    return nums[i];
//                std::swap(nums[i], nums[nums[i]]);
//            }
//        }
        while(1)
        {
            if (nums[nums[0]] == nums[0])
                return nums[0];
            std::swap(nums[0], nums[nums[0]]);
        }
    }
};
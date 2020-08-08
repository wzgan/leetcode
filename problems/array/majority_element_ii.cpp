//
// Created by 甘唯哲 on 2020/8/3.
//

//https://leetcode.com/problems/majority-element-ii/

#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums)
    {
        int candidate1 = 0, candidate2 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == candidate1)
            {
                cnt1++;
            }
            else if (nums[i] == candidate2)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                candidate1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                candidate2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] == candidate1)
                cnt1++;
            if (nums[j] == candidate2)
                cnt2++;
        }

        std::vector<int> res;
        if (cnt1 > nums.size()/3)
            res.push_back(candidate1);
        if (cnt2 > nums.size()/3)
            res.push_back(candidate2);
    }
};
//
// Created by 甘唯哲 on 2020/9/14.
//

// https://leetcode.com/problems/next-greater-element-ii/

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums)
    {
//        std::vector<int> nums_new(nums.size()*2, 0);
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            nums_new[i] = nums[i];
//            nums_new[i+nums.size()] = nums[i];
//        }

        std::vector<int> res(nums.size(), -1);
        std::stack<int> s;
        for (int j = nums.size()*2-1; j >= 0; --j)
        {
            while (!s.empty() && s.top() <= nums[j%nums.size()])
            {
                s.pop();
            }
//            if (j < nums.size())
//            {
//                res[j] = s.empty() ? -1 : s.top();
//            }
            res[j%nums.size()] = s.empty() ? -1 : s.top();
            s.push(nums[j%nums.size()]);
        }
        return res;
    }
};
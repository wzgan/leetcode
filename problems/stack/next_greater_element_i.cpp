//
// Created by 甘唯哲 on 2020/9/5.
//

#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_map<int, int> nums1_map;
        for (int i = 0; i < nums1.size(); ++i)
        {
            nums1_map[nums1[i]] = i;
        }
        std::vector<int> ans(nums1.size(), -1);
        std::stack<int> s;
        for (int i = nums2.size()-1; i >= 0; --i)
        {
            while (!s.empty() && s.top() < nums2[i])
            {
                s.pop();
            }
            if (nums1_map.count(nums2[i]))
            {
                ans[nums1_map[nums2[i]]] = s.empty() ? -1 : s.top();
            }
            s.push(nums2[i]);
        }

        return ans;
    }
};
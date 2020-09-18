//
// Created by 甘唯哲 on 2020/9/18.
//

//https://leetcode.com/problems/sliding-window-maximum/

#include <vector>
#include <set>
#include <queue>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::multiset<int, std::greater<int>> ms;
        for (int i = 0; i < k; ++i)
        {
            ms.insert(nums[i]);
        }

        std::vector<int> res(nums.size()-k+1, INT32_MIN);
        res[0] = *ms.begin();
        for (int j = 1; j <= nums.size()-k; ++j)
        {
            auto iter = ms.find(nums[j-1]);
            ms.erase(iter);
            ms.insert(nums[j+k-1]);
            res[j] = *ms.begin();
        }

        return res;
    }

    std::vector<int> maxSlidingWindow2(std::vector<int>& nums, int k)
    {
        std::deque<int> dq;
        std::vector<int> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!dq.empty() && dq.front() == i-k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k-1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
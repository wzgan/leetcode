//
// Created by 甘唯哲 on 2020/8/7.
//

// https://leetcode.com/problems/top-k-frequent-elements/

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> numsMap;
        std::vector<std::vector<int>> freqVec(nums.size()+1, std::vector<int>());

        for (int i = 0; i < nums.size(); ++i)
        {
            numsMap[nums[i]]++;
            freqVec[numsMap[nums[i]]].push_back(nums[i]);
        }

        std::vector<int> res;
        int cnt = 0;
        for (int j = freqVec.size()-1; cnt < k; --j)
        {
            for (int l = 0; l < freqVec[j].size(); ++l)
            {
                int elem = freqVec[j][l];
                if (numsMap[elem] == j)
                {
                    res.push_back(elem);
                    cnt++;
                }
                if (cnt == k) break;
            }
        }

        return res;
    }
};
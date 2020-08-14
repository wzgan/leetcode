//
// Created by 甘唯哲 on 2020/8/9.
//

// https://leetcode.com/problems/sort-characters-by-frequency/

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string frequencySort(std::string s)
    {
        std::unordered_map<char, int> smap;
        for (int i = 0; i < s.size(); ++i)
        {
            smap[s[i]]++;
        }

        std::vector<std::vector<char>> freqVec(s.size()+1, std::vector<char>());
        for (auto iter = smap.begin(); iter != smap.end(); ++iter)
        {
            freqVec[iter->second].push_back(iter->first);
        }

        std::string res = "";
        for (int j = s.size(); j >= 0; --j)
        {
            for (int k = 0; k < freqVec[j].size(); ++k)
            {
                for (int l = 0; l < j; ++l)
                {
                    res += freqVec[j][k];
                }
            }
        }

        return res;
    }
};
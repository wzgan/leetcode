//
// Created by 甘唯哲 on 2020/9/17.
//

//https://leetcode.com/problems/ugly-number-ii/

#include <vector>
#include <queue>

class Solution {
public:
    int nthUglyNumber(int n)
    {
        std::vector<int> res;
        res.push_back(1);
        int c2 = 0, c3 = 0, c5 = 0;
        while (res.size() < n)
        {
            res.push_back(std::min(res[c2]*2, std::min(res[c3]*3, res[c5]*5)));
            if (res[c2]*2 == res.back()) c2++;
            if (res[c3]*3 == res.back()) c3++;
            if (res[c5]*5 == res.back()) c5++;
        }
        return res.back();
    }

    int nthUglyNumber2(int n)
    {
        std::priority_queue<long, std::vector<long>, std::greater<long>> q;
        q.push(1);
        for (int i = 0; i < n-1; ++i)
        {
            long cur = q.top();
            while (!q.empty() && q.top() == cur)
            {
                q.pop();
            }
            q.push(cur*2);
            q.push(cur*3);
            q.push(cur*5);
        }
        return q.top();
    }
};
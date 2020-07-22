//
// Created by 甘唯哲 on 2020/7/22.
//

#include <vector>
#include <stack>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& M)
    {
        int n = M.size();
        int res = 0;
        std::vector<bool> isVisited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!isVisited[i])
            {
                std::stack<int> s;
                s.push(i);
                while (!s.empty())
                {
                    int cur = s.top();
                    s.pop();
                    isVisited[cur] = true;
                    for (int j = 0; j < n; ++j)
                    {
                        if (!isVisited[j] && M[cur][j] == 1)
                            s.push(j);
                    }
                }
                res += 1;
            }
        }
        return res;
    }
};
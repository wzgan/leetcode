//
// Created by 甘唯哲 on 2020/9/16.
//

//https://leetcode.com/problems/the-skyline-problem/

//https://nataliekung.gitbook.io/ladder_code/facebook/the-skyline-problempriority-queue

/*
 * 从左到右扫描，碰见left edge：将新building的height入队，如果max改变，则将该点放入result；
 * 碰见right edge：将该building的height出队，如果max改变，则将该点放入result
 * edge case：1 left edge重叠：先处理大height
 * 2 right edge重叠：先处理小height
 * 3 前一个building的right edge与后一个building的left edge重叠：先处理后一个building
 */

#include <vector>
#include <queue>
#include <set>

class Solution {
private:
    struct Edge
    {
        int x = 0;
        int h = 0;
        bool bStarted = true;
        Edge(int x, int h, bool bStarted): x(x), h(h), bStarted(bStarted){}
    };

    struct Comp
    {
        bool operator()(Edge e1, Edge e2)
        {
            if (e1.x == e2.x)
            {
                if (e1.bStarted && e2.bStarted)
                {
                    return e1.h < e2.h;
                }else if (!e1.bStarted && !e2.bStarted)
                {
                    return e1.h > e2.h;
                } else
                {
                    return e2.bStarted;
                }
            } else
            {
                return e1.x > e2.x;
            }
        }
    };

public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings)
    {
        std::priority_queue<Edge, std::vector<Edge>, Comp> q_edge;
        for(auto bd : buildings)
        {
            Edge e1(bd[0], bd[2], true);
            Edge e2(bd[1], bd[2], false);
            q_edge.push(e1);
            q_edge.push(e2);
        }

        std::multiset<int, std::greater<int>> s_height;
        std::vector<std::vector<int>> res;
        while (!q_edge.empty())
        {
            Edge e = q_edge.top();
            if (e.bStarted)
            {
                if (s_height.empty() || e.h > *s_height.begin())
                    res.push_back({e.x, e.h});
                s_height.insert(e.h);
                q_edge.pop();
            } else
            {
                int pre_top = *s_height.begin();
                auto iter = s_height.find(e.h);
                s_height.erase(iter);
                if (pre_top > *s_height.begin())
                    res.push_back({e.x, *s_height.begin()});
                q_edge.pop();
            }
        }

        return res;
    }
};
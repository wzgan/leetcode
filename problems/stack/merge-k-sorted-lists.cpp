//
// Created by 甘唯哲 on 2020/9/15.
//

//https://leetcode.com/problems/merge-k-sorted-lists/

#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct Comp
    {
        bool operator() (ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Comp> pq;
        for (ListNode* pNode: lists)
        {
            if (pNode)
                pq.push(pNode);
        }

        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (!pq.empty())
        {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next)
                pq.push(cur->next);
        }

        return head->next;
    }
};
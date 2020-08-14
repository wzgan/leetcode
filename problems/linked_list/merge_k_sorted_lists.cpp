//
// Created by 甘唯哲 on 2020/7/28.
//

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(std::vector<ListNode*>& lists, int start, int end)
    {
        if (start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* node1 = merge(lists, start, mid);
        ListNode* node2 = merge(lists, mid+1, end);

        ListNode* p1 = node1, *p2 = node2, *p0 = new ListNode, *p = p0;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            } else
            {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        if (p1 != nullptr)
        {
            p->next = p1;
            p = p->next;
        }
        if (p2 != nullptr)
        {
            p->next = p2;
            p = p->next;
        }
        return p0->next;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        if (lists.empty()) return nullptr;
        int start = 0, end = lists.size() - 1;
        return merge(lists, start, end);
    }
};
//
// Created by 甘唯哲 on 2020/7/30.
//

//https://leetcode.com/problems/linked-list-cycle-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head, *quick = head;
        while(slow && quick && quick->next)
        {
            slow = slow->next;
            quick = quick->next->next;

            if (slow == quick)
                break;
        }

        if (slow != quick)
            return nullptr;

        slow = head;
        while (slow != quick)
        {
            slow = slow->next;
            quick = quick->next;
        }
        return slow;
    }
};
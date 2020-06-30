//
// Created by 甘唯哲 on 2020/6/27.
//

// https://leetcode.com/problems/same-tree/description/

#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q) return true;
        if ((!p && q) || (p && !q)) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSameTree_2(TreeNode* p, TreeNode* q)
    {
        std::queue<TreeNode*> nodeQueue1;
        std::queue<TreeNode*> nodeQueue2;

        if (!p || !q)
        {
            if (!p && !q) return true;
            return false;
        }

        nodeQueue1.push(p);
        nodeQueue2.push(q);

        while (!nodeQueue1.empty() && !nodeQueue1.empty())
        {
            TreeNode* node1 = nodeQueue1.front();
            TreeNode* node2 = nodeQueue2.front();

            nodeQueue1.pop();
            nodeQueue2.pop();

            if (node1->val != node2->val) return false;

            if (!node1->left || !node2->left)
            {
                if (!(!node1->left && !node2->left)) return false;
            }
            else
            {
                nodeQueue1.push(node1->left);
                nodeQueue2.push(node2->left);
            }

            if (!node1->right || !node2->right)
            {
                if (!(!node1->right && !node2->right)) return false;
            }
            else
            {
                nodeQueue1.push(node1->right);
                nodeQueue2.push(node2->right);
            }
        }

        return true;
    }
};
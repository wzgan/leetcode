//
// Created by 甘唯哲 on 2020/7/2.
//

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

class Solution
{
public:
    bool isSymmetric(TreeNode* p, TreeNode* q)
    {
        if (!p || !q)
        {
            if (!p && !q) return true;
            else return false;
        }

        if (p->val != q->val) return false;

        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }

    bool isSymmetric_1(TreeNode* root)
    {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }

    //non-re2cursive
    bool isSymmetric_2(TreeNode* root)
    {
        if (!root) return true;

        std::queue<TreeNode*> nodeQueue1;
        std::queue<TreeNode*> nodeQueue2;
        nodeQueue1.push(root->left);
        nodeQueue2.push(root->right);
        while (!nodeQueue1.empty() && !nodeQueue2.empty())
        {
            TreeNode* node1 = nodeQueue1.front();
            TreeNode* node2 = nodeQueue2.front();
            nodeQueue1.pop();
            nodeQueue2.pop();
            if (!node1 || !node2)
            {
                if (!node1 && !node2) continue;
                else return false;
            }
            if (node1->val != node2->val) return false;
            nodeQueue1.push(node1->left);
            nodeQueue1.push(node1->right);
            nodeQueue2.push(node2->right);
            nodeQueue2.push(node2->left);
        }
        return true;
    }

    bool isSymmetric2_2(TreeNode* root) {
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            TreeNode* node1 = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* node2 = nodeQueue.front();
            nodeQueue.pop();
            if (!node1 || !node2)
            {
                if (!node1 && !node2) continue;
                else return false;
            }
            if (node1->val != node2->val) return false;
            nodeQueue.push(node1->left);
            nodeQueue.push(node2->right);
            nodeQueue.push(node1->right);
            nodeQueue.push(node2->left);
        }
        return true;
    }
};

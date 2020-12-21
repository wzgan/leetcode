//
// Created by g23811 on 2020/12/21.
//


//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>

class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;

        std::queue<TreeNode*> nodeque;
        nodeque.push(root);
        int depth = 1;
        while (!nodeque.empty())
        {
            int n = nodeque.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode* cur = nodeque.front();
                nodeque.pop();

                if (!cur->left && !cur->right)
                {
                    return depth;
                }

                if (cur->left) nodeque.push(cur->left);
                if (cur->right) nodeque.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};
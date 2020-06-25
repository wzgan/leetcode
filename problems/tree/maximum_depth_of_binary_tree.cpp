//
// Created by 甘唯哲 on 2020/6/21.
//

// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <stack>

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


class Solution
{
public:
    int maxDepth1(TreeNode* root)
    {
        if(!root) return 0;
        return std::max(maxDepth1(root->right), maxDepth1(root->left)) +1;
    }

    int maxDepth2(TreeNode* root)
    {
        return 1;
    }
};


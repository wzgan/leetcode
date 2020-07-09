//
// Created by 甘唯哲 on 2020/7/9.
//

// https://leetcode.com/problems/sum-of-left-leaves/

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
    //root是否为left-leaf交给上一层考虑
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum = 0;
        if (!root) return 0;
        if (root->left)
        {
            if (!root->left->left && !root->left->right)
                return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }


    //root在本层判断
    int helper(TreeNode* root, bool isLeft)
    {
        if (!root) return 0;

        if (!root->left && !root->right && isLeft)
        {
            return root->val;
        }

        return helper(root->left, true) + helper(root->right, false);
    }

    int sumOfLeftLeaves2(TreeNode* root)
    {
        return helper(root, false);
    }
};
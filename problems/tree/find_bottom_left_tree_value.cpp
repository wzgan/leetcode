//
// Created by 甘唯哲 on 2020/7/10.
//

//https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int maxDepth = -1, val = 0;
    void helper(TreeNode* root, int depth)
    {
        if (!root) return;

        if (!root->left && !root->right)
        {
            if (depth > maxDepth)
            {
                val = root->val;
                maxDepth = depth;
            }
            return;
        }

        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root)
    {
        helper(root, 0);
        return val;
    }
};
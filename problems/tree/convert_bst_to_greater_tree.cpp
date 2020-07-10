//
// Created by 甘唯哲 on 2020/7/10.
//

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
    int helper(TreeNode* root, int preVal)
    {
        if (!root) return 0;

        int rVal = helper(root->right, preVal);
        root->val += rVal;
        return helper(root->left, root->val);
    }

    TreeNode* convertBST(TreeNode* root)
    {
        helper(root, 0);
        return root;
    }


    int preVal = 0;
    void helper2(TreeNode* root)
    {
        if (!root) return;

        helper2(root->right);
        root->val += preVal;
        preVal = root->val;
        helper2(root->left);
    }
};
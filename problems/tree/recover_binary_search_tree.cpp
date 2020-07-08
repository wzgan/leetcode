//
// Created by 甘唯哲 on 2020/7/8.
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
    TreeNode* w1, *w2, *pre;
    void helper(TreeNode* root)
    {
        if (!root) return;

        helper(root->left);
        if (pre && root->val < pre->val)
        {
            if (!w1)
            {
                w1 = pre;
                w2 = root;
            } else
            {
                w2 = root;
            }
        }
        pre = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root)
    {
        helper(root);
        if (w1 && w2)
        {
            int temp = w1->val;
            w1->val = w2->val;
            w2->val = temp;
        }
    }
};
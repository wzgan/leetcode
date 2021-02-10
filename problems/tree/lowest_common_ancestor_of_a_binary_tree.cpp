//
// Created by 甘唯哲 on 2020/7/5.
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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return nullptr;

        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode* lRet = lowestCommonAncestor(root->left, p, q);
        TreeNode* rRet = lowestCommonAncestor(root->right, p, q);

        if (rRet && lRet)
            return root;
        else
            return rRet ? rRet : lRet;
    }
};
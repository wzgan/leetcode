//
// Created by 甘唯哲 on 2020/7/9.
//

//https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (t1 && t2)
        {
            t1->val = t1->val + t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        } else if (t1 || t2)
        {
            return t1 ? t1 : t2;
        }else
        {
            return nullptr;
        }
    }
};
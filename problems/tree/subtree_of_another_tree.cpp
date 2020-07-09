//
// Created by 甘唯哲 on 2020/7/9.
//

//https://leetcode.com/problems/subtree-of-another-tree/

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
    bool isSameTree(TreeNode* s, TreeNode* t)
    {
        if (!s || !t)
        {
            if (!s && !t) return true;
            else return false;
        }

        if (s->val != t->val) return false;

        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if (!t) return true;
        if (!s) return false;

        if (s->val == t->val)
        {
            if (isSameTree(s, t)) return true;
        }

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
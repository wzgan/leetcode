//
// Created by g23811 on 2020/12/17.
//

//https://leetcode.com/problems/sum-root-to-leaf-numbers/

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

#include <vector>
#include <cmath>

class Solution {
public:
    int sum = 0;
    std::vector<int> track;

    void bt(TreeNode* root)
    {
        if (!root) return;
        if (!root->left && !root->right)
        {
            int sz = track.size();
            for (int i = 0; i < sz; ++i)
            {
                sum += track[sz-i-1] * std::pow(10, i);
            }
            return;
        }

        if (root->left)
        {
            track.push_back(root->left->val);
            bt(root->left);
            track.pop_back();
        }
        if (root->right)
        {
            track.push_back(root->right->val);
            bt(root->right);
            track.pop_back();
        }
    }

    int sumNumbers(TreeNode* root)
    {
        if (!root) return 0;
        track.push_back(root->val);
        bt(root);
        return sum;
    }
};
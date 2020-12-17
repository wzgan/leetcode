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
            int temp = 0;
            for (int i = 0; i < sz; ++i)
            {
                temp = temp*10 + track[i];
            }
            sum += temp;
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

    //not necessary to use vector to record every root-val, use num to record the former value in a certain path
    std::vector<int> res;
    void dfs(TreeNode* root, int num)
    {
        if (!root)
            return;

        num = num*10 + root->val;

        if (!root->left && !root->right)
        {
            res.push_back(num);
            return;
        }

        if (root->left) dfs(root->left, num);
        if (root->right) dfs(root->right, num);
    }

    int sumNumbers2(TreeNode* root)
    {
        int num = 0, sum = 0;
        dfs(root, num);
        for (int val : res)
        {
            sum += val;
        }
        return sum;
    }
};
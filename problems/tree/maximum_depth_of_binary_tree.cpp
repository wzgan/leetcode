//
// Created by 甘唯哲 on 2020/6/21.
//

// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <queue>

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
        if (!root) return 0;

        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int levelCnt = 0, levelFlag = 1;
        while (!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            levelFlag--;
            if (node->left) nodeQueue.push(node->left);
            if (node->right) nodeQueue.push(node->right);
            if (levelFlag == 0)
            {
                levelCnt++;
                levelFlag = nodeQueue.size();
            }
        }
        return levelCnt;
    }
};


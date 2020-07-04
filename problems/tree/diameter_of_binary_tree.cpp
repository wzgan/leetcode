//
// Created by 甘唯哲 on 2020/7/4.
//

// https://leetcode.com/problems/diameter-of-binary-tree/

#include <algorithm>
#include <stack>

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
    void helper(TreeNode* root, int& maxPath, int& depth)
    {
        if (!root)
        {
            maxPath = 0;
            depth = 0;
        }
        int lMaxPath, lDepth, rMaxPath, rDepth;
        helper(root->left, lMaxPath, lDepth);
        helper(root->right, rMaxPath, rDepth);
        maxPath = std::max(std::max(lMaxPath, rMaxPath), lDepth+rDepth);
        depth = std::max(lDepth, rDepth) + 1;
    }

    int diameterOfBinaryTree_1(TreeNode* root)
    {
        int maxPath, depth;
        helper(root, maxPath, depth);
        return maxPath;
    }


    //non-recursive
    struct nodeData
    {
        TreeNode* node;
        bool rChildVisited;
        int lDepth;
        int rDepth;
        int lMaxPath;
        int rMaxPath;
        nodeData(TreeNode* node): node(node), rChildVisited(false),
        lDepth(0), rDepth(0), lMaxPath(0), rMaxPath(0) {}
    };

    int diameterOfBinaryTree_2(TreeNode* root)
    {
        std::stack<nodeData> nodeStack;
        nodeData p(root);
        int pDepth;
        int pMaxPath;

        while (!nodeStack.empty() || p.node)
        {
            while (p.node)
            {
                nodeStack.push(p);
                p.node = p.node->left;
            }

            p = nodeStack.top();
            if (p.rChildVisited)
            {
                if (!p.node->right)
                {
                    p.rDepth = 0;
                    p.rMaxPath = 0;
                } else
                {
                    p.rDepth = pDepth;
                    p.rMaxPath = pMaxPath;
                }
                pDepth = std::max(p.lDepth, p.rDepth) + 1;
                pMaxPath = std::max(std::max(p.lMaxPath, p.rMaxPath), p.lDepth + p.rDepth);
                nodeStack.pop();
                p.node = nullptr;
            } else
            {
                if (!p.node->left)
                {
                    p.lDepth = 0;
                    p.lMaxPath = 0;
                } else
                {
                    p.lDepth = pDepth;
                    p.lMaxPath = pMaxPath;
                }
                p.rChildVisited = true;
                nodeStack.top() = p;
                p.node = p.node->right;
                p.rChildVisited = false;
            }
        }
        return pMaxPath;
    }
};
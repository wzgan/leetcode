//
// Created by 甘唯哲 on 2020/7/2.
//

#include <cstdlib>
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

class Solution
{
public:
    bool res = true;

    int maxDepth_1(TreeNode *root)
    {
        if (!root) return 0;

        int leftDepth = maxDepth_1(root->left);
        int rightDepth = maxDepth_1(root->right);
        if (std::abs(leftDepth - rightDepth) > 1) res = false;
        return std::max(leftDepth, rightDepth) + 1;
    }

    int maxDepth_2(TreeNode *root)
    {
        if (!root) return 0;
        if (!res)   return 0;

        int leftDepth = maxDepth_2(root->left);
        int rightDepth = maxDepth_2(root->right);
        if (std::abs(leftDepth - rightDepth) > 1) res = false;
        return std::max(leftDepth, rightDepth) + 1;
    }

    bool isBalanced_1(TreeNode *root)
    {
        maxDepth_2(root);
        return res;
    }

    //non-recursive
    struct nodeData
    {
        TreeNode* node;
        bool rChildVisited;
        int lDepth;
        int rDepth;
        nodeData(TreeNode* node): node(node), rChildVisited(false), lDepth(0), rDepth(0) {}
    };

    bool isBalanced_2(TreeNode* root)
    {
        std::stack<nodeData> nodeStack;
        nodeData p(root);
        int pDepth = 0;

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
                if (!p.node->right) p.rDepth = 0;
                else p.rDepth = pDepth;
                if (std::abs(p.rDepth - p.lDepth) > 1) return false;
                else pDepth = std::max(p.rDepth, p.lDepth)+1;
                nodeStack.pop();
                p.node = nullptr;
            } else
            {
                if (!p.node->left) p.lDepth = 0;
                else p.lDepth = pDepth;
                p.rChildVisited = true;
                nodeStack.top() = p;
                p.node = p.node->right;
                p.rChildVisited = false;
            }
        }

        return true;
    }

};
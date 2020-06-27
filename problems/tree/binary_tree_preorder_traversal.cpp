//
// Created by 甘唯哲 on 2020/6/26.
//

// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <vector>
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
    //recursive
    std::vector<int> preorderTraversal1(TreeNode* root) {
        std::vector<int> resVec;
        if (!root) return resVec;
        resVec.push_back(root->val);
        if(root->left)
        {
            std::vector<int> leftVec = preorderTraversal1(root->left);
            resVec.insert(resVec.end(), leftVec.begin(), leftVec.end());
        }
        if(root->right)
        {
            std::vector<int> rightVec = preorderTraversal1(root->right);
            resVec.insert(resVec.end(), rightVec.begin(), rightVec.end());
        }
        return resVec;
    }

    //another recursive
    void preorder(TreeNode* root, std::vector<int>& resVec)
    {
        if (!root) return;
        resVec.push_back(root->val);
        if (root->left) preorder(root->left, resVec);
        if (root->right) preorder(root->right, resVec);
    }
    std::vector<int> preorderTraversal1_1(TreeNode* root)
    {
        std::vector<int> resVec;
        preorder(root, resVec);
        return resVec;
    }

    //dfs with stack
    std::vector<int> preorderTraversal2(TreeNode* root)
    {
        std::vector<int> resVec;
        if (!root) return resVec;

        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            resVec.push_back(node->val);
            if (node->right) nodeStack.push(node->right);
            if (node->left) nodeStack.push(node->left);
        }
        return resVec;
    }

    //non-recursive
    std::vector<int> preorderTraversal2_2(TreeNode* root)
    {
        std::vector<int> resVec;
        std::stack<TreeNode*> nodeStack;
        TreeNode* p = root;
        while (!nodeStack.empty() || p)
        {
            while (p)
            {
                resVec.push_back(p->val);
                nodeStack.push(p);
                p = p->left;
            }
            p = nodeStack.top()->right;
            nodeStack.pop();
        }
        return resVec;
    }
};
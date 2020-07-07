//
// Created by 甘唯哲 on 2020/7/8.
//
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(std::vector<int>& preorder,
                        std::unordered_map<int, int>& inorderHash,
                        int preorder_rootIndex,
                        int inorder_beginIndex,
                        int inorder_endIndex)
    {
        if (inorder_beginIndex > inorder_endIndex) return nullptr;

        TreeNode* root = new TreeNode(preorder[preorder_rootIndex]);
        int inorder_rootIndex = inorderHash[root->val];
        root->left = buildTree(preorder,
                               inorderHash,
                               preorder_rootIndex+1,
                               inorder_beginIndex,
                               inorder_rootIndex-1);
        root->right = buildTree(preorder,
                                inorderHash,
                                inorder_rootIndex - inorder_beginIndex + preorder_rootIndex + 1,
                                inorder_rootIndex + 1,
                                inorder_endIndex);
        return root;
    }

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        if (preorder.empty() && inorder.empty()) return nullptr;

        std::unordered_map<int, int> inorderHash;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderHash[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder, inorderHash, 0, 0, inorder.size()-1);
        return root;
    }
};
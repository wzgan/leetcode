//
// Created by 甘唯哲 on 2020/6/22.
//
#include <vector>
#include <stack>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBinaryTree(const std::vector<int>& nodeVec, int rootIndex)
{
    TreeNode* root;
    if(rootIndex < 1 || rootIndex >= nodeVec.size() || nodeVec[rootIndex] == 0)
    {
        root = nullptr;
        return root;
    }

    int val = nodeVec[rootIndex];
    root = new TreeNode(val);
    root->left = createBinaryTree(nodeVec, 2*rootIndex);
    root->right = createBinaryTree(nodeVec, 2*rootIndex+1);
    return root;
}

class BinaryTree
{
public:
    TreeNode* root;

public:
    BinaryTree(std::vector<int>& nodeVec)
    {
        root = createBinaryTree(nodeVec, 1);
    }
};

//DFS in BT with Recursive
void dfsTraversal(TreeNode* root, std::vector<int>& resVec)
{
    resVec.clear();
    if (!root) return;

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
}

void bfsTraversal(TreeNode* root, std::vector<int>& resVec)
{
    resVec.clear();
    if (!root) return;

    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        resVec.push_back(node->val);
        if (node->left) nodeQueue.push(node->left);
        if (node->right) nodeQueue.push(node->right);
    }
}
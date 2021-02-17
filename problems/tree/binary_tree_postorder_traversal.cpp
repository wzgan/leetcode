//
// Created by 甘唯哲 on 2020/6/26.
//

#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void postorder(TreeNode* root, std::vector<int>& resVec)
    {
        if (!root) return;
        if (root->left) postorder(root->left, resVec);
        if (root->right) postorder(root->right, resVec);
        resVec.push_back(root->val);
    }

    std::vector<int> postorderTraversal_1(TreeNode* root)
    {
        std::vector<int> resVec;
        postorder(root, resVec);
        return resVec;
    }

    std::vector<int> postorderTraversal_2(TreeNode* root)
    {
        std::vector<int> resVec;
        std::stack<TreeNode*> nodeStack;
        std::stack<bool> flagStack;
        TreeNode* p = root;
        bool bVisited = false;

        while (!nodeStack.empty() || p)
        {
            while (p)
            {
                nodeStack.push(p);
                flagStack.push(false);
                p = p->left;
            }
            //回溯
            p = nodeStack.top();
            bVisited = flagStack.top();
            if (bVisited) //已访问过右子树
            {
                resVec.push_back(p->val);
                nodeStack.pop();
                flagStack.pop();
                p = nullptr; //继续回溯
            }
            else //访问右子树，root暂时不出栈
            {
                flagStack.top() = true;
                p = p->right;
            }
        }
        return resVec;
    }

    struct NewNode
    {
        TreeNode* node;
        bool bVisited;

        NewNode(TreeNode* node) : node(node), bVisited(false){}
    };
    std::vector<int> postorderTraversal_3(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<NewNode> nodeStack;
        nodeStack.push(NewNode(root));

        while (!nodeStack.empty())
        {
            NewNode& n_node = nodeStack.top();
            if (!n_node.node)
            {
                nodeStack.pop();
            }
            else if (!n_node.bVisited)
            {
                nodeStack.push(n_node.node->right);
                nodeStack.push(n_node.node->left);
                n_node.bVisited = true;
            }
            else
            {
                res.push_back(n_node.node->val);
                nodeStack.pop();
            }
        }
        return res;
    }
};
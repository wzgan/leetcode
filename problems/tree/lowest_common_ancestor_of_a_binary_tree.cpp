//
// Created by 甘唯哲 on 2020/7/5.
//

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

#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root->val == p->val || root->val == q->val)
            return root;

        TreeNode* lRet = lowestCommonAncestor(root->left, p, q);
        TreeNode* rRet = lowestCommonAncestor(root->right, p, q);

        if (rRet && lRet)
            return root;
        else
            return rRet ? rRet : lRet;
    }

    //bfs
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::queue<TreeNode*> nodeQue;
        std::unordered_map<TreeNode*, TreeNode*> parentsMap;

        nodeQue.push(root);
        parentsMap.insert(std::make_pair(root, nullptr));
        while (!parentsMap.count(p) || !parentsMap.count(q))
        {
            TreeNode* curNode = nodeQue.front();
            nodeQue.pop();

            if (curNode->left)
            {
                nodeQue.push(curNode->left);
                parentsMap.insert(std::make_pair(curNode->left, curNode));
            }

            if (curNode->right)
            {
                nodeQue.push(curNode->right);
                parentsMap.insert(std::make_pair(curNode->right, curNode));
            }
        }

        std::unordered_set<TreeNode*> ancestors;
        while (p)
        {
            ancestors.insert(p);
            p = parentsMap[p];
        }
        while (!ancestors.count(q))
            q = parentsMap[q];
        return q;
    }

    //dfs
    struct NewNode
    {
        TreeNode* node;
        bool bVisited;
        TreeNode* lRes;
        TreeNode* rRes;
        NewNode* parent;

        NewNode(TreeNode* node) : node(node), bVisited(false), lRes(nullptr), rRes(nullptr), parent(nullptr) {}
    };
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::stack<NewNode> nodeStack;
        nodeStack.push(NewNode(root));

        while (!nodeStack.empty())
        {
            NewNode n_node = nodeStack.top();

            if (!n_node.node || n_node.node == p || n_node.node == q)
            {

            }
            if (!n_node.bVisited)
            {
                nodeStack.push(NewNode(root->right));
                nodeStack.push(root->left);
            } else if ()


        }
    }
};
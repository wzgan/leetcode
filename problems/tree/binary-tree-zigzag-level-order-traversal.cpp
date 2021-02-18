//
// Created by g23811 on 2021/2/18.
//

//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
#include <queue>
#include <deque>

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        if (!root)
            return res;
        std::queue<TreeNode*> nodeQue;
        nodeQue.push(root);
        bool bReverse = false;

        while (!nodeQue.empty())
        {
            int levelNum = nodeQue.size();
            std::vector<int> levelVec(levelNum);

            for (int i = 0; i < levelNum; ++i)
            {
                TreeNode* front = nodeQue.front();
                nodeQue.pop();
                if (bReverse)
                    levelVec[levelNum-1-i] = front->val;
                else
                    levelVec[i] = front->val;
                if (front->left) nodeQue.push(front->left);
                if (front->right) nodeQue.push(front->right);
            }

            bReverse = !bReverse;
            res.push_back(levelVec);
        }
        return res;
    }

    std::vector<std::vector<int>> zigzagLevelOrder2(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        if (!root)
            return res;
        std::deque<TreeNode*> nodeQue;
        nodeQue.push_back(root);
        bool bReverse = false;

        while (!nodeQue.empty())
        {
            int levelNum = nodeQue.size();
            std::vector<int> levelVec(levelNum);

            for (int i = 0; i < levelNum; ++i)
            {
                if (!bReverse)
                {
                    TreeNode* top = nodeQue.front();
                    nodeQue.pop_front();
                    levelVec[i] = top->val;
                    if (top->left) nodeQue.push_back(top->left);
                    if (top->right) nodeQue.push_back(top->right);
                }
                else
                {
                    TreeNode* top = nodeQue.back();
                    nodeQue.pop_back();
                    levelVec[i] = top->val;
                    if (top->right) nodeQue.push_front(top->right);
                    if (top->left) nodeQue.push_front(top->left);
                }
            }
            bReverse = !bReverse;
            res.push_back(levelVec);
        }
        return res;
    }
};
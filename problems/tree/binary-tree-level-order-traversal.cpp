//
// Created by g23811 on 2021/2/18.
//
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
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        if(!root) return res;
        std::queue<TreeNode*> nodeQue;
        nodeQue.push(root);
        std::vector<int> level;
        int levelNum = 1;
        while(!nodeQue.empty())
        {
            TreeNode* front = nodeQue.front();
            nodeQue.pop();
            level.push_back(front->val);
            if(front->left) nodeQue.push(front->left);
            if(front->right) nodeQue.push(front->right);

            if(level.size() == levelNum)
            {
                levelNum = nodeQue.size();
                res.push_back(level);
                level.clear();
            }
        }
        return res;
    }
};
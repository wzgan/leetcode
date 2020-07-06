//
// Created by 甘唯哲 on 2020/7/6.
//
#include <vector>
#include <unordered_set>

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
    void delNodes(TreeNode* root, std::unordered_set<int>& dict, std::vector<TreeNode*>& res)
    {
        if (!root) return;
        TreeNode* lChild = root->left;
        TreeNode* rChild = root->right;
        bool ltoDel = lChild ? dict.count(lChild->val) : true;
        bool rtoDel = rChild ? dict.count(rChild->val) : true;

        if (dict.count(root->val))
        {
            if (!ltoDel) res.push_back(lChild);
            if (!rtoDel) res.push_back(rChild);
        } else
        {
            if (ltoDel) root->left = nullptr;
            if (rtoDel) root->right = nullptr;
        }
        //上下两层中对lChild和rChild重复判断，可只判断root并将判断结果作为返回值
        delNodes(lChild, dict, res);
        delNodes(rChild, dict, res);
    }

    bool delNotes_2(TreeNode* root, std::unordered_set<int>& dict, std::vector<TreeNode*>& res)
    {
        if (!root) return false;

        bool isDelLeft = delNotes_2(root->left, dict, res);
        bool isDelRight = delNotes_2(root->right, dict, res);

        //如果要删除子节点，则将root的子节点指针置空
        if (isDelLeft) root->left = nullptr;
        if (isDelRight) root->right = nullptr;

        //如果root不删除，则直接返回
        if (!dict.count(root->val)) return false;

        //否则将root现存的子节点加入res
        if (root->left) res.push_back(root->left);
        if (root->right) res.push_back(root->right);

        return true;
    }

    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete)
    {
        std::unordered_set<int> dict(to_delete.begin(), to_delete.end());
        std::vector<TreeNode*> res;
//        if (!root) return res;
//        if (!dict.count(root->val)) res.push_back(root);
//        delNodes(root, dict, res);
//        return res;
        if (!delNotes_2(root, dict, res))
        {
            res.push_back(root);
        }
        return res;
    }

};
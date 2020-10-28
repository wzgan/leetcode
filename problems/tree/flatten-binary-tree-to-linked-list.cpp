//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

//Definition for a binary tree node.
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
    void flatten(TreeNode* root) 
    {
        if (!root)
        {
        	return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        flatten(left);
        flatten(right);

        root->left = nullptr;
        root->right = left;

        if (!left)
        {
        	root->right = right;
        }
        else
        {
        	while(left->right != nullptr)
        	{
        		left = left->right;
        	}
        	left->right = right;
        }

    }

    TreeNode* prev = nullptr;
    void flatten2(TreeNode* root) 
    {
        if (!root)
        {
        	return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        prev = root;
        flatten(left);
        TreeNode* leftTail = prev;
        flatten(right);

        root->left = nullptr;
        root->right = left;
        leftTail -> right = right; 
    }

    void flatten3(TreeNode* root)
};
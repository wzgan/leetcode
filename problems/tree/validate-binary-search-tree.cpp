//https://leetcode.com/problems/validate-binary-search-tree/

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
	bool res;

	int helper(TreeNode* root, bool bLeft)
	{
		if (!root)
		{
			return bLeft? INT_MIN: INT_MAX;
		}

		int lmax = helper(root->left, true);
		int rmin = helper(root->right, false);

		if (lmax > root->val && rmin < root->val)
		{
			res = false;
		}

		return bLeft? 
	}

    bool isValidBST(TreeNode* root)
    {
        res = true;
        helper(root, false);
        return res;
    }
};
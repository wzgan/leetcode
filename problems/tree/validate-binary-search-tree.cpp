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

	void helper(TreeNode* root, int& min, int& max)
	{
		if (!root || !res)
		{
			return;
		}

		int lmin, lmax, rmin, rmax;
		helper(root->left, lmin, lmax);
		helper(root->right, rmin, rmax);

		min = root->val; 
		max = root->val;

		if (!root->left && root->right)
		{
			if (rmin <= root->val)
			{
				res = false;
				return;
			}
			
			max = rmax;
		}
		else if (root->left && !root->right)
		{
			if (lmax >= root->val)
			{
				res = false;
				return;
			}

			min = lmin;
		}
		else if (root->left && root->right)
		{
			if (lmax >= root->val || rmin <= root->val)
			{
				res = false;
				return;
			}

			min = lmin;
			max = rmax;
		}

		return;
	}

    bool isValidBST(TreeNode* root)
    {
        res = true;
        int min, max;
        helper(root, min, max);
        return res;
    }
};
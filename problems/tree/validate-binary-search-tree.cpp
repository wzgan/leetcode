// https://leetcode.com/problems/validate-binary-search-tree/

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
	bool helper(TreeNode* root, long& min, long& max)
	{
		if (!res || !root)
		{
			min = LONG_MIN;
			max = LONG_MAX;
			return;
		}

		int lmin, lmax;
		helper(root->left, lmin, lmax);
		if (root->val <= lmax)
		{
			return false;
		}

		int rmin, rmax;
		helper(root->right, rmin, rmax);
		if (root->val >= rmin)
		{
			return false;
		}

		min = std::min(lmin, root->val);
		max = std::man(rmax, root->val);
	}

    bool isValidBST(TreeNode* root)
    {
        long min, max;
        return helper(root, min, max);
    }


    bool validate(TreeNode*root, TreeNode* &prev)
    {
    	if (!root)
    	{
    		return true;
    	}

    	if(!validate(root->left, prev) || (prev && prev->val >= root->val)) return false;

    	prev = root;

 		return validate(root->right, prev);
    }

    bool isValidBST2(TreeNode* root)
    {
    	TreeNode* prev = nullptr;
    	return validate(root, prev);
    }
};
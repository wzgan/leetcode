//https://leetcode.com/problems/unique-binary-search-trees-ii/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include <vector>

class Solution {
public:
	std::vector<TreeNode*> helper(int start, int end)
	{
		std::vector<TreeNode*> res;
		if (start > end)
		{
			res.push_back(nullptr);
		}

		for (int i = start; i <= end; ++i)
		{
			std::vector<TreeNode*> lTrees = helper(start, i-1);
			std::vector<TreeNode*> rTrees = helper(i+1, end);

			for (int j = 0; j < lTrees.size(); ++j)
			{
				for (int k = 0; k < rTrees.size(); ++k)
				{
					TreeNode* root = new TreeNode(i, lTrees[j], rTrees[k]);
					res.push_back(root);
				}
			}
		}

		return res;
	}

    std::vector<TreeNode*> generateTrees(int n) 
    {
        return helper(1, n);
    }
};
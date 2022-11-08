struct TreeNode {
		int val;
		int height;
		struct TreeNode *left;
		struct TreeNode *right;
		struct TreeNode *parent;
}

// we know height diff at most 1
// can be calculated using
1 + max(dfs(left), dfs(right));
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    stack<TreeNode*> st;
	st.push(A);
	TreeNode* curr = NULL;
	while (!st.empty())
	{
		TreeNode* root = st.top();
		st.pop();
		if(root->right!=NULL)
			st.push(root->right);
		if(root->left!=NULL)
			st.push(root->left);
		root->left = NULL;
		if(st.empty())
			root->right = NULL;
		else
			root->right = st.top();
	}
	return A;
}

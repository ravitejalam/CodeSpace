/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool find(TreeNode* root, int A){
	if(root==NULL)
		return false;
	if(root->val==A)
		return true;
	return find(root->left,A) || find(root->right,A);
}

int Solution::lca(TreeNode* A, int B, int C) {
    int ans = -1;
	TreeNode* root = A;
	if(find(root,B) && find(root,C))
		ans = root->val;
	while (root!=NULL)
	{
		if(find(root->left,B) && find(root->left,C)){
			root=root->left;
			ans = root->val;
		}
		else if(find(root->right,B) && find(root->right,C))
		{
			root = root->right;
			ans = root->val;
		}
		else
		{
			break;
		}
	}
	return ans;
}

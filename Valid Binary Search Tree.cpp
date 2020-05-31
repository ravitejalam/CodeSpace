/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isValid(TreeNode* root,int min,int max){
	if(root==NULL)
		return true;
	if(root->val<=max && root->val >=min)
		return (isValid(root->left,min,root->val-1) && isValid(root->right,root->val+1,max));
	else
		return false;
}

int Solution::isValidBST(TreeNode* A) {
	if(isValid(A,INT_MIN,INT_MAX))
		return 1;
	return 0;
}

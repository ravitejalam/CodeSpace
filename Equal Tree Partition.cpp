int sumOfTree(TreeNode* root){
	if(root==NULL)
		return 0;
	return root->val + sumOfTree(root->left) + sumOfTree(root->right);
}

int Solution::solve(TreeNode* A) {
    if(A==NULL)
        return 0;
	int reqSum = sumOfTree(A);
	if(reqSum&1){
		return 0;
	}
	else{
		reqSum /= 2;
	}
	TreeNode* root = A;
	stack<TreeNode*> st;
	st.push(A->right);
	st.push(A->left);
	while (!st.empty())
	{
		TreeNode* root = st.top();
		st.pop();
		if(root->right!=NULL)
			st.push(root->right);
		if (root->left!=NULL)
			st.push(root->left);
		if(sumOfTree(root) == reqSum)
			return 1;
	}
	return 0;
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void updateAns(TreeNode* A, int B, int C, int &sum){
	if(A==NULL)
		return;
	if(A->val<=C && B<=A->val){
		sum++;
		updateAns(A->left,B,C,sum);
		updateAns(A->right,B,C,sum);
	}
	else if(A->val<B)
		updateAns(A->right,B,C,sum);
	else
		updateAns(A->left,B,C,sum);
}

int Solution::solve(TreeNode* A, int B, int C) {
	int sum = 0;
	updateAns(A,B,C,sum);
	return sum;
}

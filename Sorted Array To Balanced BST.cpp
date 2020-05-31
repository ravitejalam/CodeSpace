/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *BBST(const vector<int> &A, int start, int end)
{
	if (start > end)
		return NULL;
	int mid = start + (end - start) / 2;
	TreeNode *tmp = new TreeNode(A[mid]);
	tmp->left = BBST(A,start,mid-1);
	tmp->right = BBST(A,mid+1,end);
	return tmp;
}

TreeNode *Solution::sortedArrayToBST(const vector<int> &A)
{
	return BBST(A, 0, A.size() - 1);
}

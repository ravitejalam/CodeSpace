/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = 0;

bool isValid(TreeNode* root,int min,int max){
	if(root==NULL)
		return true;
	if(root->val<=max && root->val >=min)
		return (isValid(root->left,min,root->val-1) && isValid(root->right,root->val+1,max));
	else
		return false;
}

int countNodes(TreeNode* root){
    queue<TreeNode*> q;
	q.push(root);
	int c = 0;
	while (!q.empty())
	{
		if(q.front()!=NULL){
			q.push(q.front()->left);
			q.push(q.front()->right);
			c++;
		}
		q.pop();
	}
	return c;
}

void traversal(TreeNode* root){
    if(root==NULL)
        return;
    if(isValid(root,INT_MIN,INT_MAX))
        ans = max(ans,countNodes(root));
    traversal(root->left);
    traversal(root->right);
}

int Solution::solve(TreeNode* A) {
    ans = 0;
    traversal(A);
    return ans;
}

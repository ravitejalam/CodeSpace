/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define M 1000000007

void inOrder(TreeNode *root, vector<int> &vec)
{
	if (root == NULL)
		return;
	inOrder(root->left, vec);
	vec.push_back(root->val);
	inOrder(root->right, vec);
}


int Solution::solve(TreeNode* A, TreeNode* B) {
    vector<int> AV, BV;
	inOrder(A, AV);
	inOrder(B, BV);
	int a = 0, b = 0;
	int ans = 0;
	while (a < AV.size() && b < BV.size())
	{
		if(AV[a]==BV[b]){
			ans = (ans+AV[a])%M;
			a++;
			b++;
		}
		else if(AV[a]<BV[b]){
			a++;
		}
		else{
			b++;
		}
	}
	return ans;
}
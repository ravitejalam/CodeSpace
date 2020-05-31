/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getDiameter(TreeNode* root,int &m){
    if (root==NULL)
        return -1;
    int lHeight = getDiameter(root->left,m)+1;
    int rHeight = getDiameter(root->right,m)+1;
    if (m<lHeight+rHeight+1)
        m = lHeight+rHeight+1;
    return max(lHeight,rHeight);
}

int Solution::solve(TreeNode* A) {
    int ans = 0;
    getDiameter(A,ans);
    return ans;
}

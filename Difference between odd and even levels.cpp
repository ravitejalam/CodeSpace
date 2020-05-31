/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preOrderTraversal(TreeNode* A,int level,int &ans){
    if(A){
        if(level&1)
            ans+=A->val;
        else
            ans-=A->val;
        preOrderTraversal(A->left,level+1,ans);
        preOrderTraversal(A->right,level+1,ans);
    }
}

int Solution::solve(TreeNode* A) {
    int ans=0;
    preOrderTraversal(A,1,ans);
    return ans;
}
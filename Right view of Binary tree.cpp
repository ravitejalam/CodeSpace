/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preOrderTraversal(TreeNode* A,int level,vector<int> &ans){
    if(A){
        while(level>=ans.size())
            ans.push_back(-1);
        ans[level]=A->val;
        preOrderTraversal(A->left,level+1,ans);
        preOrderTraversal(A->right,level+1,ans);
    }
}

vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    preOrderTraversal(A,0,ans);
    return ans;
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isSBT(TreeNode* root){
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    int leftSum = isSBT(root->left);
    int rightSum = isSBT(root->right);
    if(leftSum == -1 || rightSum == -1)
        return -1;
    if (leftSum + rightSum == root->val)
        return 2*(root->val);
    else
        return -1;    
}

int Solution::solve(TreeNode* A) {
    if(isSBT(A) == -1)
        return 0;
    return 1;
}

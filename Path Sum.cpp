/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool traverse(TreeNode *root, int e, int sum)
{
    if(root==NULL)
        return false;
    if (root->left == NULL && root->right == NULL){
        sum += root->val;
        return sum == e;
    }
    else
    {
        sum += root->val;
        if(traverse(root->left, e, sum))
            return true;
        if(traverse(root->right, e, sum))
            return true;
    }
    return false;
}

int Solution::hasPathSum(TreeNode *A, int B)
{
    if (traverse(A, B, 0))
        return 1;
    return 0;
}

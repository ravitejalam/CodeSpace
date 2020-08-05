/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int getMax(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = getMax(root->left, maxi);
    int right = getMax(root->right, maxi);
    maxi = max(maxi, root->val + max(0, left) + max(0, right));
    return root->val + max(max(0, left), max(0, right));
}

int Solution::maxPathSum(TreeNode* A) {
    int maxi = INT_MIN;
    getMax(A, maxi);
    return maxi;
}

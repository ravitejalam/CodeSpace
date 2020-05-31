/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* invert(TreeNode* root){
    if(root==NULL)
        return NULL;
    TreeNode* tmp = root->left;
    root->left = invert(root->right);
    root->right = invert(tmp);
    return root;
}

TreeNode* Solution::invertTree(TreeNode* A) {
    return invert(A);
}

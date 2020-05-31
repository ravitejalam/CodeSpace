/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool check(TreeNode* root,TreeNode* sroot){
    if(root==NULL && sroot == NULL)
        return true;
    else if((root!=NULL && sroot == NULL) || (root==NULL && sroot != NULL))
        return false;
    else if(!check(root->left,sroot->left) || !check(root->right,sroot->right))
        return false;
    else if(root->val != sroot->val)
        return false;
    return true;
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return check(A,B);
}

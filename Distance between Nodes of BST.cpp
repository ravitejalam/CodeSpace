/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findDepth(TreeNode* root, int e){
    if(root==NULL)
        return -1;
    if (root->val == e)
        return 0;
    if(root->val < e)
        return 1 + findDepth(root->right,e);
    else
        return 1 + findDepth(root->left,e);
}

int distance(TreeNode* root, int B, int C){
    if (root->val>B && root->val>C)
    {
        return distance(root->left,B,C);
    }
    else if(root->val<B && root->val<C)
    {
        return distance(root->right,B,C);
    }
    else{
        return findDepth(root,B) + findDepth(root,C);
    }    
}

int Solution::solve(TreeNode* A, int B, int C) {
    return distance(A,B,C);
}

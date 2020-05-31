/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int getHeight(TreeNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = getHeight(node->left);
        int rDepth = getHeight(node->right);
        if(lDepth == -1 || rDepth == -1)
            return -1;
        if(abs(lDepth-rDepth)>1)
            return -1;
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int Solution::isBalanced(TreeNode* A) {
    if(getHeight(A) == -1)
        return 0;
    return 1;
}

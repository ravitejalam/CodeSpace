/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

TreeNode *DLL(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    TreeNode *rightHead = DLL(root->right);
    TreeNode *leftHead = DLL(root->left);
    TreeNode *head = root;
    root->left = root;
    root->right = root;
    if (leftHead != NULL)
    {
        TreeNode *last = head->left;
        TreeNode *leftLast = leftHead->left;
        leftLast->right = head;
        head->left = leftLast;
        leftHead->left = last;
        last->right = leftHead;
        head = leftHead;
    }
    if (rightHead != NULL){
        TreeNode *last = head->left;
        TreeNode *rightLast = rightHead->left;
        last->right = rightHead;
        rightHead->left = last;
        rightLast->right = head;
        head->left = rightLast;
    }
    return head;
}

TreeNode *solve(TreeNode *A)
{
    return DLL(A);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int getDiameter(TreeNode *root, int &m)
    {
        if (root == NULL)
            return -1;
        int lHeight = getDiameter(root->left, m) + 1;
        int rHeight = getDiameter(root->right, m) + 1;
        if (m < lHeight + rHeight)
            m = lHeight + rHeight;
        return max(lHeight, rHeight);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        getDiameter(root, ans);
        return ans;
    }
};
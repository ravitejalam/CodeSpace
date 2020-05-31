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

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void LevelOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    int index = getHeight(root);
    for (int i = 0; i < 2*index; i++)
        ans.push_back(-1);
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, index));
    while (!q.empty())
    {
        pair<TreeNode *, int> tmp = q.front();
        q.pop();
        TreeNode* node = tmp.first;
        index = tmp.second;
        if(ans[index]==-1)
            ans[index]=node->val;
        if (node->left != NULL)
            q.push(make_pair(node->left, index - 1));
        if (node->right != NULL)
            q.push(make_pair(node->right, index + 1));
    }
}

vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    LevelOrder(A, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
        {
            ans.erase(ans.begin()+i);
            i--;
        }
    }
    return ans;
}

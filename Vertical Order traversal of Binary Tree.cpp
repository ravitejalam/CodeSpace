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

void LevelOrder(TreeNode *root, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;
    int index = getHeight(root);
    for (int i = 0; i < 2*index; i++)
        ans.push_back({});
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, index));
    while (!q.empty())
    {
        pair<TreeNode *, int> tmp = q.front();
        q.pop();
        TreeNode* node = tmp.first;
        index = tmp.second;
        ans[index].push_back(node->val);
        if (node->left != NULL)
            q.push(make_pair(node->left, index - 1));
        if (node->right != NULL)
            q.push(make_pair(node->right, index + 1));
    }
}

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A)
{
    vector<vector<int>> ans;
    int height = getHeight(A);
    LevelOrder(A, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].size() == 0)
        {
            ans.erase(ans.begin()+i);
            i--;
        }
    }
    return ans;
}

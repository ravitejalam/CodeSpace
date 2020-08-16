#include <bits/stdc++.h>

using namespace std;

// Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int, int> m;
TreeNode *t1;
TreeNode *t2;
int repeated_val;

void dfs(TreeNode *root)
{
    m[root->val]++;
    if (root->left)
        dfs(root->left);
    if (root->right)
        dfs(root->right);
}

void dfs2(TreeNode *root, TreeNode *par)
{
    if (root->val == repeated_val)
    {
        if (t1 == NULL)
        {
            t1 = par;
        }
        else
            t2 = par;
    }
    if (root->left)
        dfs2(root->left, root);
    if (root->right)
        dfs2(root->right, root);
}

TreeNode *Solution::solve(TreeNode *A)
{
    TreeNode *ans;
    ans = A;
    m.clear();
    t1 = NULL;
    t2 = NULL;
    dfs(A);

    for (auto x : m)
    {
        if (x.second == 2)
        {
            repeated_val = x.first;
        }
    }
    dfs2(A, NULL);
    if (t1->val > t2->val)
    {
        if (t1->left && t1->left->val == repeated_val)
            t1->left = NULL;
        else
            t1->right = NULL;
    }
    else
    {
        if (t2->left && t2->left->val == repeated_val)
            t2->left = NULL;
        else
            t2->right = NULL;
    }
    return ans;
}
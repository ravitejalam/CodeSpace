/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<int,int> m;

TreeNode* constructTree(vector<int> &PreOrder,vector<int> &InOrder,int InOrderStart,int InOrderEnd,int &index){
    if(InOrderStart>InOrderEnd)
        return NULL;
    int val = PreOrder[index];
    TreeNode* node = new TreeNode(val);
    index++;
    if(InOrderStart==InOrderEnd)
        return node;
    node->left = constructTree(PreOrder,InOrder,InOrderStart,m[val]-1,index);
    node->right = constructTree(PreOrder,InOrder,m[val]+1,InOrderEnd,index);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int start = 0;
    int end = B.size()-1;
    m.clear();
    int index = 0;
    for (int i = 0; i < B.size(); i++)
        m[B[i]]=i;
    return constructTree(A,B,start,end,index);
}

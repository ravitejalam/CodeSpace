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


TreeNode* constructTree(vector<int> &InOrder,vector<int> &PostOrder,int InOrderStart,int InOrderEnd,int &index){
    if(InOrderStart>InOrderEnd)
        return NULL;
    int val = PostOrder[index];
    TreeNode* node = new TreeNode(val);
    index--;
    if(InOrderStart==InOrderEnd)
        return node;
    node->right = constructTree(InOrder,PostOrder,m[val]+1,InOrderEnd,index);
    node->left = constructTree(InOrder,PostOrder,InOrderStart,m[val]-1,index);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int start = 0;
    int end = B.size()-1;
    m.clear();
    int index = end;
    for (int i = 0; i < A.size(); i++)
        m[A[i]]=i;
    return constructTree(A,B,start,end,index);
}

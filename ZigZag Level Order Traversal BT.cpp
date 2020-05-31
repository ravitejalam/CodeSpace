/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preOrderTraversal(TreeNode* A,int level,vector<vector<int>> &ans){
    if(A){
        while(level>=ans.size())
            ans.push_back({});
        ans[level].push_back(A->val);
        preOrderTraversal(A->left,level+1,ans);
        preOrderTraversal(A->right,level+1,ans);
    }
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    preOrderTraversal(A,0,ans);
    for(int i = 1; i<ans.size(); i+=2)
        reverse(ans[i].begin(),ans[i].end());
    return ans;
}

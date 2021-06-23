/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* curr = A;
    while (curr!=NULL || !st.empty())
    {
        if(curr!=NULL){
            st.push(curr);
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else
        {
            curr=st.top();
            st.pop();
            curr=curr->left;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

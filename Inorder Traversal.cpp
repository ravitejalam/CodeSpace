/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* curr = A;
    while (curr!=NULL || !st.empty())
    {
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            curr=st.top();
            ans.push_back(curr->val);
            st.pop();
            curr=curr->right;
        }
    }
    return ans;
}

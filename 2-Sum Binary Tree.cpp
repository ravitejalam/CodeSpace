/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> inorderTraversal(TreeNode* A) {
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

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> inOrder = inorderTraversal(A);
    vector<int> tmp = {};
    for (int i = 1; i < inOrder.size(); i++)
	{
		if(inOrder[i]<inOrder[i-1])
			tmp.push_back(i);
	}
	if(tmp.size()==2)
		return {inOrder[tmp[1]],inOrder[tmp[0]-1]};
	else if(tmp.size()==1)
		return {inOrder[tmp[0]],inOrder[tmp[0]-1]};
	else
		return {};
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> inorderTraversal(TreeNode* A) {
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

int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> inOrder = inorderTraversal(A);
    int start = 0;
    int end = inOrder.size() - 1;
    int sum;
    while(start<end){
        sum = inOrder[start] + inOrder[end];
        if(sum == B)
            return 1;
        else if(sum < B)
            start++;
        else
            end--;
    }
    return 0;
}

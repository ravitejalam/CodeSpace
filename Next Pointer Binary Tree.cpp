/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
void preOrderTraversal(TreeLinkNode* A,int level,vector<queue<TreeLinkNode*>> &ans){
    if(A){
        ans[level].push(A);
        preOrderTraversal(A->left,level+1,ans);
        preOrderTraversal(A->right,level+1,ans);
    }
}

int getHeight(TreeLinkNode *node)
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

void Solution::connect(TreeLinkNode* A) {
    vector<queue<TreeLinkNode*>> ans(getHeight(A));
    preOrderTraversal(A,0,ans);
    for(int i = 0; i< ans.size(); i++){
        while(!ans[i].empty()){
            TreeLinkNode* tmp = ans[i].front();
            ans[i].pop();
            if(ans[i].empty()){
                tmp->next = NULL;
            }
            else
                tmp->next = ans[i].front();
        }
    }
}

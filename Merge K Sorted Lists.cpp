struct MyComp{
    bool operator()(ListNode* a, ListNode* b)
    {
        if (a->val>b->val)
            return true;
        return false;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<ListNode*,vector<ListNode*>, MyComp> minHeap;
    ListNode *ans = NULL;
    ListNode *head = NULL;
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i])
            minHeap.push(A[i]);
    }
    while (!minHeap.empty())
    {
        ListNode* next = minHeap.top()->next;
        if(head==NULL){
            ans = minHeap.top();
            head = ans;
        }
        else
        {
            ans->next = new ListNode(minHeap.top()->val);
            ans = ans->next;
        }
        minHeap.pop();
        if(next)
            minHeap.push(next);
    }
    return head;   
}
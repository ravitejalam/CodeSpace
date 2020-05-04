/*
struct ListNode { 
    int val; 
    ListNode *next,*random; 
    ListNode(int x) { 
        val = x; 
        next = random = NULL; 
    } 
}; 
*/
ListNode* clonelist(ListNode *A) {
    ListNode* ansHead = NULL;
    ListNode* ansTmp = NULL;
    ListNode* tmp = A;
    while (tmp!=NULL)
    {
        if(ansHead==NULL){
            ansHead = new ListNode(tmp->val);
            ansHead->random = tmp->random;
            ansTmp = ansHead;
        }
        else{
            ansTmp->next = new ListNode(tmp->val);
            ansTmp=ansTmp->next;
            ansTmp->random = tmp->random;
        }
        tmp=tmp->next;
    }
    return ansHead;
}
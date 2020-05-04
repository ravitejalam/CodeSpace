/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int l = 0;
    ListNode *tmp = A;
    while (tmp != NULL)
    {
        l++;
        tmp = tmp->next;
    }
    if(B>=l){
        if(A!=NULL)
            A=A->next;
    }
    else{
        tmp = A;
        for (int i = 0; i < l-B-1; i++)
        {
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
    }
    return A;
}

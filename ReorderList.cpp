/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    int l = 0;
    ListNode *tmp = A;
    while (tmp != NULL)
    {
        l++;
        tmp = tmp->next;
    }
    int mid = (l + 1) / 2;
    tmp = A;
    for (int i = 0; i < mid - 1; i++)
        tmp = tmp->next;
    ListNode *first = A;
    ListNode *second = NULL;
    ListNode *tt = tmp->next;
    tmp->next = NULL;
    while (tt!=NULL)
    {
        if(second==NULL){
            second=tt;
            tt=tt->next;
            second->next=NULL;
        }
        else{
            ListNode* t = tt;
            tt=tt->next;
            t->next=second;
            second=t;
        }
    }
    while (second != NULL)
    {
        ListNode *t = first->next;
        first->next = second;
        second = second->next;
        first = first->next;
        first->next = t;
        first = first->next;
    }
    return A;
}

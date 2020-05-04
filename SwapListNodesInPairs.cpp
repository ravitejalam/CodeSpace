/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    int l = 0;
    ListNode *tmp = A;
    ListNode *prev = NULL;
    while (tmp != NULL)
    {
        l++;
        tmp = tmp->next;
    }
    tmp=A;
    for (int i = 1; i < l; i+=2)
    {
        ListNode *t = tmp->next;
        tmp->next = t->next;
        if(prev==NULL)
            A=t;
        else
            prev->next = t;
        t->next = tmp;
        prev = tmp;
        tmp = tmp->next;
    }
    return A;
}

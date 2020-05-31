/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *C = NULL, *tmp = NULL;
    while (A != NULL || B != NULL)
    {
        if (A == NULL)
        {
            if (tmp == NULL)
            {
                tmp = B;
                C=tmp;
            }
            else
            {
                tmp->next = B;
                tmp = tmp->next;
            }
            B = B->next;
            tmp->next = NULL;
        }
        else if (B == NULL)
        {
            if (tmp == NULL)
            {
                tmp = A;
                C=tmp;
            }
            else
            {
                tmp->next = A;
                tmp = tmp->next;
            }
            A = A->next;
            tmp->next = NULL;
        }
        else
        {
            if(B->val<A->val){
                if (tmp == NULL)
                {
                    tmp = B;
                    C=tmp;
                }
                else
                {
                    tmp->next = B;
                    tmp = tmp->next;
                }
                B = B->next;
                tmp->next = NULL;
            }
            else
            {
                if (tmp == NULL)
                {
                    tmp = A;
                    C=tmp;
                }
                else
                {
                    tmp->next = A;
                    tmp = tmp->next;
                }
                A = A->next;
                tmp->next = NULL;
            }
            
        }
    }
    return C;
}

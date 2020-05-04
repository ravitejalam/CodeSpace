/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C)
        return A;
    int l = 0;
    ListNode *tmp = A;
    ListNode *prev = NULL;
    while (tmp != NULL)
    {
        l++;
        tmp = tmp->next;
    }
    ListNode *R = NULL;
    ListNode *Rlast = NULL;
    tmp = A;
    for (int i = 0; i < l; i++)
    {
        if (i + 1 < B){
            prev = tmp;
            tmp = tmp->next;
        }
        else if (i + 1 <= C){
            if (R == NULL){
                R = new ListNode(tmp->val);
                Rlast = R;
            }
            else{
                ListNode* tmpB = new ListNode(tmp->val);
                tmpB->next = R;
                R = tmpB;
            }
            if (prev!=NULL)
                prev->next = tmp->next;
            tmp = tmp->next;
        }
        else
            break;
    }
    if (prev!=NULL)
        prev->next = R;
    else
        A = R;
    Rlast->next = tmp;
    return A;
}

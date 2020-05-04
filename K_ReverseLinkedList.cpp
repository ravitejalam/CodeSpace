/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    int l = 0;
    ListNode *tmp = A;
    ListNode *prev = NULL;
    while (tmp != NULL)
    {
        l++;
        tmp = tmp->next;
    }
    tmp = A;
    for (int i = 0; i < l; i+=B)
    {
        ListNode* head = NULL;
        for (int j = 0; j < B; j++)
        {
            ListNode* t = head;
            if(head==NULL)
                head=tmp;
            else{
                head=tmp;
            }
            tmp = tmp->next;
            head->next=t;
        }
        if(prev==NULL)
            A=head;
        else{
            prev->next = head;
        }
        while (head->next!=NULL)
        {
            head=head->next;
        }
        prev=head;
    }
    return A;
}

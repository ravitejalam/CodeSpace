/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* Atmp = NULL;
    ListNode* Btmp = NULL;
    int lenA = 0,lenB = 0;
    Atmp = A;
    while (Atmp!=NULL)
    {
        lenA++;
        Atmp=Atmp->next;
    }
    Btmp = B;
    while (Btmp!=NULL)
    {
        lenB++;
        Btmp=Btmp->next;
    }
    Atmp=A;
    Btmp=B;
    if (lenA<lenB)
    {
        for (int i = 0; i < lenB-lenA; i++)
        {
            Btmp=Btmp->next;
        }
    }
    else
    {
        for (int i = 0; i < lenA-lenB; i++)
        {
            Atmp=Atmp->next;
        }
    }
    while (Atmp!=NULL && Btmp!=NULL)
    {
        if(Atmp==Btmp)
            return Atmp;
        else
        {
            Atmp=Atmp->next;
            Btmp=Btmp->next;
        }
    }
    return NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int countCommon(ListNode *a, ListNode *b) 
{ 
    int count = 0;
    for (; a && b; a = a->next, b = b->next)
        if (a->val == b->val) 
            ++count; 
        else
            break; 
    return count; 
}

int Solution::solve(ListNode* A) {
    int result = 0; 
    ListNode *prev = NULL, *curr = A;
    while (curr) 
    {
        ListNode *next = curr->next; 
        curr->next = prev;
        result = max(result, 
                     2*countCommon(prev, next)+1);
        result = max(result, 
                     2*countCommon(curr, next));
        prev = curr; 
        curr = next; 
    } 
    return result; 
}
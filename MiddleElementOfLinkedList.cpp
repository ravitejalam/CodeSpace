/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A) {
    int l = 0;
    ListNode *tmp = A;
    while (tmp != NULL)
    {
        l++;
        tmp = tmp->next;
    }
    tmp = A;
    for (int i = 0; i < l / 2; i++)
    {
        tmp = tmp->next;
    }
    return tmp->val;
}

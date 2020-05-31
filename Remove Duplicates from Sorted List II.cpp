/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *tmp = A;
    unordered_map<int, int> count;
    while (tmp != NULL)
    {
        count[tmp->val]++;
        tmp = tmp->next;
    }
    ListNode *ans = NULL, *ansTmp = NULL;
    tmp = A;
    while (tmp != NULL)
    {
        if (count[tmp->val] == 1)
        {
            if (ansTmp == NULL)
            {
                ansTmp = tmp;
                ans = ansTmp;
            }
            else
            {
                ansTmp->next = tmp;
                ansTmp = ansTmp->next;
            }
            tmp = tmp->next;
            ansTmp->next = NULL;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return ans;
}

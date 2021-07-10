/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *endLookOut = head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        for (int i = 0; i < n; i++)
        {
            endLookOut = endLookOut->next;
        }
        // case for head removal
        if (endLookOut == NULL)
        {
            head = head->next;
            return head;
        }
        // sliding window
        while (endLookOut)
        {
            endLookOut = endLookOut->next;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};
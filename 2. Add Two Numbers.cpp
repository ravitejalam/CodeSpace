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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val == 0 && !l1->next) return l2;
        if(l2->val == 0 && !l2->next) return l1;
        int carry  = 0;
        ListNode* ans = NULL;
        ListNode* tmp;
        while(l1 && l2){
            int x = l1->val;
            int y = l2->val;
            if(ans){
                tmp->next = new ListNode((x+y+carry)%10);
                tmp = tmp->next;
            }
            else{
                ans = new ListNode((x+y+carry)%10);
                tmp = ans;
            }
            carry = (x+y+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            while(l1){
                int x = l1->val;
                if(ans){
                    tmp->next = new ListNode((x+carry)%10);
                    tmp = tmp->next;
                }
                else{
                    ans = new ListNode((x+carry)%10);
                    tmp = ans;
                }
                carry = (x+carry)/10;
                l1 = l1->next;
            }
        }
        else{
            while(l2){
                int x = l2->val;
                if(ans){
                    tmp->next = new ListNode((x+carry)%10);
                    tmp = tmp->next;
                }
                else{
                    ans = new ListNode(x+carry);
                    tmp = ans;
                }
                carry = (x+carry)/10;
                l2 = l2->next;
            }
        }
        if(carry)
            tmp->next = new ListNode(carry);
        return ans;
    }
};
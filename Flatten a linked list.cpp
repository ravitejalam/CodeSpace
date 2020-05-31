ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
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
                tmp->down = B;
                tmp = tmp->down;
            }
            B = B->down;
            tmp->down = NULL;
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
                tmp->down = A;
                tmp = tmp->down;
            }
            A = A->down;
            tmp->down = NULL;
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
                    tmp->down = B;
                    tmp = tmp->down;
                }
                B = B->down;
                tmp->down = NULL;
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
                    tmp->down = A;
                    tmp = tmp->down;
                }
                A = A->down;
                tmp->down = NULL;
            }
            
        }
    }
    return C;
}

ListNode *flatten(ListNode *root)
{
    ListNode *down = NULL, *ans = NULL, *tmp = root;
    while (tmp != NULL)
    {
		down = tmp;
        tmp = tmp->right;
        ans = mergeTwoLists(ans, down);
    }
    return ans;
}
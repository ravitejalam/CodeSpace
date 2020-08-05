int Solution::longestValidParentheses(string A)
{
    stack<int> st;
    st.push(-1);
    int res = 0;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (st.empty())
                st.push(i);
            else
                res = max(res, i - st.top());
        }
    }
    return res;
}
